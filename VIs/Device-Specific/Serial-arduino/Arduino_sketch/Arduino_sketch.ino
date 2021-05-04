  
/*
 * timer_blink_micros
 *
 * Blinks the built-in LED every second using the arduino-timer library.
 *
 */

#include <arduino-timer.h>
int analogPin = A0;
Timer<1, micros> timer; // create a timer with 1 task and microsecond resolution
int val = 0; 


bool toggle_led_print(void *) {
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);
  return true; // repeat? true
}

void setup() {
 // analogReference(EXTERNAL);
  Serial.begin(115200);    
  // call the toggle_led function every 1000 micros (1 mili second)
  timer.every(996, toggle_led_print); //slightly faster to compansate for error.
}

void loop() {
  timer.tick(); // tick the timer
}
