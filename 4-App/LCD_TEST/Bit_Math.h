/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     : 23/05/2020   ****************/
/*************** SWC      :   LibBITMATH ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/

#ifndef __Bit_Math__
#define __Bit_Math__
//BIT OPERATION
#define SET_BIT(Reg, BitNum) (Reg |= (1 << BitNum))
#define CLEAR_BIT(Reg, BitNum) (Reg &= ~(1 << BitNum))
#define TOGGLE_BIT(Reg, BitNum) (Reg ^= (1 << BitNum))
#define GET_BIT(Reg, BitNum) ((Reg >> BitNum) & 1)
//#define GET_BIT_1(Reg, BitNum) (!!(Reg & (1 << BitNum)))

#endif
