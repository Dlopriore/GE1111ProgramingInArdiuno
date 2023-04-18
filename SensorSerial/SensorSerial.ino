
/* 
SensorSerial 
 This program prints the reading from an analog sensor to the Serial Monitor. 
*/ 
 
const int sensorPin = A0; 
int reading; 
 
void setup() 
{ 
  // set up the sensor pin to be an input 
  pinMode(sensorPin, INPUT); 
 
  // Begin Serial communication 
  Serial.begin(9600); 
} 
void loop() 
{ 
  // measure the voltage coming from the photoresistor 
  reading = analogRead(sensorPin); 
 
  // print this value to Serial monitor 
  Serial.print("Photoresistor Reading: "); 
  Serial.println(reading); 
 
  delay(200); //slow down readings to about once every 200 msec (i.e., 5 per sec) 
} 
