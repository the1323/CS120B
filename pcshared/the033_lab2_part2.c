/*	Author:Tongyuan He &the033@ucr.edu
 *  Partner(s) Name:
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char temp = 0x00; 
	unsigned char cntavail=0x00;
while(1) {
        
        cntavail=0x00;
		temp = PINA;
		temp = temp & 0x0F;
		if(temp ==0x00){//0000
		    cntavail =0x04;
		}
		if((temp== 0x01)||(temp== 0x02)||(temp== 0x04)||(temp== 0x08)){
		    cntavail =0x03; 
		}
		
		if((temp== 0x03 || temp== 0x05 || temp== 0x06 || temp== 0x09 || temp== 0x0A || temp== 0x0C)){
		    cntavail = 0x02;
		    
		}
		if (temp== 0x07 || temp== 0x0B || temp== 0x0D || temp== 0x0E) {
            cntavail = 0x01;
        }
		
		
		
		PORTC = cntavail;
		
		
		}
	return 0;
}


