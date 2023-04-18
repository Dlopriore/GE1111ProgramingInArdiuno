//Dante LoPriore
//September 26, 2022
//Mission 4


// to set pin numbers to the respective speaker
int speaker = 7;

// to set pin numbers to the respective lights
int redLight = 10;
int blueLight = 11;

void setup() {
  // put your setup code here, to run once:

  // Pinhole-A0 -> INPUT
  // intializing pinhole A0 the on RedBoard to be an INPUT
  pinMode(A0, INPUT);

  // Pinhole-7 -> OUTPUT
  // intializing pinhole 7 or the speaker on RedBoard to be an OUTPUT
  pinMode(speaker, OUTPUT);

  // Pinhole-10 -> OUTPUT
  // intializing pinhole 10 which is the red light on RedBoard to be an OUTPUT
  pinMode(redLight, OUTPUT);

  // Pinhole-11 -> OUTPUT
  // intializing pinhole 11 which is the blue light on RedBoard to be an OUTPUT
  pinMode(blueLight, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // initalizes the the light levels using analogRead
  // attempted bonus point where lights level incremently increases as you open the box.
  int lightLevel = analogRead(A0);
  int LEDLevelDark = 255 - (lightLevel/0.5);
  int LEDLevelDim = 255 - (lightLevel/1);
  int LEDLevelSunset = 255 - (lightLevel/2);
  int LEDLevelNormal = 255 - (lightLevel/4);
  int LEDLevelBright = 255 - (lightLevel/8);

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
    pinMode(speaker, OUTPUT);
    analogWrite(redLight, LEDLevelDim);
    analogWrite(blueLight, LEDLevelDim);
    digitalWrite(speaker, HIGH);
    delay(75);
    digitalWrite(speaker, LOW);
  }

  // to determine if the box is half opened or the photorister has a normal lightLevel
  if(lightLevel >= 251 && 300 <= lightLevel) {
    pinMode(speaker, OUTPUT);
    analogWrite(redLight, LEDLevelSunset);
    analogWrite(blueLight, LEDLevelSunset);
    digitalWrite(speaker, HIGH);
    delay(50);
    digitalWrite(speaker, LOW);
  }

  // to determine if the box is partially open or the photorister has a high lightLevel
  if(lightLevel >= 301 && 351 <= lightLevel) {
    pinMode(speaker, OUTPUT);
    analogWrite(redLight, LEDLevelNormal);
    analogWrite(blueLight, LEDLevelNormal);
    digitalWrite(speaker, HIGH);
    delay(25);
    digitalWrite(speaker, LOW);
  }

  // to determine if the box is fully open or the photorister has the highest lightLevel
  if(lightLevel >= 352 && 450 <= lightLevel) {
    //plays jingle and lights flash to indicate that the box is fully open.
    pinMode(speaker, OUTPUT);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    pinMode(speaker, OUTPUT);
    tone(speaker, 466, 100);
    delay(130);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    tone(speaker, 466, 100);
    delay(130);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 415, 100);
    delay(130);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    tone(speaker, 415, 100);
    delay(130);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 698, 300);
    delay(390);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    tone(speaker, 698, 300);
    delay(390);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 622, 600);
    delay(780);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    tone(speaker, 466, 100);
    delay(130);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 466, 100);
    delay(130);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    tone(speaker, 415, 100);
    delay(130);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 415, 100);
    delay(130);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    tone(speaker, 622, 300);
    delay(390);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 622, 300);
    delay(390);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    tone(speaker, 554, 300);
    delay(390);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 523, 100);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, LOW);
    delay(130);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    tone(speaker, 466, 200);
    delay(260);
  }
}
