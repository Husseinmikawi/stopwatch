/*
 * EXT_interrupt.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Hussein
 */

#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include"..\Service\std_types.h"

typedef enum {
    BOTH_EDGES,FALLING_EDGE,RISING_EDGE,LEVEL
}INT_SENSE;

void EXT_INT_Config(uint8 port_num,uint8 pin_num,INT_SENSE mode);
uint8 EXT_BitHandler( uint8 port_num, uint8 pin_num);
void EXT_ClearBitHandler( uint8 port_num, uint8 pin_num);

#endif /* EXT_INTERRUPT_H_ */
