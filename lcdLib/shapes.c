#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

u_char sqcol,sqrow,lcol,lrow,rcol,rrow;
u_char startRow,endRow;
void square(u_char col,u_char row,u_int colorBGR)
{
  for(sqcol=0;sqcol<=40;sqcol++){
    for(sqrow=0;sqrow<=40;sqrow++){
      drawPixel(sqcol+col,sqrow+row,colorBGR);
    }
  }
}

void lid(u_char col,u_char row,u_int colorBGR){
  for(lcol=0;lcol<=40;lcol++){
    for(lrow=0;lrow<=10;lrow++){
      drawPixel(lcol+col,lrow+row,colorBGR);
    }
  }
}

void rhombus(u_char col,u_char row,u_int colorBGR){
  for(rcol=0;rcol<50;rcol++){
    if(rcol<=10){
      startRow=0;
      endRow=rcol;
    }
    else if(rcol<=40){
      startRow = 0;
      endRow = 10;
    }
    else{
      startRow=rcol-40;
      endRow = 10;
    }
    for(rrow= startRow;rrow<=endRow;rrow++){
      drawPixel(rcol+col,rrow+row,colorBGR);
    }
  }
}

