/*
 * stopwatch.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Hussein
 */

#include"..\MCAL\systick.h"
#include"..\MCAL\gpio.h"
#include"..\HAL\lcd.h"
#include"..\MCAL\EXT_interrupt.h"
#include"..\Service\common_macros.h"
#include"..\Service\REG.h"
#include"../Service/SW_Timer.h"

static int sec =0;
unsigned char EXT_flag=0;
unsigned char EXT_flag_2=0;

Systick_config config = {1000,PRESCALER};

void Second_count(void)
{
    sec++;    //increment seconds with every Timer1_interrupt(1Sec)

}


void stopwatch_init(void)
{
    GPIO_Init(PORTF_ID);
    GPIO_setupPinDirection(PORTF_ID, PIN0_ID, PIN_INPUTPUL);
    //SET_BIT(GPIO_PORTF_PUR_R,PIN0_ID);
    GPIO_setupPinDirection(PORTF_ID, PIN4_ID, PIN_INPUTPUL);
    //SET_BIT(GPIO_PORTF_PUR_R,PIN4_ID);

    EXT_INT_Config(PORTF_ID, PIN0_ID, FALLING_EDGE);
    EXT_INT_Config(PORTF_ID, PIN4_ID, FALLING_EDGE);


    Systick_setCallBack(Second_count);

    /* LCD initializations */
    LCD_init();
    LCD_displayStringRowColumn(0,1,"**StopWatch**");
    LCD_displayStringRowColumn(1,4,"Project");
    SWT_delay(1500);
    LCD_clearScreen();

    Systick_init(&config);

}

void stopwatch_ON(void)
{

   static unsigned int tmr[6]={0}; /* array of six elements to carry values of stopwatch
                                             and initialize stopwatch with zero
                                             tmr[0]:units of seconds
                                             tmr[1]:tens  of seconds
                                             tmr[2]:units of minutes
                                             tmr[3]:tens  of minutes
                                             tmr[4]:units of hours
                                             tmr[5]:tens  of hours */
    unsigned char i;
    unsigned char Character1[8] = {0x00,
                                   0x1B,
                                   0x1B,
                                   0x1B,
                                   0x1B,
                                   0x1B,
                                   0x1B,
                                   0x00 };
    unsigned char Character2[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    tmr[0]=sec; // store the value of second on tmr[0]

    //clear LCD and start again from 0 Second (reset mode)
    if(EXT_flag==1  && EXT_flag_2==0)
    {
        LCD_clearScreen();
        LCD_moveCursor(0,2);
        LCD_displayCharacter('"');
        LCD_moveCursor(0,3);
        for(i=0;i<6;i++)
        {
            if((i>0) && (!(i&1)))
            {
                LCD_displayCharacter(':');
            }
            LCD_intgerToString(tmr[5-i]);

        }
        LCD_displayCharacter('"');
        EXT_flag =0;

    }
    else if(EXT_flag==3 && EXT_flag_2==1 )
    {
        sec=0;
        for(i=0;i<6;i++)
            tmr[i]=0;

        Systick_init(&config);
        EXT_flag=0;
    }
    if(EXT_flag_2==1)
    {

        Systick_deinit();
        LCD_Custom_Char(Character1,0,1,13);
        EXT_flag =2;

    }
    else if(EXT_flag_2==2)
    {
        LCD_Custom_Char(Character2,1,1,13);
        Systick_init(&config);
        EXT_flag =0;
        EXT_flag_2=0;
    }

    if(tmr[0]>9)
    {
        sec=0;
        tmr[0]=sec;
        tmr[1]++;//increment tens of seconds
        if(tmr[1]>5)
        {
            tmr[1]=0;
            tmr[2]++;//increment units of minutes
        }
        if(tmr[2]>9)
        {
            tmr[2]=0;
            tmr[3]++;//increment tens of minutes
        }
        if(tmr[3]>5)
        {
            tmr[3]=0;
            tmr[4]++;//increment units of hours
        }
        if(tmr[4]>9)
        {
            tmr[4]=0;
            tmr[5]++;//increment tens of hours
        }
        //when stop watch exceeds maximum time it will reset
        if(tmr[5]>9)
        {
            sec=0;
            for(i=0;i<6;i++)
                tmr[i]=0;
        }


    }

    LCD_moveCursor(1,3);
    for(i=0;i<6;i++)
    {
        if((i>0) && (!(i&1)))
        {
            LCD_displayCharacter(':');
        }
        LCD_intgerToString(tmr[5-i]);

    }

}

void EXT_PORTFHandler(void)
{
    if(EXT_BitHandler(PORTF_ID, PIN0_ID))
    {

        EXT_flag++;
        EXT_ClearBitHandler(PORTF_ID, PIN0_ID);
    }
    else if(EXT_BitHandler(PORTF_ID, PIN4_ID))
    {

        EXT_flag_2++;
        EXT_ClearBitHandler(PORTF_ID, PIN4_ID);
    }
}


