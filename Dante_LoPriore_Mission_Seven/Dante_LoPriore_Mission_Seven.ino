//Dante LoPriore
//October 24, 2022
//Mission 8

// create constants to name the pins we're using. 
const int sensorPin = A0; 

// create constants for the lowest and highest sensor readings we expect 
// (the values 200 and 1000 are initial guesses) 
const int sensorLow = 200; 
const int sensorHigh = 1000; 

// variables for the reading from the photoresistor and then the corresponding 
// frequency output to the speaker 
int reading; 

void setup() {
  // put your setup code here, to run once:

  // Pinhole-A0 -> INPUT
  // intializing pinhole A0 the on RedBoard to be an INPUT
  pinMode(sensorPin, INPUT);

  // Begin Serial communication 
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
  // initalizes the the light levels using analogRead
  // attempted bonus point where lights level incremently increases as you open the box.
  int lightLevel = analogRead(sensorPin);
  int LEDLevelDark = 255 - (lightLevel/0.5);
  int LEDLevelDim = 255 - (lightLevel/1);
  int LEDLevelSunset = 255 - (lightLevel/2);
  int LEDLevelNormal = 255 - (lightLevel/4);
  int LEDLevelBright = 255 - (lightLevel/8);
  */

  // take a reading 
  reading = analogRead(sensorPin); 
 
  // print the values to the Serial monitor
  Serial.print(reading); 
  Serial.print("   "); 
  Serial.println(millis()); 
 
  // pause the program for 500 ms 
  delay(500); 


  /*
  // to determine if the box is shut or the photorister has no lightLevel
  if(lightLevel <= 150) {
    analogWrite(redLight, LOW);
    analogWrite(blueLight, LOW);
  }

  // to determine if the box is slightly closed or the photorister has a little lightLevel
  if(lightLevel >= 151 && 201 <= lightLevel) {
    pinMode(speaker, OUTPUT);
    analogWrite(redLight, LEDLevelDark);
    analogWrite(blueLight, LEDLevelDark);
    digitalWrite(speaker, HIGH);
    delay(150);
    digitalWrite(speaker, LOW);
  }

  // to determine if the box is partially closed or the photorister has a moderate lightLevel
  if(lightLevel >= 201 && 250 <= lightLevel) {

    analogWrite(redLight, LEDLevelDim);
    analogWrite(blueLight, LEDLevelDim);
    delay(75);
  }

  // to determine if the box is half opened or the photorister has a normal lightLevel
  if(lightLevel >= 251 && 300 <= lightLevel) {
    
    analogWrite(redLight, LEDLevelSunset);
    analogWrite(blueLight, LEDLevelSunset);
    delay(50);
  }

  // to determine if the box is partially open or the photorister has a high lightLevel
  if(lightLevel >= 301 && 351 <= lightLevel) {

    analogWrite(redLight, LEDLevelNormal);
    analogWrite(blueLight, LEDLevelNormal);
    delay(25);
  }

  // to determine if the box is fully open or the photorister has the highest lightLevel
  if(lightLevel >= 352 && 450 <= lightLevel) {
    //plays jingle and lights flash to indicate that the box is fully open.
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    delay(300);
  }
  */
}
