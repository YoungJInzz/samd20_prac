#ifndef USER_TIMER_H_
#define USER_TIMER_H_

#include <atmel_start.h>

/*
 * user_timer.h
 *
 * Created: 2024-12-02 오후 4:27:02
 *  Author: sohaj
 */ 
extern int isReset;

void TIMER_0_enable(void);
void timer_delay_ms(uint32_t ms);  // ms 딜레이 함수

#endif /* USER_TIMER_H_ */