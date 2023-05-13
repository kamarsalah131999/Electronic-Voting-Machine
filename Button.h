/*
 * Button.h
 *
 * Created: 7/09/2021 2:07:49 AM
 *  Author: kamar salah
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

/* function description 
define given pin in given port as input
*/
void button_vinit (char port_name, char pin_num );

/* function description 
return the value on the button 0 or 1 debend on connection pull down or pull up
*/
unsigned char button_u8read (char port_name, char pin_num);

#endif /* BUTTON_H_ */