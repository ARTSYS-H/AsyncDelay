/*
  AsyncDelay - Library for non-blocking delay.
  Created by Lucas H. Dijon, January 17, 2020.
  Released into the public domain.
*/

#include <AsyncDelay.h>

const int led_pin = 13;
byte Led = LOW;

AsyncDelay ledBlink;

void setup() {
 
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin,Led);
  // ledBlink.set(blink,250);
  // or
  ledBlink.setInterval(250);
  ledBlink.attach(blink);

}

void loop() {
  ledBlink.run();
}

void blink() {
    Led = !Led;
    digitalWrite(led_pin,Led);
}