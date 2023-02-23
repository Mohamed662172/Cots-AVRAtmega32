/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/05/2020  ****************/
/*************** SWC      :  LibSTDTYPE  ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/
#ifndef __Std_Type__
#define __Std_Type__
//boolleen

#define FALSE       0

#define TRUE        1


#define NULL      ((void *)0)

/* Void */ 

typedef   void    Void;

/* unsigned Type */
typedef   unsigned char            _uint8;      // 0 ...... 255//
typedef   unsigned short int      _uint16;      // 0 ...... 65536 //
typedef   unsigned long int       _uint32;      // 0 ...... 4294967296 //
typedef   unsigned long long int  _uint64;      // 0 ...... 18446744073709551615 //
typedef   float                  _float32;      //4 Byte 
typedef   double                 _float64;      //8 Byte

/* signed Type */
typedef   signed char              _sint8;      // -128 ...... +127 //
typedef   signed short int        _sint16;      // -32768 ...... +32767 //
typedef   signed long int         _sint32;      // -2147483648 ...... +2147483647     //
typedef   signed long long int    _sint64;      // -9223372037709551618 ...... +9223372037709551617 //

/* ERROR STATUS CHECK */

typedef enum{ CHECK_SUCCESS=0,
              CHECK_FAIL=1
            }CheckStatus;
        

#endif