#### 统一培训

代码和文档都需要自己学习，自己写，不要使用ai，有不懂的内容最好学长学姐在的话直接问学长学姐，多和在实验室的同学交流问题，也可以问ai

用ai写代码的前提是自己有了一定的代码能力，这个代码你自己会写，对你来说是重复劳动的时候

以下内容的推荐作为参考，最好自己多看点资料

##### 1

**一天的时间， 11.23**

**这部分内容是前置的基础知识，加粗的必须了解学会，其他的你们后续学习应该也会慢慢学会**

学习uart dma的原理与使用，以及一些stm32的基础： i2c，spi的通信，通信过程

目标：**能自己讲出dma有什么用，stm32中怎么配置dma，中断从脉冲进来最终怎么到我们的预设函数，arm基本的寄存器**

对i2c，spi有基本的了解，比如有什么物理线序，有什么关键的参数需要配置，一次通信的完整流程：通信的起始帧，数据帧，结束帧，格式

**对于git，注册github账号，需要了解git有什么用，自己亲手创建一个仓库，上传一个代码（git commit），切换一次分支，拉取一次代码，后续可以自己了解冲突合并等**

**自己要配置好vscode + eide的开发环境，可以自己看一下vscode还有什么好用的插件配置一下**

推荐：

[【keysking的STM32教程】 第7集 深入讲解STM32中断_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1M24y1473t?spm_id_from=333.788.videopod.sections&vd_source=de144ef193dc3f4b419bd8828397d9db)

[【工作STM32】第10集 STM32串口DMA模式与收发不定长数据 | keysking的stm32教程_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1do4y1F7wt?spm_id_from=333.788.videopod.sections&vd_source=de144ef193dc3f4b419bd8828397d9db)

[【STM32】程序是如何控制寄存器的???_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1GJfBYDEiA?spm_id_from=333.788.videopod.sections&vd_source=de144ef193dc3f4b419bd8828397d9db)

[【STM32】串口数据拆包？黏包？循环缓冲区帮你搞定！_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1p75yzSEt9?spm_id_from=333.788.videopod.sections&vd_source=de144ef193dc3f4b419bd8828397d9db)

[Git 使用教程：最详细、最正宗手把手教学（万字长文）_git教程-CSDN博客](https://blog.csdn.net/qq_16027093/article/details/130503317)只用会基本的操作就好

[ARM汇编基础之内核寄存器详解_arm内核寄存器-CSDN博客](https://blog.csdn.net/u010632165/article/details/105983229)

[手把手教你配置，VSCode+EIDE开发STM32，超详细，超好用。_vscode eide-CSDN博客](https://blog.csdn.net/m0_74858601/article/details/139050698)

##### 2

**三天，11.24 - 11.26**

学习can通信的原理，能自己说出can的通信流程，物理线序，can通信的一整个过程有什么阶段，数据，不需要背下来，但要知道

了解一下fdcan和can的区别

验收：

1. 用实验室提供的6020电机，vscode 的开发环境，手写实现can的配置，电机返回数据的接收和处理，保存在一个结构体内；代码不可以使用ai，可以参考网上的博客复制部分代码，对于can的理解可以用ai辅助
2. 手写md文档，讲明白can的通信流程，关键配置参数是什么，不要使用ai
3. 将完整的工程上传到对应的git仓库，工程 + md文档

推荐：

​	[趋近于完美的通讯 CAN总线！4分钟看懂！_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV14k4y187e6/?spm_id_from=333.337.search-card.all.click&vd_source=de144ef193dc3f4b419bd8828397d9db)

​	[10分钟带你入门CAN总线！_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1e7c7zZE9V/?spm_id_from=333.337.search-card.all.click&vd_source=de144ef193dc3f4b419bd8828397d9db)

​	[CAN通信知识梳理及在Stm32上的应用（HAL库）-CSDN博客](https://blog.csdn.net/weixin_44793491/article/details/107298426)

##### 3

**三天的时间， 11.27 - 11.29**

手写pid的最简单实现 kp ki kd，只需要考虑最简单的kp ki kd的作用，以及电机的输出限幅，以6020的反馈一阶低通滤波，用滤波后的数据作为pid输入，分别做速度环，角度环的闭环控制，使用ozone进行在线调试pid参数，手写md文档讲述pid的原理，滤波的作用和原理

上传代码带git仓库

有时间的话可以自己了解一下卡尔曼滤波

推荐：

​	[Ozone使用_ozone调试步骤-CSDN博客](https://blog.csdn.net/2301_82079903/article/details/147670539)

​	[北京理工大学机器人队暑招2025：ozone调试_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1uVgyzUE8F/?spm_id_from=333.337.search-card.all.click&vd_source=de144ef193dc3f4b419bd8828397d9db)

​	[通俗易懂的 PID 控制算法讲解_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1et4y1i7Gm/?spm_id_from=333.337.search-card.all.click&vd_source=de144ef193dc3f4b419bd8828397d9db)

​	[超详细！一文搞定PID！嵌入式STM32-PID位置环和速度环_stm32 pid-CSDN博客](https://blog.csdn.net/qq_48361010/article/details/136061625)

​	[一阶低通滤波器在stm32中的简单应用_stm32低通滤波-CSDN博客 ](https://blog.csdn.net/qq_45186942/article/details/120139531) 不用看前边的公式，直接看代码，滤波的作用效果

​	[基于STM32的ADC采样及各式滤波实现（HAL库，含VOFA+教程）_数据采集滤波算法stm32-CSDN博客](https://blog.csdn.net/black_sneak/article/details/129629485)直接看滤波的代码部分和作用，这里讲的是别的滤波算法，了解一下有什么方法

​	

##### 4

**3天 11.30 -- 12.2 ** 

学习freertos基本api的调用，包括任务的创建，队列，栈堆，任务通知的使用，互斥锁的意义，使用；拉取我们提供的基础仓库（后续会说明），实现在战队的freertos框架下创建一个任务实现电机的闭环控制

写自己的学习文档和遇到的问题

上传代码和学习文档

[韦东山freeRTOS系列教程：入门文档教程+进阶视频教程(全部免费的freeRTOS系列教程、freeRTOS学习路线)-CSDN博客](https://blog.csdn.net/thisway_diy/article/details/121399484)  这个比较深入，现阶段我们要求是 会基本的API使用和基本概念

[【keysking】全网最好的FreeRTOS教程！_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1mhWqzFEzn/?spm_id_from=333.337.search-card.all.click&vd_source=de144ef193dc3f4b419bd8828397d9db) 优先看这个，快速学习一下目前发布的视频

快速学会需要掌握的知识：

可以借助ai快速了解概念和学习，代码自己写

1. rtos的任务怎么创建， rtos里任务的优先级含义， 
2. rtos任务栈是什么，为什么需要任务栈
3. 任务之间怎么进行通信 ---- 队列的使用，数据怎么保护 ---- 互斥锁，为什么需要锁



深入的可以了解一下任务是怎么切换的，PendSV中断的作用，锁的原理，任务的不同状态怎么管理，什么情况下会切换，Systick中断被怎么使用  等