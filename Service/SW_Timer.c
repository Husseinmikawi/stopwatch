/*
 * SW_Timer.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Hussein
 */


void SWT_delay(unsigned int ms)
{
    unsigned long long t;
    t = 1500 * ms;
    while(t)
    {
        t--;
    }
}

