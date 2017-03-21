#include <EnableInterrupt.h>

/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

int val;
volatile int place = 0;
int pin4_place = 0;
bool pin4_reported = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(4, INPUT);
  enableInterrupt(4, ISR_pin4, FALLING);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  /* ANALOG */
  /*
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (3.3 / 1023.0);
  Serial.println(voltage);
  */

  /* Digital */
  /*
  val = digitalRead(4);
  Serial.println(val);
  delay(500);
  */
  if(pin4_place > 0 && (pin4_reported == false)) {
    Serial.print("Pin 4 came in place ");
    Serial.println(pin4_place);
    pin4_reported = true;
  }
}

void ISR_pin4() {
  pin4_place = ++place;
}

