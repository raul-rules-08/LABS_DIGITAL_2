/*
 * File:   lAB_1.C
 * Author: RAUL_AGUILAR
 *
 * Created on January 31, 2021
 */

//configuracion del programa 
// CONFIG1
#pragma config FOSC  = XT        // Oscillator Selection bits (EC: I/O function on RA6/OSC2/CLKOUT pin, CLKIN on RA7/OSC1/CLKIN)
#pragma config WDTE  = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP    = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD   = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO  = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP   = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT   = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "PIC16F887.h"
#define _XTAL_FREQ 8000000

//definimos las variables

int cont  = 0;
int cont2 = 0;

//declaramos todas las funciones del programa 

void config     (void);
void LIGTHS_OUT (void);
void PLAYER_1   (void);
void PLAYER_2   (void);

void main(void) { //Ciclo principal
    
    config();
    
    if (PORTEbits.RE0 == 1){                 //revisamos si el boton esta presionado
        LIGTHS_OUT();                        //llamamos a la funcion
        if(PORTBbits.RB2 == 1){              //revisamos si la tercera luz esta encendida
            while ( cont < 8 && cont2 < 8) { // loop en cont y 2 no hayan llegado al final
                __delay_ms(30);
                if (PORTCbits.RC0 == 1){    // se revisa si el boton player_1 esta presionado
                    cont = cont+1;          //aumentamos el contador
                 }
                if (PORTDbits.RD0 == 1){   // se revisa si el boton de player_2 esta presionado
                    cont2 = cont2+1;       //aumentamos el contador del player_2
                 }
            PLAYER_1();                    // funcion  player-1
            PLAYER_2();                    // funcion  player_2
            }   
        
        }
    
    }       
    
}
  
    void config (void) {  //Configuraciones

        ANSELH = 0        ; 
        ANSEL = 0         ; 
        TRISB = 0         ; 
        
        TRISD = 0b00000001; 
        TRISC = 0b00000001; 
        TRISE = 0b001; 
        
        PORTB = 0         ; 
        PORTC = 0         ; 
        PORTD = 0         ; 
    }
 
    void LIGTHS_OUT (void){ // función del semaforo de salida 
    
        PORTBbits.RB0 = 1; //ponemos el puerto en 1  
        __delay_ms(80);
        
        PORTBbits.RB0 = 0; //ponemos el puerto en 0
        PORTBbits.RB1 = 1; //ponemos el puerto en 1 
         __delay_ms(80);
         
        PORTBbits.RB1 = 0;//ponemos el puerto en 0
        PORTBbits.RB2 = 1;//ponemos el puerto en 1
    }
     
    
    void PLAYER_1 (void){  // funcion player_1
        
           if  (cont == 1){ 
                PORTCbits.RC1 = 1; 
            }
           if  (cont == 2){  
                PORTCbits.RC2 = 1; 
            }
           if  (cont  == 3){ 
                PORTCbits.RC3 = 1;         
            }
           if  (cont  == 4){ 
                PORTCbits.RC4 = 1;         
            }
           if  (cont  == 5){             
                PORTCbits.RC5 = 1;            
            } 
           if  (cont == 6){               
                PORTCbits.RC6 = 1;           
            }
           if  (cont == 7){        
                PORTCbits.RC7 = 1;         
            }   
            
    }
    
    void PLAYER_2 (void){ // funcion player_2
        
            if (cont2 == 1){ 
                PORTDbits.RD1 = 1;   
            }
            if (cont2 == 2){ 
                PORTDbits.RD2 = 1;    
            }
            if  (cont2 == 3){ 
                PORTDbits.RD3 = 1;       
            }
            if  (cont2 == 4){ 
                PORTDbits.RD4 = 1;           
            }
            if (cont2 == 5){               
                PORTDbits.RD5 = 1;           
            }
            if (cont2 == 6){              
                PORTDbits.RD6 = 1;           
            }
            if (cont2 == 7){               
                PORTDbits.RD7 = 1;          
            }
            
    }
    
    
    