/*
 V Sync Delay

 VGA V Sync delay for Datapath VisionRGB capture cards that can't sync to some 
 640x480 signals.

 */
#include <stdlib.h>
 
#define VSYNC_OUT 13 // PORT B pin 5
#define VSYNC_IN   2
#define HSYNC_IN   3

#define VSYNC_COUNT 2
#define VGA_LINES 525

volatile int h_count = 0;
volatile int h_offset_store = 8;
volatile int h_offset = 8;

void vsync()
{

	/*
	if (h_count == VGA_LINES) {
		h_offset = h_offset_store;
	} else {
		h_offset = 0;
	}
	*/
	h_count = 0;
}

void hsync()
{
	if ( h_count == h_offset) {
		PORTB = PORTB & B11011111;
	}
	if ( h_count == h_offset + VSYNC_COUNT) {
		PORTB = PORTB | B00100000;
	}

	h_count+=1;

}

// the setup routine runs once when you press reset:
void setup() 
{                
	Serial.begin(115200);
	pinMode(VSYNC_OUT, OUTPUT);     
	pinMode(VSYNC_IN, INPUT);     
	pinMode(HSYNC_IN, INPUT);     
	attachInterrupt (INT0, vsync, FALLING);  // attach interrupt handler
	attachInterrupt (INT1, hsync, RISING);  // attach interrupt handler
}

// the loop routine runs over and over again forever:
void loop() 
{
	// Set different offset
	if (Serial.available() > 0) {
		if ( Serial.read() == ':' ) {
			int new_delay = Serial.parseInt();
			Serial.println(":"+String(new_delay));
			h_offset = new_delay;
			h_offset_store = h_offset;
			Serial.println("h: "+String(h_offset));
		}
	}

	//Serial.println(h_max);
}
