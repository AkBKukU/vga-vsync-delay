/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
#define VSYNC_IN 2
#define HSYNC_IN 3

#define VSYNC_COUNT 2

volatile int h_count = 0;
volatile int h_offset = 8;

void vsync()
{
	h_count = 0;
}

void hsync()
{
	if (h_count == h_offset) {
		PORTB = PORTB & B11011111;
	}
	if (h_count == h_offset + VSYNC_COUNT) {
		PORTB = PORTB | B00100000;
	}

	h_count+=1;

}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(VSYNC_IN, INPUT);     
  pinMode(HSYNC_IN, INPUT);     
 attachInterrupt (INT0, vsync, FALLING);  // attach interrupt handler
 attachInterrupt (INT1, hsync, RISING);  // attach interrupt handler
}

// the loop routine runs over and over again forever:
void loop() {
 // digitalWrite(led, digitalRead(VSYNC_IN));   // turn the LED on (HIGH is the voltage level)
}
