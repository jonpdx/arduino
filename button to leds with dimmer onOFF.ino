//--------------------------------------------------------------
//Define Variables
  //constant values
    //outputs
      const int ledPinRed = 10; //arduino pin for LED 1
      const int ledPinGreen = 11; //arduino pin for LED 2
      const int serialPortNumber = 9600; //port number for the computer monitor
    //inputs
      const int buttonPin = 3; //arduino pin for button input
      const int analogKnob = A0; //arduino pin for analog Knob
    //constant values for equations
      const float allON = 255; //the most on a light can get
      const float knobStepSize = 1023.0; //amount of incriments in knob readings

  //changing variables
     int brightness = 255;    // how bright the LED is
//--------------------------------------------------------------

void setup() {
  //Outputs
    pinMode(ledPinRed,OUTPUT); //LED Red Color
    pinMode(ledPinGreen,OUTPUT); //LED Green Color
    Serial.begin(serialPortNumber); //computer monitor
  //inputs
    pinMode(buttonPin,INPUT); //push button
}

void loop() {
  //input from knob
  int sensorValue = analogRead(analogKnob); // read the input on analog pin A0:
  int brightness = sensorValue * (allON / knobStepSize); //convert input to brightness
  Serial.println(brightness); //print the brightness value to the monitor

  //Loop for Push Button
  if (digitalRead(buttonPin)== LOW){
      analogWrite(ledPinRed, brightness); //turn led on to the brightness values
      analogWrite(ledPinGreen, LOW); //turn led off
  }else{
    //if button is pressed turn it off
    digitalWrite(ledPinRed,LOW); //turn led off
    digitalWrite(ledPinGreen, brightness); //turn led on to the brightness values
  }
}
