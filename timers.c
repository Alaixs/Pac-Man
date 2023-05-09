/**
  ******************************************************************************************************************
  * @file    timers.c 
  * @author  IUT Informatique La Rochelle
  * @version v2.0
  * @date    2021
  * @modification	rien pour le moment
  * @brief   configurations des timers
  ******************************************************************************************************************/

#include "stm32f10x.h"                  /* STM32F10x.h definitions            */
#include "GLCD_Config.h"
#include "boule.h"
#include "ext_globales.h"
#include "timers.h"

/**
  * @brief  configuration du timer1 pour générer des interruptions
  * @param  None
  * @retval None
  */
void cfgTimer1(void){
		RCC->APB2ENR |= (1<<11); // fourniture de l'horloge sur le périphérique TMR1
    
		TIM1->PSC = 71; // prescaler de 72
    TIM1->ARR = 10000; // autoReload pour 10ms

    TIM1->DIER |= UIE; // autorisation des interruptions sur Timer1
    TIM1->CR1  |= CEN; // autorisation du comptage 
    
    *(volatile unsigned long *)0xE000E100 = (1<<25); // bit 25 pour activation IRQ Timer1 Up
}

void TIM1_UP_TIM10_IRQHandler (void){
//    LEDS_PORTB ^= (1<<8);
    if ( TIM1->SR & UIF ){  // apparemment inevitable de faire ce test car sinon, le CPU est capable de se dérouter
                            // dans la routine d'interruption alors que le drapeau n'est pas levé
        TIM1->SR &= ~UIF;
			
			//votre code
			
    }
}



