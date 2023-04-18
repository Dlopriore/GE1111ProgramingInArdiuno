/* 
SensorCalibrate 
 
This program repeatedly takes a reading from a photoresistor and based on that sets 
the frequency coming out of a speaker on pin 8. It does this every 100 milliseconds. 
The reading and frequency output are sent to the Serial Monitor. 
*/ 
 
// create constants to name the pins we're using. 
const int sensorPin = A0; 
const int speakerPin = 8; 
 
// create constants for the lowest and highest sensor readings we expect 
// (the values 200 and 1000 are initial guesses) 
const int sensorLow = 200; 
const int sensorHigh = 1000; 
 
// variables for the reading from the photoresistor and then the corresponding 
// frequency output to the speaker 
int reading; 
int frequency; 
 
void setup() 
{ 
  // set up the speaker pin to be an output and sensor pin to be an input 
  pinMode(sensorPin, INPUT); 
  pinMode(speakerPin, OUTPUT); 
 
  // Begin Serial communication 
  Serial.begin(9600); 
} 
 
 
void loop() 
{
  // take a reading 
  reading = analogRead(sensorPin); 
 
  // rescale the reading to a frequency in the 6th octave 
  frequency = map(reading, sensorLow, sensorHigh, 1046, 2093); 
 
  // send this frequency to the speaker 
  tone(speakerPin, frequency, 120); 
 
  // print the values to the Serial monitor 
  Serial.print(reading); 
  Serial.print("   "); 
  Serial.println(frequency); 
 
  // pause the program for 100 ms 
  delay(100); 
} 
