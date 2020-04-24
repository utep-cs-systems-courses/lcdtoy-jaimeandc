#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  u_char a;
  u_char b;
  u_char c;
  u_char d;
  clearScreen(COLOR_BLACK);

  for(a=50;a<90;a++){
    drawPixel(40,a,COLOR_GREEN);//Left Side
  }
  //for(u_char col = 40;col<50;col++){
  // for(u_char row= 50; row<90;row++){
  //    drawPixel(col,row,COLOR_YELLOW);
  //  }
  // }
  
  for(b=50; b<90; b++){
    drawPixel(80,b,COLOR_YELLOW);//Right Side
  }
  for(c=40;c<80;c++){
    drawPixel(c,50,COLOR_RED);//Top Side
  }
  for(d=40;d<80;d++){
    drawPixel(d,90,COLOR_BLUE);//Lower Side
  }
  drawString5x7(40,70,"The Book",COLOR_GREEN,COLOR_BLACK);

  u_char startRow, endRow;
  for(u_char col = 0; col <50;col++){
    if(col <=10){
      startRow = 0; endRow=10;}
    else if(col<=40){
      startRow = 0 ; endRow = 10;}
    else{
      startRow = 0; endRow = 10;}
    for(u_char row = startRow; startRow <= endRow; row++)
      drawPixel(col,row,COLOR_BLACK);
  }
  
}


