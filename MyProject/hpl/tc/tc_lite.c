
/**
 * \file
 *
 * \brief TC related functionality implementation.
 *
 * Copyright (c) 2017 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#include "tc_lite.h"

/**
 * \brief Initialize TC interface
 */
int8_t PWM_BLUE_init()
{

	hri_tc_wait_for_sync(TC0);
	if (hri_tc_get_CTRLA_reg(TC0, TC_CTRLA_ENABLE)) {
		hri_tc_clear_CTRLA_ENABLE_bit(TC0);
		hri_tc_wait_for_sync(TC0);
	}
	hri_tc_write_CTRLA_reg(TC0, TC_CTRLA_SWRST);
	hri_tc_wait_for_sync(TC0);

	hri_tc_write_CTRLA_reg(TC0,
	                       0 << TC_CTRLA_PRESCSYNC_Pos       /* Prescaler and Counter Synchronization: 0 */
	                           | 0 << TC_CTRLA_RUNSTDBY_Pos  /* Run in Standby: disabled */
	                           | 7 << TC_CTRLA_PRESCALER_Pos /* Setting: 7 */
	                           | 2 << TC_CTRLA_WAVEGEN_Pos   /* Waveform Generation Operation: 2 */
	                           | 0x1 << TC_CTRLA_MODE_Pos);  /* Operating Mode: 0x1 */

	// hri_tc_write_CTRLB_reg(TC0,0 << TC_CTRLBSET_CMD_Pos /* Command: 0 */
	//		 | 0 << TC_CTRLBSET_ONESHOT_Pos /* One-Shot: disabled */
	//		 | 0 << TC_CTRLBSET_DIR_Pos); /* Counter Direction: disabled */

	// hri_tc_write_CTRLC_reg(TC0,0 << TC_CTRLC_INVEN1_Pos /* Waveform Output 1 Invert Enable: disabled */
	//		 | 0 << TC_CTRLC_INVEN0_Pos); /* Waveform Output 0 Invert Enable: disabled */

	// hri_tc_write_READREQ_reg(TC0,0 << TC_READREQ_RREQ_Pos /*  Read Request: disabled */
	//		 | 0 << TC_READREQ_RCONT_Pos /*  Read Continuously: disabled */
	//		 | 0x0); /* Address: 0x0 */

	// hri_tc_write_DBGCTRL_reg(TC0,0); /* Run in debug: 0 */

	// hri_tccount8_write_CC_reg(TC0, 0 ,0x0); /* Compare/Capture Value: 0x0 */

	// hri_tccount8_write_CC_reg(TC0, 1 ,0x0); /* Compare/Capture Value: 0x0 */

	// hri_tccount8_write_COUNT_reg(TC0,0x0); /* Counter Value: 0x0 */

	// hri_tc_write_PER_reg(TC0,0x0); /*  Period Value: 0x0 */

	// hri_tc_write_EVCTRL_reg(TC0,0 << TC_EVCTRL_MCEO0_Pos /* Match or Capture Channel 0 Event Output Enable: disabled
	// */
	//		 | 0 << TC_EVCTRL_MCEO1_Pos /* Match or Capture Channel 1 Event Output Enable: disabled */
	//		 | 0 << TC_EVCTRL_OVFEO_Pos /* Overflow/Underflow Event Output Enable: disabled */
	//		 | 0 << TC_EVCTRL_TCEI_Pos /* TC Event Input: disabled */
	//		 | 0 << TC_EVCTRL_TCINV_Pos /* TC Inverted Event Input: disabled */
	//		 | 0); /* Event Action: 0 */

	// hri_tc_write_INTEN_reg(TC0,0 << TC_INTENSET_MC0_Pos /* Match or Capture Channel 0 Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_MC1_Pos /* Match or Capture Channel 1 Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_SYNCRDY_Pos /* Synchronization Ready Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_ERR_Pos /* Error Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_OVF_Pos); /* Overflow Interrupt enable: disabled */

	hri_tc_write_CTRLA_ENABLE_bit(TC0, 1 << TC_CTRLA_ENABLE_Pos); /* Enable: enabled */

	return 0;
}

/**
 * \brief Initialize TC interface
 */
int8_t PWM_GREEN_RED_init()
{

	hri_tc_wait_for_sync(TC1);
	if (hri_tc_get_CTRLA_reg(TC1, TC_CTRLA_ENABLE)) {
		hri_tc_clear_CTRLA_ENABLE_bit(TC1);
		hri_tc_wait_for_sync(TC1);
	}
	hri_tc_write_CTRLA_reg(TC1, TC_CTRLA_SWRST);
	hri_tc_wait_for_sync(TC1);

	hri_tc_write_CTRLA_reg(TC1,
	                       0 << TC_CTRLA_PRESCSYNC_Pos       /* Prescaler and Counter Synchronization: 0 */
	                           | 0 << TC_CTRLA_RUNSTDBY_Pos  /* Run in Standby: disabled */
	                           | 7 << TC_CTRLA_PRESCALER_Pos /* Setting: 7 */
	                           | 2 << TC_CTRLA_WAVEGEN_Pos   /* Waveform Generation Operation: 2 */
	                           | 0x1 << TC_CTRLA_MODE_Pos);  /* Operating Mode: 0x1 */

	// hri_tc_write_CTRLB_reg(TC1,0 << TC_CTRLBSET_CMD_Pos /* Command: 0 */
	//		 | 0 << TC_CTRLBSET_ONESHOT_Pos /* One-Shot: disabled */
	//		 | 0 << TC_CTRLBSET_DIR_Pos); /* Counter Direction: disabled */

	// hri_tc_write_CTRLC_reg(TC1,0 << TC_CTRLC_INVEN1_Pos /* Waveform Output 1 Invert Enable: disabled */
	//		 | 0 << TC_CTRLC_INVEN0_Pos); /* Waveform Output 0 Invert Enable: disabled */

	// hri_tc_write_READREQ_reg(TC1,0 << TC_READREQ_RREQ_Pos /*  Read Request: disabled */
	//		 | 0 << TC_READREQ_RCONT_Pos /*  Read Continuously: disabled */
	//		 | 0x0); /* Address: 0x0 */

	// hri_tc_write_DBGCTRL_reg(TC1,0); /* Run in debug: 0 */

	// hri_tccount8_write_CC_reg(TC1, 0 ,0x0); /* Compare/Capture Value: 0x0 */

	// hri_tccount8_write_CC_reg(TC1, 1 ,0x0); /* Compare/Capture Value: 0x0 */

	// hri_tccount8_write_COUNT_reg(TC1,0x0); /* Counter Value: 0x0 */

	// hri_tc_write_PER_reg(TC1,0x0); /*  Period Value: 0x0 */

	// hri_tc_write_EVCTRL_reg(TC1,0 << TC_EVCTRL_MCEO0_Pos /* Match or Capture Channel 0 Event Output Enable: disabled
	// */
	//		 | 0 << TC_EVCTRL_MCEO1_Pos /* Match or Capture Channel 1 Event Output Enable: disabled */
	//		 | 0 << TC_EVCTRL_OVFEO_Pos /* Overflow/Underflow Event Output Enable: disabled */
	//		 | 0 << TC_EVCTRL_TCEI_Pos /* TC Event Input: disabled */
	//		 | 0 << TC_EVCTRL_TCINV_Pos /* TC Inverted Event Input: disabled */
	//		 | 0); /* Event Action: 0 */

	// hri_tc_write_INTEN_reg(TC1,0 << TC_INTENSET_MC0_Pos /* Match or Capture Channel 0 Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_MC1_Pos /* Match or Capture Channel 1 Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_SYNCRDY_Pos /* Synchronization Ready Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_ERR_Pos /* Error Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_OVF_Pos); /* Overflow Interrupt enable: disabled */

	hri_tc_write_CTRLA_ENABLE_bit(TC1, 1 << TC_CTRLA_ENABLE_Pos); /* Enable: enabled */

	return 0;
}
