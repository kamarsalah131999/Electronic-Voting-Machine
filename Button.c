/*
 * Button.c
 *
 * Created: 7/09/2021 2:07:31 AM
 *  Author: kamar salah
 */ 
#include "DIO drivers.h"

void button_vinit (char port_name, char pin_num )
{
	DIO_vset_pin_dir( port_name,  pin_num, 0);
}

unsigned char button_u8read (char port_name, char pin_num)
{
	unsigned char x;
	x=DIO_u8read_pin( port_name,  pin_num);
	return x;
}