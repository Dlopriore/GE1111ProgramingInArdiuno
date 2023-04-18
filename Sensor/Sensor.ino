void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightLevel = analogRead(A0);
  int LEDLevel = 255 - (lightLevel/4);
  analogWrite(11, LEDLevel);
}
