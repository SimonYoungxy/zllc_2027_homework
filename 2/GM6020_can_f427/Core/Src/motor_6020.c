#include "motor_6020.h"
#include "can.h"
#include <string.h>

/*hcan已经在can.c中定义*/
extern CAN_HandleTypeDef hcan1;

volatile gm6020_t gm6020[GM6020_NUM];
volatile uint32_t g_can_err=0U;

/*大端解包(有符号，无符号)*/
uint16_t be_u16(const uint8_t *data)
{
    return (uint16_t)((uint16_t)(data[0] << 8) | (uint16_t)(data[1]));
}

static int16_t be_s16(const uint8_t *data)
{
    return (int16_t)be_u16(data);
}

//滤波器配置
/* ===================== 滤波器配置 ===================== */
/* 目标：只接收 0x205 ~ 0x20B
 *   0x205 = 0010 0000 0101
 *   0x20B = 0010 0000 1011
 *   只有低 4 位不同 → 比较位 = 0x200，掩码 = 0x7F0
 *
 * 标准帧 ID 在32位滤波器里占 bit31:21，
 * 而FilterIdHigh是高 16 位，所以 ID 要左移 5 位。
 */
static  HAL_StatusTypeDef CAN_Filter_CONFIG(void)
{
    CAN_FilterTypeDef can_filter={0};

    can_filter.FilterBank = 0;                      //使用第0组滤波器
    can_filter.FilterMode = CAN_FILTERMODE_IDMASK;
    can_filter.FilterScale = CAN_FILTERSCALE_32BIT;
    can_filter.FilterIdHigh = (uint16_t)(0x200 << 5); //0x205是电机的CAN ID
    can_filter.FilterIdLow = 0U;
    can_filter.FilterMaskIdHigh = (uint16_t)(0x7F0 << 5); //0x7F0是掩码
    can_filter.FilterMaskIdLow = 0U;
    can_filter.FilterFIFOAssignment = CAN_RX_FIFO0;
    can_filter.FilterActivation = ENABLE;
    can_filter.SlaveStartFilterBank = 14;

    return HAL_CAN_ConfigFilter(&hcan1, &can_filter);
}


/*初始化*/
void motor_6020_init(void)
{
    /*CAN滤波器配置*/
    if(CAN_Filter_CONFIG() != HAL_OK)
    {
        Error_Handler();
    }
    /*启动CAN*/
    if(HAL_CAN_Start(&hcan1) != HAL_OK)
    {
        Error_Handler();
    }
    /*激活FIFO0消息挂起中断*/
    if(HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
    {
        Error_Handler();
    }

    memset((void*)gm6020, 0, sizeof(gm6020));
}

/*接收回调并进行校验*/
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan_ptr)
{
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];
    uint8_t idx;

    /*读取CAN数据*/
    if(hcan_ptr->Instance) return;
    /*检查ID范围*/
    /*必须用while，处理有可能来了新帧*/
    while(HAL_CAN_GetRxFifoFillLevel(hcan_ptr, CAN_RX_FIFO0) > 0)
    {
        if(HAL_CAN_GetRxMessage(hcan_ptr, CAN_RX_FIFO0, &rx_header, rx_data) != HAL_OK)
        {
            g_can_err++;
            break;
        }

        /*----进行校验----*/
        if(rx_header.IDE !=CAN_ID_STD)    continue; //只处理标准帧
        if(rx_header.RTR != CAN_RTR_DATA) continue; //只处理数据帧
        if(rx_header.DLC != 8U)           continue;   //数据长度必须为8
        if(rx_header.StdId < GM6020_ID_MIN || 
           rx_header.StdId > GM6020_ID_MAX) continue; //ID范围检查
        idx=(uint8_t)(rx_header.StdId - GM6020_ID_BASE);
        if (idx >= GM6020_NUM) continue; //索引范围检查
        {
            uint16_t ang = be_u16(&rx_data[0]);
            int16_t  spd = be_s16(&rx_data[2]);
            int16_t  cur = be_s16(&rx_data[4]);
            uint8_t tmp = rx_data[6];

            gm6020[idx].id = idx;
            gm6020[idx].angle = ang;
            gm6020[idx].speed_rpm =spd;
            gm6020[idx].torque_current = cur;
            gm6020[idx].temperature = tmp;
            gm6020[idx].last_update_time=HAL_GetTick();
            gm6020[idx].online = 1U; //标记在线
            gm6020[idx].rx_count++; //接收计数
        }
    }

}


/*-----掉线检测-----*/
void motor_6020_poll(void)
{
    uint32_t now=HAL_GetTick();
    for(uint8_t i=0;i<GM6020_NUM;i++)
}
