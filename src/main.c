// main.c

/*----------------------------------------------------------------------------
/*----------------------------------------------------------------------------
Concevoir un programme qui incrémente le port B (LEDs) à chaque appui sur le
bouton BP_USER
* *---------------------------------------------------------------------------
-*/
#include <stm32f10x.h> // STM32F10x Library Definitions
#include "main.h"
unsigned long bpUser;
unsigned int memoire = 1; // état relâché par défaut
unsigned int nombre = 0;
void Enable_GPIO(void);
void Init_GPIO(void);
int main (void)
{
Enable_GPIO(); // Mise en service des ports
Init_GPIO(); // Initialisation des Ports
GPIOB->ODR = ALL_LED_OFF; // LED PB15 OFF
while(1){
bpUser = GPIOG->IDR & (1<<BP_USER); // lecture de l'état du bouton
// Si le bouton a un état différent de celui enregistré ET
 // que cet état est "appuyé"
 if((bpUser != memoire) && (bpUser == APPUYE)){
 // on incrémente la variable qui indique
 // combien de LED devrons s'allumer
nombre++;
nombre %= 256;
unsigned long tempo = 1000000; //tempo cochon pour éviter
while(tempo--);
 }
// on enregistre l'état du bouton pour le tour suivant
memoire = bpUser;
GPIOB->ODR = (nombre << LED_8); //on affiche le nombre sur les
}
}

void Enable_GPIO(void)
{
RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
}
void Init_GPIO(void)
{
GPIOB->CRH = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull)
GPIOG->CRH |= 0x00000004; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating
}