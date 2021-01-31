//#include <stdio.h>
#include <conio.h>  //For clrscr

//#link "map.c"
//#link "input.c"
//#link "c64_bitmapmode.c"
//#link "bitwiseops.c"
//#link "common.c"

#include "map.h"
#include "input.h"
#include "common.h"
#include "bitwiseops.h"
#include "c64_bitmapmode.h"


void Initialize()
{
  InitializeInput();
  clrscr();
  
  setcolortextmode();
  
  InitializeMapData();
  
  DrawMap();
}

void main(void)
{ 
  int i = 0;
  Initialize();
  
  while(true)
  {
    //MapUpdate();
    //DrawMap();
    for(i = 0;i < 4; i++)
    raster_wait(255);
    ScrollChar(0,1);
    
    UpdateInput();
    if(InputChanged())
    {
      CheckInput();
      DrawMap();
    }
  }
}