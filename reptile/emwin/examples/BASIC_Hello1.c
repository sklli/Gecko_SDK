/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.28 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to Energy  Micro AS whose registered
office is  situated at  Sandakerveien 118,  N-0484 Oslo, NORWAY solely
for  the  purposes  of  creating  libraries  for   Energy  Micros  ARM
Cortex-M3,  M4Fb processor-based devices,  sublicensed and distributed
under  the  terms  and conditions of  the End  User License  Agreement
supplied by Energy Micro AS. 
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_Hello1.c
Purpose     : Simple demo drawing "Hello world"
Requirements: WindowManager - ( )
              MemoryDevices - ( )
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
----------------------------------------------------------------------
*/

#include "GUI.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
//
// Recommended memory to run the sample with adequate performance
//
#define RECOMMENDED_MEMORY (1024L * 5)

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*******************************************************************
*
*       MainTask
*/
void MainTask(void) {
  int xPos;
  int yPos;
  int xSize;
  int i;
  
  i = 0;
  GUI_Init();
  //
  // Check if recommended memory for the sample is available
  //
  if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {
    GUI_ErrorOut("Not enough memory available."); 
    return;
  }
  xPos = LCD_GetXSize() / 2;
  yPos = LCD_GetYSize() / 3;
  GUI_SetTextMode(GUI_TM_REV);
  GUI_SetFont(GUI_FONT_20F_ASCII);
  GUI_DispStringHCenterAt("Hello world!", xPos, yPos);
  GUI_SetFont(GUI_FONT_D24X32);
  xSize = GUI_GetStringDistX("0000");
  xPos -= xSize / 2;
  yPos += 24 + 10;
  while (1) {
    GUI_DispDecAt( i++, xPos, yPos, 4);
    if (i > 9999) {
      i = 0;
    }
  }
}

/*************************** End of file ****************************/

