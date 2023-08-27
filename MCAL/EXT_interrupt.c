/*
 * EXT_interrupt.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Hussein
 */

#include"..\Service\REG.h"
#include"..\Service\common_macros.h"
#include"EXT_interrupt.h"
#include"gpio.h"




void EXT_INT_Config(uint8 port_num,uint8 pin_num,INT_SENSE mode)
{
    if(port_num == PORTF_ID)
    {
        SET_BIT(NVIC_EN0_R,30);
    }
    else
    {
        SET_BIT(NVIC_EN0_R,port_num);
    }

    switch(port_num)
    {
    case PORTA_ID:
        SET_BIT(GPIO_PORTA_IM_R,pin_num);
        if(mode == LEVEL)
        {
            SET_BIT(GPIO_PORTA_IS_R,pin_num);
        }
        else if(mode == BOTH_EDGES)
        {
            CLEAR_BIT(GPIO_PORTA_IS_R,pin_num);
            SET_BIT(GPIO_PORTA_IBE_R,pin_num);
        }
        else if(mode == FALLING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTA_IS_R,pin_num);
            CLEAR_BIT(GPIO_PORTA_IEV_R,pin_num);

        }
        else if(mode == RISING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTA_IS_R,pin_num);
            SET_BIT(GPIO_PORTA_IEV_R,pin_num);
        }

        break;
    case PORTB_ID:
        SET_BIT(GPIO_PORTB_IM_R,pin_num);
        if(mode == LEVEL)
        {
            SET_BIT(GPIO_PORTB_IS_R,pin_num);
        }
        else if(mode == BOTH_EDGES)
        {
            CLEAR_BIT(GPIO_PORTB_IS_R,pin_num);
            SET_BIT(GPIO_PORTB_IBE_R,pin_num);
        }
        else if(mode == FALLING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTB_IS_R,pin_num);
            CLEAR_BIT(GPIO_PORTB_IEV_R,pin_num);

        }
        else if(mode == RISING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTB_IS_R,pin_num);
            SET_BIT(GPIO_PORTB_IEV_R,pin_num);
        }
        break;
    case PORTC_ID:
        SET_BIT(GPIO_PORTC_IM_R,pin_num);
        if(mode == LEVEL)
        {
            SET_BIT(GPIO_PORTC_IS_R,pin_num);
        }
        else if(mode == BOTH_EDGES)
        {
            CLEAR_BIT(GPIO_PORTC_IS_R,pin_num);
            SET_BIT(GPIO_PORTC_IBE_R,pin_num);
        }
        else if(mode == FALLING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTC_IS_R,pin_num);
            CLEAR_BIT(GPIO_PORTC_IEV_R,pin_num);

        }
        else if(mode == RISING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTC_IS_R,pin_num);
            SET_BIT(GPIO_PORTC_IEV_R,pin_num);
        }
        break;
    case PORTD_ID:
        SET_BIT(GPIO_PORTD_IM_R,pin_num);
        if(mode == LEVEL)
        {
            SET_BIT(GPIO_PORTD_IS_R,pin_num);
        }
        else if(mode == BOTH_EDGES)
        {
            CLEAR_BIT(GPIO_PORTD_IS_R,pin_num);
            SET_BIT(GPIO_PORTD_IBE_R,pin_num);
        }
        else if(mode == FALLING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTD_IS_R,pin_num);
            CLEAR_BIT(GPIO_PORTD_IEV_R,pin_num);

        }
        else if(mode == RISING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTD_IS_R,pin_num);
            SET_BIT(GPIO_PORTD_IEV_R,pin_num);
        }
        break;
    case PORTE_ID:
        SET_BIT(GPIO_PORTE_IM_R,pin_num);
        if(mode == LEVEL)
        {
            SET_BIT(GPIO_PORTE_IS_R,pin_num);
        }
        else if(mode == BOTH_EDGES)
        {
            CLEAR_BIT(GPIO_PORTE_IS_R,pin_num);
            SET_BIT(GPIO_PORTE_IBE_R,pin_num);
        }
        else if(mode == FALLING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTE_IS_R,pin_num);
            CLEAR_BIT(GPIO_PORTE_IEV_R,pin_num);

        }
        else if(mode == RISING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTE_IS_R,pin_num);
            SET_BIT(GPIO_PORTE_IEV_R,pin_num);
        }
        break;
    case PORTF_ID:
        SET_BIT(GPIO_PORTF_IM_R,pin_num);
        if(mode == LEVEL)
        {
            SET_BIT(GPIO_PORTF_IS_R,pin_num);
        }
        else if(mode == BOTH_EDGES)
        {
            CLEAR_BIT(GPIO_PORTF_IS_R,pin_num);
            SET_BIT(GPIO_PORTF_IBE_R,pin_num);
        }
        else if(mode == FALLING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTF_IS_R,pin_num);
            CLEAR_BIT(GPIO_PORTF_IEV_R,pin_num);

        }
        else if(mode == RISING_EDGE)
        {
            CLEAR_BIT(GPIO_PORTF_IS_R,pin_num);
            SET_BIT(GPIO_PORTF_IEV_R,pin_num);
        }
        break;
    }


}

void EXT_ClearBitHandler(uint8 port_num,uint8 pin_num)
{
    switch (port_num) {
    case PORTA_ID:

        SET_BIT(GPIO_PORTA_ICR_R,pin_num);
        break;

    case PORTB_ID:

        SET_BIT(GPIO_PORTB_ICR_R,pin_num);
        break;

    case PORTC_ID:

        SET_BIT(GPIO_PORTC_ICR_R,pin_num);
        break;

    case PORTD_ID:

        SET_BIT(GPIO_PORTD_ICR_R,pin_num);
        break;

    case PORTE_ID:

        SET_BIT(GPIO_PORTE_ICR_R,pin_num);
        break;

    case PORTF_ID:

        SET_BIT(GPIO_PORTF_ICR_R,pin_num);
        break;

    default:
        break;
    }
}

uint8 EXT_BitHandler( uint8 port_num, uint8 pin_num)
{
    uint8 data=0;
    switch (port_num) {
    case PORTA_ID:

        data = GET_BIT(GPIO_PORTA_MIS_R,pin_num);
        break;

    case PORTB_ID:

        data = GET_BIT(GPIO_PORTB_MIS_R,pin_num);
        break;

    case PORTC_ID:

        data = GET_BIT(GPIO_PORTC_MIS_R,pin_num);
        break;

    case PORTD_ID:

        data = GET_BIT(GPIO_PORTD_MIS_R,pin_num);
        break;

    case PORTE_ID:

        data = GET_BIT(GPIO_PORTE_MIS_R,pin_num);
        break;

    case PORTF_ID:

        data = GET_BIT(GPIO_PORTF_MIS_R,pin_num);
        break;

    default:
        break;
    }

    return data;
}





