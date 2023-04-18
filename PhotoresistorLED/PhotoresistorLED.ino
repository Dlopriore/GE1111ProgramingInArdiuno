 
/* 
 PhotoresistorLED 
 This program turns an LED on/off based on the reading from an analog sensor 
*/ 
 
// create constants to give names to the pins we're using. 
const int sensorPin = A0; 
const int ledPin = 13; 
// the threshold value below which the LED will turn on 
const int threshold = 0;  // <--- replace '0' with your calibrated value! 
int reading; 
 
void setup() 
{ 
  // set up the LED pin as an output and sensor pin as an input 
  pinMode(ledPin, OUTPUT); 
  pinMode(sensorPin, INPUT); 
} 
 
void loop() 
{ 
  // measure the voltage coming from the photoresistor 
  reading = analogRead(sensorPin); 
 
  // turn on LED if photoresistor reads below threshold value, and off if above 
  if(reading < threshold) 
  { 
    digitalWrite(ledPin, HIGH) ; 
  } 
  else 
  { 
    digitalWrite(ledPin, LOW) ; 
  } 
} 
