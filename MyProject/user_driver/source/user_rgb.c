#include <atmel_start.h>
#include "user_timer.h"
#include "user_switch.h"

uint16_t brightness = 0;
uint8_t	dim_mod = 1;

#define Brigter 1
#define Darker 2

void dimming()
{
	if(timer_ms_count) return;
	
	switch (dim_mod)
	{
		case Brigter: //밝기 조절
		hri_tccount8_write_CC_reg(TC1, 1, brightness);
		timer_ms_count = 10;
		
		brightness +=1;
		if(brightness == 255)
		{
			dim_mod = Darker;
		}
		break;
		
		case Darker : //대기시간
		brightness -= 1;
		hri_tccount8_write_CC_reg(TC1, 1, brightness);
		timer_ms_count = 10;
		
		if(brightness == 0)
		{
			dim_mod = Brigter;
			//timer_ms_count = 2000;
		}
		break;
		
	}
}

void changeColor()
{
	if(timer_ms_count) return;
	
	hri_tccount8_write_CC_reg(TC0, 1, hex_val*5);
	hri_tccount8_write_CC_reg(TC1, 0, hex_val*2);
	hri_tccount8_write_CC_reg(TC1, 1, hex_val*3);
	timer_ms_count=1;
	
}