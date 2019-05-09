											   
#include <reg52.h>
//#include <intrins.h>
  /*====================================
 自定义类型名
====================================*/
typedef unsigned char INT8U;
typedef unsigned char uchar;

typedef unsigned int INT16U;
typedef unsigned int uint;
sbit IR  = P3^2;     //定义红外脉冲数据接口	外部中断O输入口


uchar IRtime; 		//检测红外高电平持续时间（脉宽）
uchar IRcord[4];    //此数组用于储存分离出来的4个字节的数据（用户码2个字节+键值码2个字节）
uchar IRdata[33];   //此数组用于储存红外的33位数据（第一位为引导码用户码16+键值码16）
bit IRpro_ok, IRok;  //第一个用于红外接收4个字节完毕。IRok用为检测脉宽完毕

////uchar code table[]={0xfe,0xfc,0xfd,0xf9,0xfb,0xf3,0xf7,0xf6};
////uchar code table1[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
//uchar code table[]={0xf1,0xf3,0xf2,0xf6,0xf4,0xfc,0xf8,0xf9};
//uchar code table1[]={0xf9,0xf8,0xfc,0xf4,0xf6,0xf2,0xf3,0xf1};
void delay_ms(uint x)
{
   uint i,j;
   for(i=x;i>0;i--)
     for(j=110;j>0;j--);
}

//初始化定时器0，外部中断0，串口
void init()
{
    TMOD|=0X02;//设置定时器0工作方式2,8位自动重装
	TL0=TH0=0;//初始化定时器0寄存器，定时器0溢出溢出时间为256个机器周期
	EA=1;	 //开启总中断
	ET0=1;//开启定时器0中断						
	TR0=1;//启动定时器0

	IT0=1;//设置外部中断0下降沿方式触发
	EX0=1;//开外部中断0中断

	TMOD |=0X20;//设置定时器1工作模式2,8位自动重装
	TL1=TH1=0Xfd;//比特率9600
	SM1=1;//设置串口工作模式1,10位异步收发
	TR1=1;//启动定时器1
}   
//定时器0中断，每中断溢出需要256*1.085us=277.76us
void time0() interrupt 1
{
     IRtime++;
}
//外部中断0存入33次此脉宽
void int0() interrupt 0
{
    static uchar i;//静态变量用于存入33次数据计数
	static bit startflag;//开始存储脉宽标志位，默认是0
	if(startflag)
	{
	    //判断引导码，如果是引导码则从起始码开始存储
		 if((IRtime<53)&&(IRtime>=32))
		      i=0;
		  IRdata[i]=IRtime;	//以T0溢出的次数来计算脉宽，把这个时间存在数组中
		  IRtime=0;	//计数清零
		  i++;		//计数脉宽存入次数
		  if(i==33)	  //脉宽次数等于33的时候代表已经存入33次
		  {
		      IRok=1;	//脉宽检查完成
			  i=0;		 //把脉宽计数清零
		  }	 
	}
	else
	{
		IRtime=0;// 计数清零
	    startflag=1;//开始处理标志位置1
	}	 
}
//把提取的33次脉宽安装NEC标准协议解码
void IRcordpro()
{
   uchar i,j,k;//i用于计数处理四个字节；j用于计数处理一个字节的8位数据；k用于计数处理33位脉宽
   k=1;//从第一位脉宽开始处理，丢掉起始码
   for(i=0;i<4;i++)
   {
      for(j=0;j<8;j++)
	  {
	      //如果脉宽大于数据0标准的1125us那么就判断为数据1
	      if(IRdata[k]>5)	 //判断高低电平
		      IRcord[i] |=0x80;	 //写1操作
		  if(j<7)				//只能右移7次，否则就把数据就移出去了
		      IRcord[i]>>=1;
	   	   k++; //处理下一次脉宽
	  }
   }
   IRpro_ok=1;
}
void main()
{
  uchar i;	//计数串口发送字节数
  uchar j=0;
  init();  //初始化
  while(1)
  {
     if(IRok)  //判断是否完成33次的脉宽提取
	 {
	    IRcordpro(); //根据
		IRok=0;		 //清零脉宽检查完成标志位等待下一次的脉宽检查
		if(IRpro_ok)  //判断解码是否完成
		{


		   for(i=0;i<4;i++)	//串口发送四个字节的数据
		   {

				IRcordpro(); //根据
                switch(IRcord[2])
		   		{
				    case 0x15:   //+
						if(i>0)
						 {
	
							i--;

	                         
							 for(j=0;j<8;j++)
				             {
				                P1=table[j];
								delay_ms(1);
				            
						 	 }	  	
				          }
					         break;    
				     case 0x07:   //-
			         if(i>0)
				      {
					  
				    	i--;
					   
                        for(j=0;j<8;j++)
			            {
			              P1=table1[j];
			           	  delay_ms(1);
			            }
				      }
				   
					     break;
					 case 0x46:
					   P1=0;delay_ms(5);  		
				             break;
					 case 0x45: 
					   P1 = 0XFF;delay_ms(5);		
				             break;
				}
		   }
		  IRpro_ok=0; //清零解码标志位等待下一次解码  
		}
	 }
  }
}

//****************************
//        按键模块
//****************************
//#include<reg52.h>
//#define uchar unsigned char
//#define uint unsigned int												
//sbit K1=P3^0;  	//	按下独立键盘S2正转
//sbit K2=P3^1;	//	按下独立键盘S3反转
//sbit K3=P3^2;	//	按下独立键盘S4停转
uchar code table[]={0xf1,0xf3,0xf2,0xf6,0xf4,0xfc,0xf8,0xf9};
uchar code table1[]={0xf9,0xf8,0xfc,0xf4,0xf6,0xf2,0xf3,0xf1};
//
//void delay(uchar z)
//{
//	uchar x,y;
//	for(x=z;x>0;x--)
//		for(y=110;y>0;y--);
//}
//
//void main()
//{
// 	uchar k,i;
//	P1=table[0];
//	while(1)
//	{
//		if(!K1)
//		delay(5);
//		if(!K1)
//		k=1;
//
//		if(!K2)
//		delay(5);
//		if(!K2)
//		k=2;
//
//		if(!K3)
//		delay(5);
//		if(!K3)
//		k=3;
//
//		if(k==1||k==2)
//		{
//			for(i=0;i<8;i++)
//			{
//				if(k==1) P1=table[i];
//				else P1=table1[i];
//				delay(20);
//			}
//		}
//	}					
//}
/*
PCF8591 AD芯片读取光敏数值，光线越强数码管数值越小，光线越暗数码管数据越大
DA输出的数值会以LED10的亮度来体现，数码管数值超过100,LED10会微亮，数值增加
LED10的亮度也增加。

当数值大于150时，蜂鸣器会发出提示音。
最简单的测试方法用手遮盖住光敏表面，数值会增加。
*/
//#include <reg52.h>
//#include <intrins.h>
//#define MAIN_Fosc		11059200UL	//宏定义主时钟HZ
//#define PCF8591_ADDR	0x90		//PCF8591地址
//#define DACOUT_EN		0x40		//DAC输出使能
//#define uchar unsigned char
//#define uint unsigned int
//sbit K1=P3^0;  	//	按下独立键盘S2正转
//sbit K2=P3^1;	//	按下独立键盘S3反转
//sbit K3=P3^2;	//	按下独立键盘S4停转
//sbit K4=P3^3;	//	按下独立键盘s5跳转功能
///*====================================
// 自定义类型名
//====================================*/
//typedef unsigned char INT8U;
//typedef unsigned char uchar;
//
//typedef unsigned int INT16U;
//typedef unsigned int uint;
//
///*====================================
// 硬件接口位声明
//====================================*/
//sbit SDA = P2^0;   //I2C串行数据
//sbit SCL = P2^1;   //I2C串行时钟
//sbit DU  = P2^6;   //数码管段选
//sbit WE  = P2^7;   //数码管位选
//sbit LED1= P1^0;   //读取AD的值是否成功（亮成功，灭失败）
//sbit LED2= P1^1;   //DAC成功输出（亮成功，灭失败）
//sbit BEEP= P2^3;   //蜂鸣器引脚定义
//
//uchar AD_Value;	//存储AD转换回的数字量
///*====================================
//共阴极数码管段选码
//====================================*/
//uchar code table[]={ 
////0		1	 2     3     4     5     6     7     8
//0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F,
////9     A     B	   C	 D	   E	 F		-	 .	  关显示
//0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x40, 0x80, 0x00
//                   };
//
///*====================================
//数码管位选码
//====================================*/
//				     //第1位	2位	  3位	 4位   5位	6位	  7位	8位
//uchar code T_COM[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};//数码管位码
//uchar code table0[]={0xf1,0xf3,0xf2,0xf6,0xf4,0xfc,0xf8,0xf9};
//uchar code table1[]={0xf9,0xf8,0xfc,0xf4,0xf6,0xf2,0xf3,0xf1};
//
//
///*====================================
//函数：void Delay_Ms(INT16U ms)
//参数：ms，毫秒延时形参
//描述：12T 51单片机自适应主时钟毫秒级延时函数
//====================================*/
//void Delay_Ms(INT16U ms)
//{
//     INT16U i;
//	 do{
//	      i = MAIN_Fosc / 96000; 
//		  while(--i);   //96T per loop
//     }while(--ms);
//}
//void Delay_Ms1(uint x)
//{
//   uint i,j;
//   for(i=x;i>0;i--)
//     for(j=110;j>0;j--);
//}
///*====================================
//函数：void Delay5us()
//描述：12T 51单片机5微秒延时函数自适应时钟（11.0592M，12M,22.1184M）
//====================================*/
//void Delay5us()
//{
//	#if MAIN_Fosc == 11059200
//		_nop_();
//	#elif MAIN_Fosc == 12000000
//		_nop_();
//	#elif MAIN_Fosc == 22118400
//		_nop_(); _nop_(); _nop_();
//	#endif
//}
//
///*====================================
//函数：void Display(INT8U Value)
//参数：Value,显示值 取值0-255
//描述：共阴极数码管显示函数可显示一个字节的数
//====================================*/
//void Display(INT8U Value)
//{
////------------------------------
//	DU = 1;
//	P0 = table[Value/100];	//管显示百位
//	DU = 0;
//
//	P0 = 0xff;			 	 //清除断码
//
//	WE = 1;
//	P0 = T_COM[0];		 	 //第一位数码管
//	WE = 0;
//	Delay_Ms(5);
////-------------------------------
//	DU = 1;
//	P0 = table[Value%100/10]; //显示十位
//	DU = 0;
//
//	P0 = 0xff;				  //清除断码
//
//	WE = 1;
//	P0 = T_COM[1];			  //第二位数码管
//	WE = 0;
//	Delay_Ms(5);
////-------------------------------
//	DU = 1;
//	P0 = table[Value%10];		//显示个位
//	DU = 0;
//								
//	P0 = 0xff;					//清除断码
//
//	WE = 1;
//	P0 = T_COM[2];				//第三位数码管
//	WE = 0;
//	Delay_Ms(5);
//}
//
///*====================================
//函数：I2C_init()
//描述：I2C总线初始化
//====================================*/
//void I2C_init()
//{
//	SDA = 1;   //数据总线高
//	_nop_();
//	SCL = 1;   //时钟总线高
//	_nop_();
//}
//
///*====================================
//函数：I2C_Start()
//描述：I2C起始信号
//====================================*/
//void I2C_Start()  
//{
//	SCL = 1;
//	_nop_();
//	SDA = 1;
//	Delay5us();
//	SDA = 0;
//	Delay5us();
//}
//
///*====================================
//函数：I2C_Stop()
//描述：I2C停止信号
//====================================*/
//void I2C_Stop()
//{
//	SDA = 0;
//	_nop_();
//	SCL = 1;
//	Delay5us();
//	SDA = 1;
//	Delay5us();
//}
//
///*====================================
//函数：Master_ACK(bit i)
//参数：i 为0时发送非应答 为1时发送应答
//描述：I2C主机发送应答
//====================================*/
//void Master_ACK(bit i)	
//{
//	SCL = 0; // 拉低时钟总线允许SDA数据总线上的数据变化
//	_nop_(); // 让总线稳定
//	if (i)	 //如果i = 1 那么拉低数据总线 表示主机应答
//	{
//		SDA = 0;
//	}
//	else	 
//	{
//		SDA = 1;	 //发送非应答
//	}
//	_nop_();//让总线稳定
//	SCL = 1;//拉高时钟总线 让从机从SDA线上读走 主机的应答信号
//	_nop_();
//	SCL = 0;//拉低时钟总线， 占用总线继续通信
//	_nop_();
//	SDA = 1;//释放SDA数据总线。
//	_nop_();
//}
//
///*====================================
//函数：Test_ACK()
//返回：0为非应答 1为应答
//描述：I2C检测从机应答
//====================================*/
//bit Test_ACK()	 // 检测从机应答
//{
//	SCL = 1;//时钟总线为高电平期间可以读取从机应答信号
//	Delay5us();
//	if (SDA)
//	{
//		SCL = 0;
//		I2C_Stop();
//		return(0);
//	}
//	else
//	{
//		SCL = 0;
//		return(1);
//	}
//}
//
///*====================================
//函数：I2C_send_byte(uchar byte)
//参数：byte 要发送的字节
//描述：I2C发送一个字节
//====================================*/
//void I2C_send_byte(uchar byte)
//{
//	uchar i;
//	for(i = 0 ; i < 8 ; i++)
//	{
//		SCL = 0;
//		_nop_();
//		if (byte & 0x80)	//
//		{
//			SDA = 1;
//			_nop_();
//		}
//		else
//		{
//			SDA = 0;
//			_nop_();
//		}
//		SCL = 1;
//		_nop_();
//		byte <<= 1;
//	}
//	SCL = 0;
//	_nop_();
//	SDA = 1;
//	_nop_();	
//}
//
///*====================================
//函数：I2C_read_byte()
//返回：读取的字节
//描述：I2C读一个字节
//====================================*/
//uchar I2C_read_byte()
//{
//	uchar i, dat;
//	SCL = 0 ;
//	_nop_();
//	SDA = 1;
//	_nop_();
//	for(i = 0 ; i < 8 ; i++)
//	{
//		SCL = 1;
//		_nop_();
//		dat <<= 1;	  
//		if (SDA)
//		{
//			dat |= 0x01;  
//		}
//		_nop_();
//		SCL = 0;
//		_nop_();
//	}
//	return(dat);
//}
//
///*DAC输出*/
//bit DAC_OUT(uchar DAT)
//{
//	I2C_Start();
//	I2C_send_byte(PCF8591_ADDR+0);
//	if (!Test_ACK())
//	{
//		return(0);
//	}
//	I2C_send_byte(DACOUT_EN);	//DA输出使能 
//	if (!Test_ACK())
//	{
//		return(0);
//	}
//	I2C_send_byte(DAT);
//	if (!Test_ACK())
//	{
//		return(0);
//	}
//	I2C_Stop();
//	return(1);	
//}
//
///*读AD数据*/
//bit ADC_Read(uchar CON)
//{
//	I2C_Start();
//	I2C_send_byte(PCF8591_ADDR+0);
//	if (!Test_ACK())
//	{
//		return(0);
//	}
//	I2C_send_byte(CON);
//	Master_ACK(0);
//	I2C_Start();
//	I2C_send_byte(PCF8591_ADDR+1);
//	if (!Test_ACK())
//	{
//		return(0);
//	}
//	AD_Value = I2C_read_byte();
//	Master_ACK(0);
//	I2C_Stop();
//	return(1);	
//}

//void main()
//{
//    
//	uint i;
//	I2C_init();
//	while(1)
//	{		
//		//单端输入，读出通道0的值(光敏)
//		if (ADC_Read(0x00))	LED1 = 0;	else	LED1 = 1;	
//		if (DAC_OUT(AD_Value))	LED2 = 0;	else	LED2 = 1;
//		Display(AD_Value);
//		if (AD_Value > 150)
//		{
//		    Display(AD_Value);
//			//BEEP = 0;
//			for(i=0;i<8;i++)
//			  {
//			     P1=table0[i];
//				 Display(AD_Value);
//			     Delay_Ms(3);
//				 
//			  }
//		}
//		else	
//		{
//		  Display(AD_Value);
//		  //BEEP = 1;
//		  for(i=0;i<8;i++)
//			  {
//			     P1=table1[i];
//				 Display(AD_Value);
//			     Delay_Ms(3);
//				 
//			  } 
//		}	
//	}	
//}
void main()
{
	uchar k,i;
	P1=table[0];
	uint n,num;
	num = 0;

	while(1)
	{
		if(k4 && num == 0 || !k4 && num == 3)	  //第一个功能
		{
			n = 1;
			num = 1;
		}
		else if (!k4 && num == 1 || k4 && num == 1) //第二个功能
		{
			n = 2;
			num = 2;
		}
		else if (k4 && num == 2 || !k4 && num == 2)	 //第三个功能
		{
			n = 3;
			num = 3;
		}
		switch(n)
		{
			case 2:
			{
//				while(1)
//				{		
//					uint i=0;
//					//单端输入，读出通道0的值(光敏)
//					if (ADC_Read(0x00))	LED1 = 0;	else	LED1 = 1;	
//					if (DAC_OUT(AD_Value))	LED2 = 0;	else	LED2 = 1;
//					Display(AD_Value);
//					if (AD_Value > 150)
//					{
//					    i++;
//					    Display(AD_Value);
//						//BEEP = 0;
//						for(i=0;i<8;i++)
//						  {
//						     P1=table0[i];
//							 Display(AD_Value);
//						     Delay_Ms(3);
//							 
//						  }
//						if(i==1)		
//						{
//						  return;
//						}
//					}
//					else	
//					{
//					   i++;
//					  Display(AD_Value);
//					  //BEEP = 1;
//					  for(i=0;i<8;i++)
//						  {
//						     P1=table1[i];
//							 Display(AD_Value);
//						     Delay_Ms(3);
//							 
//						  } 
//					  if(i==1)
//					  {
//					  	return;
//					  }
//					}
//				
//				}
			
			    
			}	
				break;
		
			case 1:
			{
				while(1)
				{
					if(!K1)
					delay(5);
					if(!K1)
					k=1;
			
					if(!K2)
					delay(5);
					if(!K2)
					k=2;
			
					if(!K3)
					delay(5);
					if(!K3)
					k=3;
			
					if(k==1||k==2)
					{
						for(i=0;i<8;i++)
						{
							if(k==1) P1=table0[i];
							else P1=table1[i];
							delay(20);
						}
					}
					if(!k4&&num=1)
					{
						TR0=1;
						break;
					}			  		   
				}	

				break;
			}
			}
				
		}
	}
//void main()
//{
// 	uchar k,i;
//	P1=table[0];
//	while(1)
//	{
//		if(!K1)
//		delay(5);
//		if(!K1)
//		k=1;
//
//		if(!K2)
//		delay(5);
//		if(!K2)
//		k=2;
//
//		if(!K3)
//		delay(5);
//		if(!K3)
//		k=3;
//
//		if(k==1||k==2)
//		{
//			for(i=0;i<8;i++)
//			{
//				if(k==1) P1=table0[i];
//				else P1=table1[i];
//				delay(20);
//			}
//		}
//	}					
//}