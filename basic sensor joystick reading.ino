/*
*Code for Arduino Uno Board
*Written in Atom
*
*Read Joystick sensor
*print to terminal: up, down, left, right
*
*by, Jon Barnes
*
*Created: September 16 2016
*Last Updated: September 16 2016
*/

//Create Variables for Sensor Inputs
int sensorPin = A0; // select the input pin
int sensorValue = 0; // variable to store the value coming from the sensor

int sensorPinB = A5; // select the input pin
int sensorValueB = 0; // variable to store the value coming from the sensor


//Begin reading from serial port ...aka usb
void setup ()
{
  Serial.begin (9600);
}


//Loop constant listen for inputs and convert to text readings
void loop ()
{
  sensorValue = analogRead(sensorPin);

  Serial.println();
  Serial.print(millis()); // print the time in milliseconds since the program started
  Serial.print(',');

  if (sensorValue < 480){
    Serial.print("Up");
  }
  else if (sensorValue > 510){
    Serial.print("Down");
  }
  else{
    Serial.print("flat");
  }

  //Print out the Joy Stick Reading
  //delay(500);
  //Serial.println(sensorValue);

  Serial.print(',');
  sensorValueB = analogRead(sensorPinB);

  if (sensorValueB < 500){
    Serial.print("Left");
  }
  else if (sensorValueB > 540){
    Serial.print("Right");
  }
  else{
    Serial.print("middle");
  }

  //Print out the Joy Stick Reading
  //delay(500);
  //Serial.println(sensorValueB);

  delay(500);
}
