#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
void main(void)
{
  configureClocks();
  lcd_init();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();
  clearScreen(COLOR_BROWN);
  or_sr(0x18);
  
}
