//Dante LoPriore 
//September 12, 2022
//Final Mission 2

void setup() {
  // put your setup code here, to run once:

  // Pinhole-10 -> OUTPUT
  // intializing pinhole 10 on RedBoard to be an OUTPUT
  pinMode(10, OUTPUT);

  // Pinhole-11 -> OUTPUT
  // intializing pinhole 11 on RedBoard to be an OUTPUT
  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Add two second pause before emiting the morse code.
  delay(2000);

  // Pinhole-10 -> 5V
  // This will turn on the yellow light.
  // Pinhole-10 will remain on or lit up with 5V throughout the loop
  digitalWrite(10, HIGH);

  /*
   * Pinhole-11 connected to the blue light will emit the morse code.
   * The morse code will be my intials which is DL.
  */

  // Producing D
  // The letter D in morse is dash, dot, dot.

  // Pinhole-11 -> 5V
  // This will turn on the yellow light.
  // Pinhole-11 will remain on or lit up with 5V throughout the loop
  digitalWrite(11, HIGH);
  delay(1000);
  
  // Pinhole-11 -> 5V
  // Produce the first dash for D
  digitalWrite(11, HIGH);
  delay(3000);

  // Pinhole-11 -> 0V
  // Produce the start of the first dot for D
  digitalWrite(11, LOW);
  delay(1000);

  // Pinhole-11 -> 5V
  // Produce the end of the first dot for D
  digitalWrite(11, HIGH);
  delay(1000);

  // Pinhole-11 -> 0V
  // Produce the start of the second dot for D
  digitalWrite(11, LOW);
  delay(1000);

  // Pinhole-11 -> 5V
  // Produce the end of the second dot for D
  digitalWrite(11, HIGH);
  delay(1000);

  // Space In Between Letters 
  
  // Add 5 second pause before emiting the next letter of the 
  // morse code.
  digitalWrite(11, LOW);
  delay(5000);

  // Producing L
  // The letter L in morse is dot, dash, dot, dot.

  // Pinhole-11 -> 5V
  // This will turn on the yellow light.
  // Pinhole-11 will remain on or lit up with 5V throughout the loop
  digitalWrite(11, HIGH);
  delay(1000);
  
  // Pinhole-11 -> 0V
  // Produce the start of the first dot for L
  digitalWrite(11, LOW);
  delay(1000);

  // Pinhole-11 -> 5V
  // Produce the end of the first dot for L
  digitalWrite(11, HIGH);
  delay(1000);

  // Pinhole-11 -> 5V
  // Produce the first dash for L
  digitalWrite(11, HIGH);
  delay(3000);

  // Pinhole-11 -> 0V
  // Produce the start of the second dot for L
  digitalWrite(11, LOW);
  delay(1000);

  // Pinhole-11 -> 5V
  // Produce the end of the second dot for L
  digitalWrite(11, HIGH);
  delay(1000);

  // Pinhole-11 -> 0V
  // Produce the start of the third dot for L
  digitalWrite(11, LOW);
  delay(1000);

  // Pinhole-11 -> 5V
  // Produce the end of the third dot for L
  digitalWrite(11, HIGH);
  delay(1000);

  //Conclusion
  //Turns All Lights Off
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(10000);
  
}
