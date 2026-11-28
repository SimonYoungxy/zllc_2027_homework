/*先搞清楚要写什么东西，结构体，函数声明，include*/
#ifndef __MOTOR_6020_H
#define __MOTOR_6020_H

#include "main.h"

/*gm6020反馈ID：前面的是C620电调占用的ID*/
#define GM6020_ID_BASE 0x204U
#define GM6020_ID_MIN  0x205U
#define GM6020_ID_MAX  0x20BU
#define GM6020_NUM     8U

typedef struct
{
    uint8_t id;             //电机ID,1~7
    uint8_t online;         //电机在线状态，0：不在线，1：在线
    uint16_t angle;        //电机角度
    int16_t speed_rpm;    //电机转速
    int16_t torque_current; //电机电流
    uint8_t temperature;   //电机温度
}gm6020_t;

extern volatile gm6020_t gm6020[GM6020_NUM];

void motor_6020_init(void);
void motor_6020_poll(void);
 
#endif