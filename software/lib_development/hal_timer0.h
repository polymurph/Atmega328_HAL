/*
MIT License

Copyright 2019 Edwin J. Koch

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
 * hal_timer0.h
 *
 * Created: 28-Oct-18 14:25:53
 *  Author: Edwin J. Koch
 */


#ifndef HAL_TIMER0_H_
#define HAL_TIMER0_H_

#include <stdint.h>
#include <avr/io.h>

typedef void (*fptr_t) (); /**< Function pointer typedef*/

typedef enum
{
	t0_outA_DISCONECTED = 0,
	t0_outA_TOGGLE_ON_COMPARE = (1 << COM0A0), // only if WGM02 is set otherwise OC0A is disconnected!
	t0_outA_CLEAR_ON_COMPARE = (1 << COM0A1),
	t0_outA_SET_ON_COMPARE = (1 << COM0A0) | (1 << COM0A1)
}t0_outA_Mode_t;

typedef enum
{
	t0_outB_DISCONECTED = 0,
	t0_outB_TOGGLE_ON_COMPARE = (1 << COM0B0),
	t0_outB_CLEAR_ON_COMPARE = (1 << COM0B1),
	t0_outB_SET_ON_COMPARE = (1 << COM0B0) | (1 << COM0B1)
}t0_outB_Mode_t;

typedef enum
{
	t0_clk_NO_CLK,
	t0_clk_NO_PRESCALE,
	t0_clk_CLK_DIV_8,
	t0_clk_CLK_DIV_64,
	t0_clk_CLK_DIV_256,
	t0_clk_CLK_DIV_1024,
	t0_clk_CLK_EXT_PIN_T0_FALLING_EDEGE,
	t0_clk_CLK_EXT_PIN_T0_RISING_EDEGE
}t0_clk_src_t;

typedef enum
{
	t0_mode_NORMAL = 0,
	t0_mode_PWM_PHASE_CORRECT_1 = (1 << WGM00),
	t0_mode_CTC = (1 << WGM01),
	t0_mode_FAST_PWM_1 = (1 << WGM01) | (1 << WGM00),
	t0_mode_PWM_PHASE_CORRECT_2 = (1 << WGM02) | (1 << WGM00),
	t0_mode_FAST_PWM_2 = (1 << WGM02) | (1 << WGM01) | (1 << WGM00)
}t0_mode_t;

void hal_timer0_enableModule();

void hal_timer0_dissableModule();

void hal_timer0_setMode(t0_mode_t mode);

void hal_timer0_setCompareValueA(uint8_t value);

void hal_timer0_setCompareValueB(uint8_t value);

void hal_timer0_setOutputA(t0_outA_Mode_t mode);

void hal_timer0_setOutputB(t0_outB_Mode_t mode);

void hal_timer0_setClockSource(t0_clk_src_t source);
//////////////////////////////////////////////////////////////////////////

// overflow callback setup functions
void hal_timer0_overflow_unregisterCB();

void hal_timer0_overflow_registerCB(fptr_t CBroutine);

void hal_timer0_overflow_enableCBroutine();

void hal_timer0_overflow_dissableCBroutine();

// compare match with A callback setup functions
void hal_timer0_compareMatch_unregisterCBA();

void hal_timer0_compareMatch_registerCBA(fptr_t CBroutineA);

void hal_timer0_compreMatch_enableCBroutineA();

void hal_timer0_compreMatch_dissableCBroutineA();

// compare match with B callback setup functions
void hal_timer0_compareMatch_unregisterCBB();

void hal_timer0_compareMatch_registerCBB(fptr_t CBroutineB);

void hal_timer0_compreMatch_enableCBroutineB();

void hal_timer0_compreMatch_dissableCBroutineB();

#endif /* HAL_TIMER0_H_ */