int sensorPin = A0; // select the input pin 
int sensorValue = 0; // variable to store the value coming from the sensor

int sensorPinB = A5; // select the input pin 
int sensorValueB = 0; // variable to store the value coming from the sensor
 
#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
  // make a string for assembling the data to log:
  String dataString = "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 6; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
 
//void loop () 
//{
//  sensorValue = analogRead(sensorPin);
//
//  Serial.println();
//  Serial.print(millis()); // print the time in milliseconds since the program started
//  Serial.print(',');
//
//  if (sensorValue < 480){
//    Serial.print("Up");
//  }
//  else if (sensorValue > 510){
//    Serial.print("Down");
//  }
//  else{
//    Serial.print("flat");
//  }
//
//  //Print out the Joy Stick Reading
//  //delay(500);
//  //Serial.println(sensorValue);
//
//  Serial.print(',');
//  sensorValueB = analogRead(sensorPinB);
//
//  if (sensorValueB < 500){
//    Serial.print("Left");
//  }
//  else if (sensorValueB > 540){
//    Serial.print("Right");
//  }
//  else{
//    Serial.print("middle");
//  }
//  
//  //Print out the Joy Stick Reading
//  //delay(500);
//  //Serial.println(sensorValueB);
//
//  delay(500);
//}
