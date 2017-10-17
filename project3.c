/*
 * project3.c
 *
 * Created: 5/5/2016 5:53:13 PM
 * Author : Aisha
 */ 
#include <string.h>
#include <avr/io.h>
#include "avr.h"
#include "lcd.h"


float tempo = 1.5;
float volume = 0;

unsigned long A = 113;
unsigned long Asharp =107;
unsigned long B = 101;
unsigned long C = 190;
unsigned long Csharp = 180;
unsigned long D = 170;
unsigned long Dsharp = 160;
unsigned long E = 151;
unsigned long F = 143;
unsigned long Fsharp = 135;
unsigned long G = 127;
unsigned long Gsharp = 120;
unsigned long Chigh = 95;
unsigned long quarter_note = 25000;
unsigned long half_note = 50000;
unsigned long eighth_note = 12500;
unsigned long whole_note = 100000;
unsigned long dotted_eighth = 18750;
unsigned long dotted_quarter = 75000;
unsigned long sixteen_note = 6250;
unsigned long Dhigh = 83;

unsigned char pressed(unsigned char r,unsigned char c){
	DDRC  = 0X0f;
	PORTC = 0xff;
	
	SET_BIT(DDRC, r);
	CLR_BIT(PORTC, r);

	wait_avr(1);
	
	if (GET_BIT(PINC, c+4))
	{
		return 0;
	}
	return 1;
}

unsigned char get_key(){
	unsigned char r, c;
	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			if(pressed(r, c))
			{
				return (r * 4) + c + 1;
			}
		}
	}
	return 0;
}

void playNote(unsigned long freq, unsigned long duration)
{
	//char buffer [50];
	//puts_lcd1(buffer);
	
	duration = duration * tempo;
	unsigned long decr = (freq * volume);
	unsigned long freq1 = freq - decr;
	unsigned long freq2 = freq + decr;
	
	//itoa(freq1, buffer, 10);
	
	

	SET_BIT(DDRA, 0);
	int i; 
	for (i = 0; i<duration/(freq * 2); ++i)
	{
		SET_BIT(PORTA, 0);
		wait_avr(freq1);
		CLR_BIT(PORTA, 0);
		wait_avr(freq2);
	}
	
}


void lion_sleeps_tonight(void)
{
	playNote(G, quarter_note);
	playNote(A, quarter_note);
	playNote(B, quarter_note);
	playNote(A, eighth_note);
	playNote(B, eighth_note);
	playNote(Chigh, quarter_note);
	playNote(B, quarter_note);
	playNote(A, quarter_note);
	playNote(G, eighth_note);
	playNote(A, eighth_note);
	playNote(B, quarter_note);
	playNote(A, quarter_note);
	playNote(G, quarter_note);
	playNote(B, quarter_note);
	playNote(A, whole_note);
	playNote(Dhigh, quarter_note);
	playNote(B, quarter_note);
	playNote(A, quarter_note);
	playNote(B, eighth_note);
	playNote(Dhigh, eighth_note);
	playNote(Chigh, quarter_note);
	playNote(B, quarter_note);
	playNote(A, quarter_note);
	playNote(G, eighth_note);
	playNote(A, eighth_note);
	playNote(B, quarter_note);
	playNote(A, quarter_note);
	playNote(G, quarter_note);
	playNote(B, quarter_note);
	playNote(A, whole_note);
}


void happy_birthday(void)
{
	playNote(D, dotted_eighth);
	playNote(D, sixteen_note);
	playNote(E, quarter_note);
	playNote(D, quarter_note);
	playNote(G, quarter_note);
	playNote(F, half_note);
	playNote(D, dotted_eighth);
	playNote(D, sixteen_note);
	playNote(E, quarter_note); 
	
	playNote(D, quarter_note);
	playNote(A, quarter_note);
	playNote(G, half_note);
	
	playNote(D, dotted_eighth); 
	playNote(D, sixteen_note); 
	playNote(Dhigh, quarter_note); 
	playNote(B, quarter_note);
	playNote(G, quarter_note);
	playNote(F, quarter_note);
	playNote(E, quarter_note);
	playNote(Chigh, dotted_eighth);
	playNote(Chigh, sixteen_note);
	
	playNote(B, quarter_note);
	playNote(G, quarter_note);
	playNote(A, quarter_note);
	playNote(G, half_note);

}

void ode_to_joy(void)
{
	
		playNote(E, quarter_note);
		playNote(E, quarter_note);
		playNote(F, quarter_note);
		playNote(G, quarter_note);
		playNote(G, quarter_note);
		playNote(F, quarter_note);
		playNote(E, quarter_note);
		playNote(D, quarter_note);
		playNote(C, quarter_note);
		playNote(C, quarter_note);
		playNote(D, quarter_note);
		playNote(E, quarter_note);
		
		playNote(E, quarter_note + eighth_note);
		playNote(D, eighth_note);
		playNote(D, half_note);
		
		playNote(E, quarter_note);
		playNote(E, quarter_note);
		playNote(F, quarter_note);
		playNote(G, quarter_note);
		playNote(G, quarter_note);
		playNote(F, quarter_note);
		playNote(E, quarter_note);
		playNote(D, quarter_note);
		playNote(C, quarter_note);
		playNote(C, quarter_note);
		playNote(D, quarter_note);
		playNote(E, quarter_note);
		
		
		playNote(D, quarter_note + eighth_note);
		playNote(C, eighth_note);
		playNote(C, half_note);
		
}

void mary_had_a_little_lamb(void)
{
	
		playNote(E, quarter_note);
		playNote(D, quarter_note);
		playNote(C, quarter_note);
		playNote(D, quarter_note);
		playNote(E, quarter_note);
		playNote(E, quarter_note);
		playNote(E, half_note);
		playNote(D, quarter_note);
		playNote(D, quarter_note);
		playNote(D, half_note);
		playNote(E, quarter_note);
		playNote(G, quarter_note);
		
		playNote(G, half_note);
		playNote(F, quarter_note);
		playNote(D, quarter_note);
		playNote(C, quarter_note);
		playNote(D, quarter_note);
		playNote(F, quarter_note);
		playNote(F, quarter_note);
		playNote(F, quarter_note);
		playNote(F, quarter_note);
		playNote(D, quarter_note);
		playNote(D, quarter_note);
		playNote(F, quarter_note);
		
		playNote(D, quarter_note);
		playNote(C, half_note);
	
		
	

	
	
}



void amazing_grace(void)
{
	playNote(D, half_note);
	playNote(G, whole_note);
	playNote(B, quarter_note);
	playNote(G, quarter_note);
	playNote(B, whole_note);
	playNote(A, half_note);
	playNote(G, whole_note);
	playNote(E, half_note);
	playNote(D, whole_note);
	playNote(D, half_note);
	playNote(G, whole_note);
	playNote(B, quarter_note);
	playNote(G, quarter_note);
	playNote(B, whole_note);
	playNote(A, half_note);
	playNote(Dhigh, whole_note + half_note);
	playNote(B, half_note);
	playNote(Dhigh, whole_note);
	playNote(Dhigh, quarter_note);
	playNote(B, quarter_note);
	playNote(G, whole_note);
	playNote(D, half_note);
	playNote(E, whole_note);
	playNote(G, quarter_note);
	playNote(E, quarter_note);
	playNote(D, whole_note);
	playNote(D, half_note);
	playNote(G, whole_note);
	playNote(B, quarter_note);
	playNote(G, quarter_note);
	playNote(B, whole_note);
	playNote(A, half_note);
	playNote(G, whole_note + half_note);
	
}


int main(void)
{
				    // lion_sleeps_tonight();
					//happy_birthday();
					//ode_to_joy();
					
					//mary_had_a_little_lamb();
					//amazing_grace();
	
	ini_lcd();	
	char printString[81];
	unsigned char keypadButton;
	int keypadPressed = 1;
	puts_lcd2("Mary Had a Little Lamb");
	while (1)
	{
		keypadButton = get_key();
		
		if(!keypadPressed && keypadButton){
			keypadPressed = 1;
			if (keypadButton == 1){
				clr_lcd();
				puts_lcd2("Amazing Grace");
				amazing_grace();
			}
			else if (keypadButton == 2){
				clr_lcd();
				puts_lcd2("Mary Had a Little Lamb");
				mary_had_a_little_lamb();
			}
			else if (keypadButton == 3){
				clr_lcd();
				puts_lcd2("Ode to Joy");
				ode_to_joy();
			}
			else if (keypadButton == 5){
				clr_lcd();
				puts_lcd2("Happy Birthday");
				happy_birthday();
			}
			else if (keypadButton == 6){
				clr_lcd();
				puts_lcd2("Lion Sleeps Tonight");
				lion_sleeps_tonight();
			}
			else if (keypadButton == 4){
				clr_lcd();
				//sprintf(printString, "tempo: %f", tempo);
				puts_lcd2(printString);
				tempo += 0.5;
			}
			else if (keypadButton == 8){
				clr_lcd();
				//sprintf(printString, "tempo: %f", tempo);
				puts_lcd2(printString);
				tempo -= 0.5;
			}
			else if (keypadButton == 13){
				clr_lcd();
				//sprintf(printString, "volume: %f", volume);
				puts_lcd2(printString);
				volume = 0;
			}
			else if (keypadButton == 14){
				clr_lcd();
				//sprintf(printString, "volume: %f", volume);
				puts_lcd2(printString);
				volume = 0.97;
			}
			else if (keypadButton == 15){
				clr_lcd();
				//sprintf(printString, "volume: %f", volume);
				puts_lcd2(printString);
				volume = 0.98;
			}
			else if (keypadButton == 16){
				clr_lcd();
				//sprintf(printString, "volume: %f", volume);
				puts_lcd2(printString);
				volume = 0.99;
			}
		}
		else if(!keypadButton){
			keypadPressed = 0;
		}
	}
}

