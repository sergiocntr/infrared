#define F_CPU 8000000;
#define __AVR_ATtiny85__ ;
#include <tiny_IRremote.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
SoftwareSerial mySerial(2, 0); //rx,tx
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  mySerial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  mySerial.println("Attiny85 IR");
}

void loop() {
  if (irrecv.decode(&results)) {
    mySerial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
