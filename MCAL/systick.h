/******************************************************************************
 *
 * Module: Systick
 *
 * File Name: systick.h
 *
 * Description: header file for the Systick driver
 *
 * Author: Hussein Ahmed
 *
 *******************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include"..\Service\std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
    PRESCALER,NO_PRESCALER
}Systick_CLK;

typedef struct
{
    uint32 initial_value;
    Systick_CLK CLK_mode;
}Systick_config;

void _delay_ms(uint32 value);
void Systick_setCallBack(void(*a_ptr)(void));
void Systick_init(const Systick_config * Config_Ptr);
void Systick_deinit(void);



#endif /* SYSTICK_H_ */
