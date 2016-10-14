#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

int air_speed = A0;
int co_concentration = A1;
int co2_concentration = A2;
int sensorValue = 0;  // variable to store the value coming from the sensor
int air_speed_value;
int co_concentration_value;
int co2_concentration_value;
char received_data;
File myFile;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(10)) {
    return;
  }
}

void loop() {
  // read the value from the sensor:
  air_speed_value = analogRead(air_speed);
  co_concentration_value = analogRead(co_concentration);
  co2_concentration_value = analogRead(co2_concentration);

  myFile = SD.open("air_data.txt", FILE_WRITE);
// if the file opened okay, write to it:
  if (myFile) {
    myFile.print(air_speed_value);
    myFile.print(";");
    myFile.print(co_concentration_value);
    myFile.print(";");
    myFile.println(co2_concentration_value);
  } else {}
  myFile.close();

//  Serial.print("Air Speed Value: ");
//  Serial.println(air_speed_value);
//  
//  Serial.print("CO concentration value: ");
//  Serial.println(co_concentration_value);
//  
//  Serial.print("CO2 concentration value: ");
//  Serial.println(co2_concentration_value);

    if (Serial.available() > 0) {
          received_data = Serial.read();

          Serial.print("I received: ");
          Serial.println(received_data);
  }
  
  delay(300);
}
