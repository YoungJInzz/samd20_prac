/*
 * user_header.c
 *
 * Created: 2024-12-02 오후 4:27:14
 *  Author: sohaj
 */ 
#include <atmel_start.h>
#include "user_timer.h"

static struct timer_task TIMER_0_task1;
static struct timer_task TIMER_0_task_ms;  // ms 카운터용 타이머 태스크
int isReset = 0;
uint32_t timer_ms_count = 0;  // ms 카운터
#define MAX_TIMER_MS_COUNT (0xFFFFFFFF - 1000)  // 오버플로우 직전 리셋 포인트

static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{	
    gpio_toggle_pin_level(s1_led);
    gpio_toggle_pin_level(s2_led);
    isReset = 1;
}

// 1ms마다 호출되는 타이머 콜백
static void TIMER_0_task_ms_cb(const struct timer_task *const timer_task)
{
    if(timer_ms_count) timer_ms_count--;
    
    // 오버플로우 방지: 특정 값에 도달하면 카운터 초기화
    //if (timer_ms_count >= MAX_TIMER_MS_COUNT) {
   //     timer_ms_count = 0;
   // }
}

void timer_delay_ms(uint32_t ms)
{

    uint32_t start_time = timer_ms_count;
    while ((timer_ms_count - start_time) < ms) {
        //  대기
    }
}

void TIMER_0_enable(void)
{
    // 기존 2초 타이머 설정
    TIMER_0_task1.interval = 2000;
    TIMER_0_task1.cb = TIMER_0_task1_cb;
    TIMER_0_task1.mode = TIMER_TASK_REPEAT;

    // 1ms 타이머 설정
    TIMER_0_task_ms.interval = 1;  // 1ms
    TIMER_0_task_ms.cb = TIMER_0_task_ms_cb;
    TIMER_0_task_ms.mode = TIMER_TASK_REPEAT;

    timer_add_task(&TIMER_0, &TIMER_0_task1);
    timer_add_task(&TIMER_0, &TIMER_0_task_ms);
    timer_start(&TIMER_0);
}
