/**
 ******************************************************************************************************************
 * @file    main.c
 * @author  YNi & APi     IUT Informatique La Rochelle
 * @version v1.0
 * @date    2023
 * @modification	rien pour le moment
 * @brief   template pour piloter l'afficheur LCD des cartes MCBSTM32EXL
 ******************************************************************************************************************/

#include "GLCD_Config.h"
#include "boule.h"
#include "ext_globales.h"
#include "fantome.h"
#include "globales.h"
#include "stm32f10x.h" /* STM32F10x.h definitions            */

/*----------------------------------------------------------------------------*
  Main Program
 *----------------------------------------------------------------------------*/
int main(void) {

  /* Initialize graphical LCD display   */
  GLCD_Initialize();
  GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
  GLCD_SetForegroundColor(GLCD_COLOR_WHITE);

  /* Clear graphical LCD display        */
  GLCD_ClearScreen();

  GLCD_SetFont(&GLCD_Font_16x24);
  GLCD_DrawChar(10, 0, 'I');
  GLCD_SetForegroundColor(GLCD_COLOR_YELLOW);
  GLCD_DrawChar(30, 0, 'U');
  GLCD_SetForegroundColor(GLCD_COLOR_RED);
  GLCD_DrawChar(50, 0, 'T');
  GLCD_SetForegroundColor(GLCD_COLOR_WHITE);

  GLCD_SetFont(&GLCD_Font_6x8);
  GLCD_DrawString(80, 0, "La Rochelle");

  lAbscisse = 200;

  GLCD_DrawBitmap(lAbscisse, 100, LARGEUR_BOULE, HAUTEUR_BOULE,
                  (const unsigned char *)bmpBoule);
  GLCD_DrawBitmap(100, 100, 16, 16, (const unsigned char *)bmpfantomepacmanpng);

  GLCD_DrawHLine(150, 60, 30);
  GLCD_DrawVLine(150, 60, 30);

  GLCD_FrameBufferAccess(true);
       // faire avant appel à GLCD_DrawPixel et GLCD_ReadPixel pour
       // supprimer les limitations d'accès à la SRAM (uniquement
       // nécessaire sur les anciennes cartes sinon les fonctions
       // GLCD_DrawPixel et GLCD_ReadPixel ne fonctionnent pas

  GLCD_SetForegroundColor(0x1234);
  GLCD_DrawPixel(50, 150); // le petit point bleu sur l'écran....

  while (1) {
  }
}
