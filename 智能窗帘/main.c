											   
#include <reg52.h>
//#include <intrins.h>
  /*====================================
 �Զ���������
====================================*/
typedef unsigned char INT8U;
typedef unsigned char uchar;

typedef unsigned int INT16U;
typedef unsigned int uint;
sbit IR  = P3^2;     //��������������ݽӿ�	�ⲿ�ж�O�����


uchar IRtime; 		//������ߵ�ƽ����ʱ�䣨����
uchar IRcord[4];    //���������ڴ�����������4���ֽڵ����ݣ��û���2���ֽ�+��ֵ��2���ֽڣ�
uchar IRdata[33];   //���������ڴ�������33λ���ݣ���һλΪ�������û���16+��ֵ��16��
bit IRpro_ok, IRok;  //��һ�����ں������4���ֽ���ϡ�IRok��Ϊ����������

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

//��ʼ����ʱ��0���ⲿ�ж�0������
void init()
{
    TMOD|=0X02;//���ö�ʱ��0������ʽ2,8λ�Զ���װ
	TL0=TH0=0;//��ʼ����ʱ��0�Ĵ�������ʱ��0������ʱ��Ϊ256����������
	EA=1;	 //�������ж�
	ET0=1;//������ʱ��0�ж�						
	TR0=1;//������ʱ��0

	IT0=1;//�����ⲿ�ж�0�½��ط�ʽ����
	EX0=1;//���ⲿ�ж�0�ж�

	TMOD |=0X20;//���ö�ʱ��1����ģʽ2,8λ�Զ���װ
	TL1=TH1=0Xfd;//������9600
	SM1=1;//���ô��ڹ���ģʽ1,10λ�첽�շ�
	TR1=1;//������ʱ��1
}   
//��ʱ��0�жϣ�ÿ�ж������Ҫ256*1.085us=277.76us
void time0() interrupt 1
{
     IRtime++;
}
//�ⲿ�ж�0����33�δ�����
void int0() interrupt 0
{
    static uchar i;//��̬�������ڴ���33�����ݼ���
	static bit startflag;//��ʼ�洢�����־λ��Ĭ����0
	if(startflag)
	{
	    //�ж������룬����������������ʼ�뿪ʼ�洢
		 if((IRtime<53)&&(IRtime>=32))
		      i=0;
		  IRdata[i]=IRtime;	//��T0����Ĵ������������������ʱ�����������
		  IRtime=0;	//��������
		  i++;		//��������������
		  if(i==33)	  //�����������33��ʱ������Ѿ�����33��
		  {
		      IRok=1;	//���������
			  i=0;		 //�������������
		  }	 
	}
	else
	{
		IRtime=0;// ��������
	    startflag=1;//��ʼ�����־λ��1
	}	 
}
//����ȡ��33������װNEC��׼Э�����
void IRcordpro()
{
   uchar i,j,k;//i���ڼ��������ĸ��ֽڣ�j���ڼ�������һ���ֽڵ�8λ���ݣ�k���ڼ�������33λ����
   k=1;//�ӵ�һλ����ʼ����������ʼ��
   for(i=0;i<4;i++)
   {
      for(j=0;j<8;j++)
	  {
	      //��������������0��׼��1125us��ô���ж�Ϊ����1
	      if(IRdata[k]>5)	 //�жϸߵ͵�ƽ
		      IRcord[i] |=0x80;	 //д1����
		  if(j<7)				//ֻ������7�Σ�����Ͱ����ݾ��Ƴ�ȥ��
		      IRcord[i]>>=1;
	   	   k++; //������һ������
	  }
   }
   IRpro_ok=1;
}
void main()
{
  uchar i;	//�������ڷ����ֽ���
  uchar j=0;
  init();  //��ʼ��
  while(1)
  {
     if(IRok)  //�ж��Ƿ����33�ε�������ȡ
	 {
	    IRcordpro(); //����
		IRok=0;		 //������������ɱ�־λ�ȴ���һ�ε�������
		if(IRpro_ok)  //�жϽ����Ƿ����
		{


		   for(i=0;i<4;i++)	//���ڷ����ĸ��ֽڵ�����
		   {

				IRcordpro(); //����
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
		  IRpro_ok=0; //��������־λ�ȴ���һ�ν���  
		}
	 }
  }
}

//****************************
//        ����ģ��
//****************************
//#include<reg52.h>
//#define uchar unsigned char
//#define uint unsigned int												
//sbit K1=P3^0;  	//	���¶�������S2��ת
//sbit K2=P3^1;	//	���¶�������S3��ת
//sbit K3=P3^2;	//	���¶�������S4ͣת
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
PCF8591 ADоƬ��ȡ������ֵ������Խǿ�������ֵԽС������Խ�����������Խ��
DA�������ֵ����LED10�����������֣��������ֵ����100,LED10��΢������ֵ����
LED10������Ҳ���ӡ�

����ֵ����150ʱ���������ᷢ����ʾ����
��򵥵Ĳ��Է��������ڸ�ס�������棬��ֵ�����ӡ�
*/
//#include <reg52.h>
//#include <intrins.h>
//#define MAIN_Fosc		11059200UL	//�궨����ʱ��HZ
//#define PCF8591_ADDR	0x90		//PCF8591��ַ
//#define DACOUT_EN		0x40		//DAC���ʹ��
//#define uchar unsigned char
//#define uint unsigned int
//sbit K1=P3^0;  	//	���¶�������S2��ת
//sbit K2=P3^1;	//	���¶�������S3��ת
//sbit K3=P3^2;	//	���¶�������S4ͣת
//sbit K4=P3^3;	//	���¶�������s5��ת����
///*====================================
// �Զ���������
//====================================*/
//typedef unsigned char INT8U;
//typedef unsigned char uchar;
//
//typedef unsigned int INT16U;
//typedef unsigned int uint;
//
///*====================================
// Ӳ���ӿ�λ����
//====================================*/
//sbit SDA = P2^0;   //I2C��������
//sbit SCL = P2^1;   //I2C����ʱ��
//sbit DU  = P2^6;   //����ܶ�ѡ
//sbit WE  = P2^7;   //�����λѡ
//sbit LED1= P1^0;   //��ȡAD��ֵ�Ƿ�ɹ������ɹ�����ʧ�ܣ�
//sbit LED2= P1^1;   //DAC�ɹ���������ɹ�����ʧ�ܣ�
//sbit BEEP= P2^3;   //���������Ŷ���
//
//uchar AD_Value;	//�洢ADת���ص�������
///*====================================
//����������ܶ�ѡ��
//====================================*/
//uchar code table[]={ 
////0		1	 2     3     4     5     6     7     8
//0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F,
////9     A     B	   C	 D	   E	 F		-	 .	  ����ʾ
//0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x40, 0x80, 0x00
//                   };
//
///*====================================
//�����λѡ��
//====================================*/
//				     //��1λ	2λ	  3λ	 4λ   5λ	6λ	  7λ	8λ
//uchar code T_COM[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};//�����λ��
//uchar code table0[]={0xf1,0xf3,0xf2,0xf6,0xf4,0xfc,0xf8,0xf9};
//uchar code table1[]={0xf9,0xf8,0xfc,0xf4,0xf6,0xf2,0xf3,0xf1};
//
//
///*====================================
//������void Delay_Ms(INT16U ms)
//������ms��������ʱ�β�
//������12T 51��Ƭ������Ӧ��ʱ�Ӻ��뼶��ʱ����
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
//������void Delay5us()
//������12T 51��Ƭ��5΢����ʱ��������Ӧʱ�ӣ�11.0592M��12M,22.1184M��
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
//������void Display(INT8U Value)
//������Value,��ʾֵ ȡֵ0-255
//�������������������ʾ��������ʾһ���ֽڵ���
//====================================*/
//void Display(INT8U Value)
//{
////------------------------------
//	DU = 1;
//	P0 = table[Value/100];	//����ʾ��λ
//	DU = 0;
//
//	P0 = 0xff;			 	 //�������
//
//	WE = 1;
//	P0 = T_COM[0];		 	 //��һλ�����
//	WE = 0;
//	Delay_Ms(5);
////-------------------------------
//	DU = 1;
//	P0 = table[Value%100/10]; //��ʾʮλ
//	DU = 0;
//
//	P0 = 0xff;				  //�������
//
//	WE = 1;
//	P0 = T_COM[1];			  //�ڶ�λ�����
//	WE = 0;
//	Delay_Ms(5);
////-------------------------------
//	DU = 1;
//	P0 = table[Value%10];		//��ʾ��λ
//	DU = 0;
//								
//	P0 = 0xff;					//�������
//
//	WE = 1;
//	P0 = T_COM[2];				//����λ�����
//	WE = 0;
//	Delay_Ms(5);
//}
//
///*====================================
//������I2C_init()
//������I2C���߳�ʼ��
//====================================*/
//void I2C_init()
//{
//	SDA = 1;   //�������߸�
//	_nop_();
//	SCL = 1;   //ʱ�����߸�
//	_nop_();
//}
//
///*====================================
//������I2C_Start()
//������I2C��ʼ�ź�
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
//������I2C_Stop()
//������I2Cֹͣ�ź�
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
//������Master_ACK(bit i)
//������i Ϊ0ʱ���ͷ�Ӧ�� Ϊ1ʱ����Ӧ��
//������I2C��������Ӧ��
//====================================*/
//void Master_ACK(bit i)	
//{
//	SCL = 0; // ����ʱ����������SDA���������ϵ����ݱ仯
//	_nop_(); // �������ȶ�
//	if (i)	 //���i = 1 ��ô������������ ��ʾ����Ӧ��
//	{
//		SDA = 0;
//	}
//	else	 
//	{
//		SDA = 1;	 //���ͷ�Ӧ��
//	}
//	_nop_();//�������ȶ�
//	SCL = 1;//����ʱ������ �ôӻ���SDA���϶��� ������Ӧ���ź�
//	_nop_();
//	SCL = 0;//����ʱ�����ߣ� ռ�����߼���ͨ��
//	_nop_();
//	SDA = 1;//�ͷ�SDA�������ߡ�
//	_nop_();
//}
//
///*====================================
//������Test_ACK()
//���أ�0Ϊ��Ӧ�� 1ΪӦ��
//������I2C���ӻ�Ӧ��
//====================================*/
//bit Test_ACK()	 // ���ӻ�Ӧ��
//{
//	SCL = 1;//ʱ������Ϊ�ߵ�ƽ�ڼ���Զ�ȡ�ӻ�Ӧ���ź�
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
//������I2C_send_byte(uchar byte)
//������byte Ҫ���͵��ֽ�
//������I2C����һ���ֽ�
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
//������I2C_read_byte()
//���أ���ȡ���ֽ�
//������I2C��һ���ֽ�
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
///*DAC���*/
//bit DAC_OUT(uchar DAT)
//{
//	I2C_Start();
//	I2C_send_byte(PCF8591_ADDR+0);
//	if (!Test_ACK())
//	{
//		return(0);
//	}
//	I2C_send_byte(DACOUT_EN);	//DA���ʹ�� 
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
///*��AD����*/
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
//		//�������룬����ͨ��0��ֵ(����)
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
		if(k4 && num == 0 || !k4 && num == 3)	  //��һ������
		{
			n = 1;
			num = 1;
		}
		else if (!k4 && num == 1 || k4 && num == 1) //�ڶ�������
		{
			n = 2;
			num = 2;
		}
		else if (k4 && num == 2 || !k4 && num == 2)	 //����������
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
//					//�������룬����ͨ��0��ֵ(����)
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