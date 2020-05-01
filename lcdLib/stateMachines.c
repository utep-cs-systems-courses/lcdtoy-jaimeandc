#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "song.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "shapes.h"
static int direction = 0;
static int count = 0;
static int i = 0;
static int j = 0;
static int pos = 0;
static int tcol,trow,sqcol,sqrow;
char unsigned red_on =0, green_on = 0, led_changed = 0;

int scale[] = {2093,1975,1760,1567,1396,1318,1174};
int colpos[] = {10,60,10,60,50};
int rowpos[] = {10,10,90,90,50};
void state_advance(){
  int button = 0;
  switch(buttonSelect(button))
    {
    case 1:
      led_update();
      if(pos != sizeof(colpos)){
	square(colpos[pos],rowpos[pos],COLOR_BLUE);
      pos++;
      }else if(pos == sizeof(colpos)){
	pos=0;
      }
      break;
    case 2:
      switch(direction)
	{
	case 0:
	  /*Draw Cookie Jar*/
	  square(40,110,COLOR_YELLOW);

	  /*Lid Open*/
	  if(i != sizeof(rowpos))
	 {
	   buzzer_set_period(scale[i]);
	   lid(40,rowpos[i],COLOR_WHITE);
	   i++;
	   clearScreen(COLOR_BROWN);
	 }
	  break;
	case 1:
	  /*Cookie Jar*/
	  square(40,110,COLOR_YELLOW);
	  /*Lid Close*/
	  if(i != 0){
	    buzzer_set_period(scale[i]);
	    lid(40,rowpos[i],COLOR_BLACK);
	    i--;
	    clearScreen(COLOR_BROWN);
	  }
	  break;
	}
      break;
    case 3:
      buzzer_set_period(0);
      clearScreen(COLOR_BROWN);
      break;
    case 4:
      switch(direction)
	{
	case 0:
	  buzzer_set_period(2000);
	  direction = 1;
	  square(50,50,COLOR_GREEN);
	  drawString5x7(50,50,"UP",COLOR_BLACK,COLOR_GREEN);
	  break;
	case 1:
	  buzzer_set_period(4000);
	  direction = 0;
	  square(50,50,COLOR_RED);
	  drawString5x7(50,50,"DOWN",COLOR_BLACK,COLOR_RED);
	  break;
	}
      break;
    }
}


int buttonSelect(button)
{
  if(switch_state_down){
    button = 1;
  }
  else if(switch1_down){
    button = 2;
  }
  else if(switch2_down){
    button = 3;
  }
  else if(switch3_down){
    button = 4;
  }
  return button;
}
  
