/*Logo-Beleuchtung SNES fuer scorp angepasst
 (c) jensma, jensma.de, 2012 
 ported to atmel studio 2013 sanni
 */

#include <avr/io.h>
#define F_CPU 8000000UL
// #define F_CPU 1000000UL
#include <avr/sleep.h>
#include <util/delay.h>

int led[4]={0,1,2,4}; // Pins mit LEDs
int count = 0;
double geschw = 1;
int verz = 10;
int modus = 0;
int breakout = 1;

uint8_t LOW = 0;
uint8_t HIGH = 1;

void delayMicroseconds(uint16_t us)
{
  while(us--) {
    _delay_us(1);
  }
}  


void digitalWrite(uint8_t pin, uint8_t val)
{
  if (val == LOW) {
    PORTB &= ~(1<<pin);
  } 
  else {
    PORTB |= (1<<pin);
  }
}

//Software PWM on Attiny85 von Ernst Christensen 16.okt. 2011, angepasst von jensma
void pwm(int freq,int spin)
{
  digitalWrite(spin,HIGH);
  delayMicroseconds(1*freq);
  digitalWrite(spin,LOW);
  delayMicroseconds(1*(255-freq));
}

int main(void)
{   
  //set outputs PortB
  DDRB |= (1<<0);
  DDRB |= (1<<1);
  DDRB |= (1<<2);
  DDRB |= (1<<4);
  

  while(1){

    for (count = 0; count < 4; count++)
    {
      for (int i = 1; i < 190; i+=1)//LED aufhellen
      {
        pwm(i,led[count]);
        delayMicroseconds(geschw);
      }

      for (int i = 1; i < 190; i+=1)//Und wieder abdunkeln
      {
        pwm(191-i,led[count]);
        delayMicroseconds(2*geschw);
      }

      verz++;

      if (verz > 16) {
        geschw *= 1.5;
      }//Das Aufhellen wird verlangsamt
      if (verz > 32) // In der letzten Phase leuchten alle LEDs noch mal auf
      {
        geschw = 1; //Ich recycle die Variablen mal, das schont den schmalen Platz
        verz = 0;
        modus = 0;
		breakout = 0;
        do {
          verz++; //Tick-Value



          if (verz > 3) {
            if (modus == 0) {
              geschw+=2;
            }
            else{
              geschw-=2;
            }
            verz = 0;

            if (geschw >= 250) {
              modus = 1;
            }

          }

          for (count = 0; count < 4; count++){
			pwm(geschw,led[count]);
          }

		  // if (geschw <= 50 && modus == 1)
          if (geschw == 1 && modus == 1)
          {
			breakout=1;
		  }

        }
        while (breakout==0); 
		while(1)
		{
			for (count = 0; count < 4; count++){
			//	pwm(50,led[count]);
			    digitalWrite(led[count],LOW);
			}
			set_sleep_mode(SLEEP_MODE_PWR_DOWN);
			sleep_mode();                   // in den Schlafmodus wechseln
		}
	  }
	}
  }
}
