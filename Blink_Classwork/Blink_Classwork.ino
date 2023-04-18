int LEDPIN = 11;
int delayTime = 300;
int val = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LEDPIN, val--);
  delay(delayTime);
  digitalWrite(LEDPIN, LOW);
  delay(delayTime--);
}
