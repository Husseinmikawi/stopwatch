/*
 * systick.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Hussein
 */
#include"systick.h"
#include"..\Service\REG.h"
#include"..\Service\common_macros.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

void _delay_ms(uint32 value)
{
    NVIC_ST_RELOAD_R = 4000 *value -1; // tick time is equal to 0.25 microsecond.
    /*
     * interrupt disabled
     * cpu frequency divided by 4(prescaler)
     * systick is enabled
     */
    NVIC_ST_CTRL_R = 0x01;

    while(!(GET_BIT(NVIC_ST_CTRL_R,16))); // wait until the count flag raised

    NVIC_ST_CTRL_R = 0x00;  // systick is disabled
    NVIC_ST_CURRENT_R =0; // clear count flag
}

/* Description:
 * Function to initialize the Systick driver */
void Systick_init(const Systick_config * Config_Ptr)
{
    if(Config_Ptr->CLK_mode == PRESCALER)
    {
        NVIC_ST_RELOAD_R = 4000 *Config_Ptr->initial_value -1;
        NVIC_ST_CTRL_R = 0x03;
    }
    else
    {
        NVIC_ST_RELOAD_R = 16000 *Config_Ptr->initial_value -1;
        NVIC_ST_CTRL_R = 0x07;

    }
}

void Systick_deinit(void)
{
    NVIC_ST_CTRL_R = 0x00;
}

/* Description:
 * Function to set the Call Back function address. */
void Systick_setCallBack(void(*a_ptr)(void))
{
    /* Save the address of the Call back function in a global variable */
    g_callBackPtr = a_ptr;
}

void systick_Handler(void )
{
    if(g_callBackPtr != NULL_PTR)
    {
        /* Call the Call Back function in the application after the edge is detected */
        (*g_callBackPtr)();
        NVIC_ST_CURRENT_R =0; // clear count flag

    }
}


