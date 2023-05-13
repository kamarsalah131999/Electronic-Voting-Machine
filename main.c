/*
 * coding.c
 * electronic voting machine
 
 * Created: 5/10/2021 12:42:16 AM
 * Author : kamar salah
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "Button.h"
#include "LCD driver.h"


unsigned char counter1=0;
unsigned char counter2=0;
unsigned char counter3=0;
unsigned char counter4=0;

int main(void)
{
    LCD_vinit();
	button_vinit('B',3);                                                            // define pin3 in PORT B as input
	button_vinit('B',4);                                                           // define pin4 in PORT B as input
	button_vinit('B',5);                                                          // define pin5 in PORT B as input
	button_vinit('B',6);                                                         // define pin6 in PORT B as input
	button_vinit('B',7);                                                        // define pin7 in PORT B as input
	
	LCD_vsend_string("A=0");                                                    // first leached dont have any voices
	LCD_vmove_cursor(1,12);
	LCD_vsend_string("B=0") ;                                                  // second leached dont have any voices
	LCD_vmove_cursor(2,1);                                                   
	LCD_vsend_string("C=0");                                                  // third leached dont have any voices
	LCD_vmove_cursor(2,12);                                                   
	LCD_vsend_string("D=0");                                                 // fourth leached dont have any voices
	
    while (1) 
    {
		if (button_u8read('B',3)==1)
		{
			counter1 ++;                                                             // increase voice to frist leached
			LCD_vmove_cursor(1,3);
			if (counter1<10)
			{
				LCD_vsend_char(counter1+48);                                        // ASCII for 0       >> printing to 9
			}
			else if (counter1<100)
			{
				LCD_vsend_char(counter1/10+48);                                    // printing to 99
				LCD_vsend_char(counter1%10+48);
			}
			
	   }
	   
	   else if (button_u8read('B',4)==1)
	   {
		   counter2 ++;                                                        // increase voice to second leached
		   LCD_vmove_cursor(1,14);
		   if (counter2<10)
		   {
			   LCD_vsend_char(counter2+48);                                        // ASCII for 0       >> printing to 9
		   }
		   else if (counter2<100)
		   {
			   LCD_vsend_char(counter2/10+48);                                    // printing to 99
			   LCD_vsend_char(counter2%10+48);
		   }
		   
	   }
	   
	   else if (button_u8read('B',5)==1)
	   {
		   counter3 ++;                                                        // increase voice to third leached
		   LCD_vmove_cursor(2,3);
		   if (counter3<10)
		   {
			   LCD_vsend_char(counter3+48);                                        // ASCII for 0       >> printing to 9
		   }
		   else if (counter3<100)
		   {
			   LCD_vsend_char(counter3/10+48);                                    // printing to 99
			   LCD_vsend_char(counter3%10+48);
		   }
		   
	   }
	   
	   else if (button_u8read('B',6)==1)
	   {
		   counter4 ++;                                                        // increase voice to forth leached
		   LCD_vmove_cursor(2,14);
		   if (counter4<10)
		   {
			   LCD_vsend_char(counter4+48);                                        // ASCII for 0       >> printing to 9
		   }
		   else if (counter4<100)
		   {
			   LCD_vsend_char(counter4/10+48);                                    // printing to 99
			   LCD_vsend_char(counter4%10+48);
		   }
		   
	   }
	   
	   else if (button_u8read('B',7)==1)
	   {
		   counter1=counter2=counter3=counter4=0;                             // reset voices
		   LCD_vmove_cursor(1,1);
		   LCD_vsend_string("A=0");                                                     // first leached dont have any voices
		   LCD_vmove_cursor(1,12);
		   LCD_vsend_string("B=0") ;                                                    // second leached dont have any voices
		   LCD_vmove_cursor(2,1);
		   LCD_vsend_string("C=0");                                                     // third leached dont have any voices
		   LCD_vmove_cursor(2,12);
		   LCD_vsend_string("D=0");                                                     // fourth leached dont have any voices
		   LCD_vmove_cursor(1,1);
		   
	  }
	  
	  _delay_ms(200);
	   
	   
    }

}

