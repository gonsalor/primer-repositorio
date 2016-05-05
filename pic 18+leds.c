/*
 * File:   pic 18+leds.c
 * Author: gonzalo
 *
 * Created on 2 de mayo de 2016, 17:03
 */


#include <xc.h>

/* 
 * File:   display.c
 * Author: WILBERT VILLARROEL
 *
 * Created on 8 de junio de 2015, 18:02
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


/*fuses configuration of microcontroller*/
#pragma config CPUDIV = OSC1_PLL2, PLLDIV = 1, USBDIV = 2/*osc 4 mhz sin PLL de entrada y en la salida tenemos 96 mhz /2=48mhz*/
#pragma config FCMEN = OFF, IESO = OFF, FOSC = HSPLL_HS /*oscilador de alta velocidad*/
#pragma config PWRT = OFF, VREGEN = OFF, BORV = 2, BOR = OFF/*power up timer,regulador de voltage del usb, brownout reset deshabilitados*/
#pragma config WDTPS = 16384, WDT = OFF /*selector del postcaler del temporizador de perro guardian en 32760 y perro guardian desactivado*/
#pragma config CCP2MX = OFF, PBADEN = OFF, MCLRE = ON, LPT1OSC = OFF /*mux ccp2,AD en puerto B,master clear y temporizador del oscilador en bajo voltage desactivados*/
#pragma config STVREN = OFF, DEBUG = OFF, ICPRT = OFF, LVP = OFF, XINST = OFF/*reset en voltaje "0",pines de depuracion,bajo voltage de programacion,set de instruccion extendido desactivados*/
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF //no protegemos el codigo en el micro
#pragma config CPB = OFF, CPD = OFF /*bloque de codigo de ram ,memoria de instrucciones no protegidos*/
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF /*bits de los registros de escritura no portegidos*/
#pragma config WRTB = OFF, WRTC = OFF, WRTD = OFF /*bloque ,registro de configuracion,eeprom de datos de escritura no protegidos*/
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF /*bits de las tablas de lectura no protegido*/
#pragma config EBTRB = OFF /*bloque de tabla de lectura no protegi*/
/**/
#define _XTAL_FREQ 48000000 /*procesamiento digital del micro de salida*/
/*aqui se definen todas las funciones ,prototipos,rutinas o subrutinas*/
void retardo_ms(unsigned long x);
/*declaracion de variables globales y externas */
void main(void) {
    
    ADCON1 = 0x0F;  /*todos como entradas y salidas digitales*/
    TRISD = 0x00; /*todos los pines como entradas digitales*/
    LATD=0b00000001;
    while(1)
    {
        char i;
        for(i=0;i<7;i++){
         LATD*=2;
        retardo_ms(500); 
        }
        for(i=0;i<7;i++){
        LATD/=2;
        retardo_ms(500); 
        }

    }
         
    
    return;
}
void retardo_ms(unsigned long x)
{
    while(x--)__delay_ms(1);
}