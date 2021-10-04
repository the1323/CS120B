
/*	Author:Tongyuan He
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #4
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

	PORTA= 0xFF;
	PORTB= 0xFF;
    PORTC= 0xFF;
   	PORTD= 0x00;


    int temp = 0x00; 
	unsigned char tempa = 0x00; 
	unsigned char tempb = 0x00; 
	unsigned char tempc = 0x00; 
	unsigned char tempd = 0x00; 
	unsigned char approxweight = 0x00; 
	
		while(1) {
		tempd = 0x00;
		approxweight = 0x00;
        tempa = PINA;
        tempb = PINB;
        tempc = PINC;
        temp = tempa + tempb + tempc;
        
		if(temp >140){ 
			tempd = 0x01;
		}
		
		if(((tempa-tempc)>80)|| ((tempc-tempa)>80)) 
		{
			if(tempd==0x01){
				tempd = 0x03;
			}
			else{
			   tempd= 0x02;
			}
		}
		temp = (temp & 0xFC)>>2;//1111 1100
		approxweight = temp | tempd;
		if(approxweight==35) approxweight --;
		PORTD = approxweight;
		
		
		
		}
	return 0;
}

