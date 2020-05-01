#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if(++blink_count == 25){
    state_advance();
    led_update();
    blink_count =0;
  }
}
