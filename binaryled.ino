/**
 * Binary LED 
 * 
 * Reads in a number from the serial port and shows it
 * in binary using LEDS
 *
 * @author Tom Price
 * @date 2013-01-13
 */

int ledPins[] = {2,3,4,5,6,7,8,9};
const int LEDS = 8;    //Number of output pins used for LEDs

void setup() {
  Serial.begin(9600);
  
  for(int i=0; i<LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  if(Serial.available() > 0) {
    int input = Serial.parseInt();
    
    if(input < 256 && input >= 0) {    //Number can be displayed in 8 bits
      binary(input);
    } else {    //Number too high or low
      numberError();
    }
    
  }
  delay(100);    //Wait 100ms before polling again
}

//Flash the lights to show the number can't be displayed
void numberError() {
  for(int i=0; i<3; i++) {
    allOn();
    delay(200);
    allOff();
    delay(200);
  } 
}

//Turn all lights on
void allOn() {
  for(int i=0; i<LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

//Turn all lights off
void allOff() {
  for(int i=0; i<LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  } 
}

//Recursively work out the binary representation
void recursiveCalc(int no, int pin) {
  digitalWrite(ledPins[pin], no%2);
  if(pin != 0) {
    recursiveCalc(no>>1, pin-1);
  }
}

//Start off the calculation
void binary(int no) {
  recursiveCalc(no, LEDS-1); 
}
