/*
 * main.c
 *
 *  Created on: Jul 22, 2024
 *      Author: !?
 *
 */
#include <stdtype.h>
#include<util/delay.h>
#include <avr/io.h>
//typedef int u8;
//#define DDRA  *((u8*)0x3A)
//#define PORTA  *((u8*)0x3B)
//#define PORTB  *((u8*)0x38)

/*
int main()
{

	DDRA = 0xff;
    PORTA = 0xff;
    while(1)
    {
      PORTA = 0b10;  //2
      _delay_ms(250);
      PORTA= 0b100;  //4
      _delay_ms(250);
      PORTA =0b1000;  //8
      _delay_ms(250);


    }
}




*/







int main()
{
	int seg_cth[]={0x3f,0x06,0x5b,0x4f,0x66,0x60,0x7d,0x07,0x7f,0x6f};
	int i;
	DDRA = 0xff;
	DDRB = 0xff;
	PORTA |= (1<<1);
	PORTA |= (0<<2);
	PORTA |= (0<<3);
	PORTB = 0x00;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			PORTB=seg_cth[i];
			_delay_ms(250);
		}
		PORTA |=0<<1;
		PORTA |=0<<2;
		PORTA |=1<<3;
		for(i=5;i>0;i--)
		{
			PORTB=seg_cth[i];
			_delay_ms(200);
		}
		PORTA |= 0<<1;
		PORTA |= 1<<2;
		PORTA |= 0<<3;
		for(i=0;i<10;i++)
		{
			PORTB=seg_cth[i];
			_delay_ms(200);
		}
		PORTA |= 0<<1;
		PORTA |= 0<<2;
		PORTA |= 1<<3;
		for(i=5;i>0;i--)
		{
			PORTB=seg_cth[i];
			_delay_ms(250);
		}
		PORTA |= 1<<1;
		PORTA |= 0<<2;
		PORTA |= 0<<3;
	}

return 0;

}

