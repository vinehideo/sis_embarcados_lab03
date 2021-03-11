#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "driverlib/systick.h"
#include "driverleds.h" // Projects/drivers

// MEF com apenas 2 estados e 1 evento temporal que alterna entre eles
// Seleção por estado

typedef enum {state0,state1,state2,state3,state4,state5,state6,
state7} state_t;

volatile uint8_t Evento = 0;

void SysTick_Handler(void){
  Evento = 1;
} // SysTick_Handler

void main(void){
  static state_t Estado = state0; // estado inicial da MEF
  
  LEDInit(LED1);
  LEDInit(LED2);
  LEDInit(LED3);
 
  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  SysTickIntEnable();
  SysTickEnable();

  while(1){
    switch(Estado){
    case state0:
      LEDOff(LED1);
      LEDOff(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = state1;
      } // if
      break;
    case state1:
      LEDOff(LED1);
      LEDOff(LED2);
      LEDOn(LED3);
      if(Evento){
        Evento = 0;
        Estado = state2;
      } // if
      break;
      case state2:
      LEDOff(LED1);
      LEDOn(LED3);
      LEDOn(LED2);
      if(Evento){
        Evento = 0;
        Estado = state3;
      } // if
      break;
     case state3:
      LEDOff(LED1);
      LEDOn(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = state4;
      } // if
      break;
      case state4:
      LEDOn(LED1);
      LEDOn(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = state5;
      } // if
      break;
      case state5:
      LEDOn(LED1);
      LEDOn(LED2);
      LEDOn(LED3);
      if(Evento){
        Evento = 0;
        Estado = state6;
      } // if
      break;
      case state6:
      LEDOn(LED1);
      LEDOff(LED2);
      LEDOn(LED3);
      if(Evento){
        Evento = 0;
        Estado = state7;
      } // if
      break;
      case state7:
      LEDOn(LED1);
      LEDOff(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = state0;
      } // if
      break;
    } // switch
  } // while
} // main
