int air_speed = A0;
int co_concentration = A1;
int co2_concentration = A2;
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int air_speed_value;
int co_concentration_value;
int co2_concentration_value;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello Computer");
}

void loop() {
  // read the value from the sensor:
  air_speed_value = analogRead(air_speed);
  co_concentration_value = analogRead(co_concentration);
  co2_concentration_value = analogRead(co2_concentration);
  
  Serial.println(air_speed_value);
  Serial.println(co2_concentration_value);
  Serial.println(co_concentration_value);
  Serial.println("endpoint");

  delay(250);
}