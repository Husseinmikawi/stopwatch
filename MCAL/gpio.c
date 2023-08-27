/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the Tiva C GPIO driver
 *
 * Author: Hussein Ahmed
 *
 *******************************************************************************/
#include "gpio.h"
#include"..\Service\common_macros.h"
#include"..\Service\REG.h"

void GPIO_Init(uint8 port)
{

    SET_BIT(SYSCTL_RCGCGPIO_R,port);
    //SYSCTL_RCGCGPIO_R |=(1<<port); // enable clock for port

    //while(Get_Bit(SYSCTL_RCGCGPIO_R,port)){}; // check if port is enable

    //unlock port_C,port_D and port_F
    if(port == PORTC_ID ||port == PORTD_ID || port == PORTF_ID )
    {
        GPIO_PORTF_LOCK_R = 0X4C4F434B;
        GPIO_PORTF_CR_R  = 0X1F;
    }
}


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
    /*
     * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
     * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
     * In this case the input is not valid port/pin number
     */
    if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
    {
        /* Do Nothing */
    }
    else
    {
        /* Setup the pin direction as required */
        switch(port_num)
        {
        case PORTA_ID:
            SET_BIT(GPIO_PORTA_DEN_R,pin_num);
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTA_DIR_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTA_DIR_R,pin_num);
                if(direction == PIN_INPUTPUL)
                {
                    SET_BIT(GPIO_PORTA_PUR_R,pin_num);
                }
            }
            break;
        case PORTB_ID:
            SET_BIT(GPIO_PORTB_DEN_R,pin_num);
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTB_DIR_R,pin_num);

            }
            else
            {
                CLEAR_BIT(GPIO_PORTB_DIR_R,pin_num);
                if(direction == PIN_INPUTPUL)
                {
                    SET_BIT(GPIO_PORTB_PUR_R,pin_num);
                }
            }
            break;
        case PORTC_ID:
            SET_BIT(GPIO_PORTC_DEN_R,pin_num);
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTC_DIR_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTC_DIR_R,pin_num);
                if(direction == PIN_INPUTPUL)
                {
                    SET_BIT(GPIO_PORTC_PUR_R,pin_num);
                }
            }
            break;
        case PORTD_ID:
            SET_BIT(GPIO_PORTD_DEN_R,pin_num);
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTD_DIR_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTD_DIR_R,pin_num);
                if(direction == PIN_INPUTPUL)
                {
                    SET_BIT(GPIO_PORTD_PUR_R,pin_num);
                }
            }
            break;
        case PORTE_ID:
            SET_BIT(GPIO_PORTE_DEN_R,pin_num);
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTE_DIR_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTE_DIR_R,pin_num);
                if(direction == PIN_INPUTPUL)
                {
                    SET_BIT(GPIO_PORTE_PUR_R,pin_num);
                }
            }
            break;
        case PORTF_ID:
            SET_BIT(GPIO_PORTF_DEN_R,pin_num);
            if(direction == PIN_OUTPUT)
            {
                SET_BIT(GPIO_PORTF_DIR_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTF_DIR_R,pin_num);
                if(direction == PIN_INPUTPUL)
                {
                    SET_BIT(GPIO_PORTF_PUR_R,pin_num);
                }
            }
            break;
        }
    }
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
    /*
     * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
     * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
     * In this case the input is not valid port/pin number
     */
    if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
    {
        /* Do Nothing */
    }
    else
    {
        /* Write the pin value as required */
        switch(port_num)
        {
        case PORTA_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTA_DATA_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTA_DATA_R,pin_num);
            }
            break;
        case PORTB_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTB_DATA_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTB_DATA_R,pin_num);
            }
            break;
        case PORTC_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTC_DATA_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTC_DATA_R,pin_num);
            }
            break;
        case PORTD_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTD_DATA_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTD_DATA_R,pin_num);
            }
            break;
        case PORTE_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTE_DATA_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTE_DATA_R,pin_num);
            }
            break;
        case PORTF_ID:
            if(value == LOGIC_HIGH)
            {
                SET_BIT(GPIO_PORTF_DATA_R,pin_num);
            }
            else
            {
                CLEAR_BIT(GPIO_PORTF_DATA_R,pin_num);
            }
            break;
        }
    }
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
    uint8 pin_value = LOGIC_LOW;

    /*
     * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
     * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
     * In this case the input is not valid port/pin number
     */
    if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
    {
        /* Do Nothing */
    }
    else
    {
        /* Read the pin value as required */
        switch(port_num)
        {
        case PORTA_ID:
            if(BIT_IS_SET(GPIO_PORTA_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;
        case PORTB_ID:
            if(BIT_IS_SET(GPIO_PORTB_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;
        case PORTC_ID:
            if(BIT_IS_SET(GPIO_PORTC_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;
        case PORTD_ID:
            if(BIT_IS_SET(GPIO_PORTD_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;
        case PORTE_ID:
            if(BIT_IS_SET(GPIO_PORTE_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;
        case PORTF_ID:
            if(BIT_IS_SET(GPIO_PORTF_DATA_R,pin_num))
            {
                pin_value = LOGIC_HIGH;
            }
            else
            {
                pin_value = LOGIC_LOW;
            }
            break;
        }
    }

    return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
    /*
     * Check if the input number is greater than NUM_OF_PORTS value.
     * In this case the input is not valid port number
     */
    if(port_num >= NUM_OF_PORTS)
    {
        /* Do Nothing */
    }
    else
    {
        /* Setup the port direction as required */
        switch(port_num)
        {
        case PORTA_ID:
            GPIO_PORTA_DEN_R = 0xFF;
            GPIO_PORTA_DIR_R = direction;
            break;
        case PORTB_ID:
            GPIO_PORTB_DEN_R = 0xFF;
            GPIO_PORTB_DIR_R = direction;
            break;
        case PORTC_ID:
            GPIO_PORTC_DEN_R = 0xFF;
            GPIO_PORTC_DIR_R = direction;
            break;
        case PORTD_ID:
            GPIO_PORTD_DEN_R = 0xFF;
            GPIO_PORTD_DIR_R = direction;
            break;
        case PORTE_ID:
            GPIO_PORTE_DEN_R = 0xFF;
            GPIO_PORTE_DIR_R = direction;
            break;
        case PORTF_ID:
            GPIO_PORTF_DEN_R = 0xFF;
            GPIO_PORTF_DIR_R = direction;
            break;
        }
    }
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
    /*
     * Check if the input number is greater than NUM_OF_PORTS value.
     * In this case the input is not valid port number
     */
    if(port_num >= NUM_OF_PORTS)
    {
        /* Do Nothing */
    }
    else
    {
        /* Write the port value as required */
        switch(port_num)
        {
        case PORTA_ID:
            GPIO_PORTA_DATA_R = value;
            break;
        case PORTB_ID:
            GPIO_PORTB_DATA_R = value;
            break;
        case PORTC_ID:
            GPIO_PORTC_DATA_R = value;
            break;
        case PORTD_ID:
            GPIO_PORTD_DATA_R = value;
            break;
        case PORTE_ID:
            GPIO_PORTE_DATA_R = value;
            break;
        case PORTF_ID:
            GPIO_PORTF_DATA_R = value;
            break;
        }
    }
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
    uint8 value = LOGIC_LOW;

    /*
     * Check if the input number is greater than NUM_OF_PORTS value.
     * In this case the input is not valid port number
     */
    if(port_num >= NUM_OF_PORTS)
    {
        /* Do Nothing */
    }
    else
    {
        /* Read the port value as required */
        switch(port_num)
        {
        case PORTA_ID:
            value = GPIO_PORTA_DATA_R;
            break;
        case PORTB_ID:
            value = GPIO_PORTB_DATA_R;
            break;
        case PORTC_ID:
            value = GPIO_PORTC_DATA_R;
            break;
        case PORTD_ID:
            value = GPIO_PORTD_DATA_R;
            break;
        case PORTE_ID:
            value = GPIO_PORTE_DATA_R;
            break;
        case PORTF_ID:
            value = GPIO_PORTF_DATA_R;
            break;
        }
    }

    return value;
}
