#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  u_char row, col;
  u_char row2, col2;
  u_char startRow, endRow;
  clearScreen(COLOR_BROWN);
  
  for(row = 0; row<=10; row++){
    u_char startCol = row, endCol = row+40;
    //drawPixel(startCol,row,COLOR_BLACK);
    //drawPixel(endCol,row,COLOR_WHITE);
    for(col = startCol; col <= endCol; col++){
      drawPixel(col+40,row+50,COLOR_GREEN);
    }
  }

  for(col2=0;col2<50;col2++){
    if(col2<=10){
      startRow = 0;
      endRow = col2;
    }
    else if(col2<=40){
      startRow = 0;
      endRow = 10;
    }
    else{
      startRow = col2-40; 
      endRow = 10; 
    }
    for(row2 = startRow; row2 <= endRow; row2++){
      drawPixel(col2+40,row2+70,COLOR_BLACK);
    }
  }
  u_char mid, left, right;
  for(mid=0;mid<=20;mid++){/*changes the size or triangle */
    // drawPixel(50,mid,COLOR_RED);
    for(right=0;right<=mid;right++){
      drawPixel(mid+50,right+110,COLOR_PURPLE);
    }
  }
    u_char sqrow, sqcol;
    for(sqcol=0;sqcol<=10;sqcol++){//RED RECTANGLE
      for(sqrow = 0;sqrow<=30;sqrow++){
	drawPixel(sqcol+10,sqrow+40,COLOR_RED);
      }
    }
    u_char x,y;//YELLO RHOMBUS
    for(x=20;x>=1;x--){
      for(y=x+20;y>=x;y--){
	drawPixel(x+49,y+109,COLOR_YELLOW);
      }
    }
    u_char j,c,r;
      for(j=0;j<=10;j++){
	c = j;
        r = 5*j;
	drawPixel(c,r,COLOR_BLACK);
    }


  
  
}
  
  

  

