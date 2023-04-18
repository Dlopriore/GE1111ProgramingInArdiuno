int speaker = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(3) == LOW) {
  pinMode(speaker, OUTPUT);
  tone(speaker, 466, 100);
  delay(130);
  tone(speaker, 466, 100);
  delay(130);
  tone(speaker, 415, 100);
  delay(130);
  tone(speaker, 415, 100);
  delay(130);
  tone(speaker, 698, 300);
  delay(390);
  tone(speaker, 698, 300);
  delay(390);
  tone(speaker, 622, 600);
  delay(780);
  tone(speaker, 466, 100);
  delay(130);
  tone(speaker, 466, 100);
  delay(130);
  tone(speaker, 415, 100);
  delay(130);
  tone(speaker, 415, 100);
  delay(130);
  tone(speaker, 622, 300);
  delay(390);
  tone(speaker, 622, 300);
  delay(390);
  tone(speaker, 554, 300);
  delay(390);
  tone(speaker, 523, 100);
  delay(130);
  tone(speaker, 466, 200);
  delay(260);
  }
}
