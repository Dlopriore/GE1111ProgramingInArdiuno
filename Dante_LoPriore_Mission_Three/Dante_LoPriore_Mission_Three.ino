//Dante LoPriore
//September 19, 2022
//Mission 3

//variables will change as they are placeholders for the button
int buttonGreenState = 0;
int buttonYellowState = 0;
int buttonRedState = 0;

//variables for the secret code
int amountofGreenButtonPressed = 2;
int amountofYellowButtonPressed = 1;
int amountofRedButtonPressed = 3;

//variables for user pressing the buttons to attempt secret code
int amountofUserPressedGreenButton = 0;
int amountofUserPressedYellowButton = 0;
int amountofUserPressedRedButton = 0;

// to set pin numbers to the respective button
int buttonGreenPinhole = 3;
int buttonYellowPinhole = 4;
int buttonRedPinhole = 5;

// to set pin numbers to the respective speaker
int speaker = 7;

// to set pin numbers to the respective lights
int redLight = 10;
int greenLight = 11;

void setup() {
  // put your setup code here, to run once:
  
  // Pinhole-3 -> INPUT_PULLUP
  // intializing pinhole 3 or the green button on RedBoard to be an INPUT_PULLUP
  pinMode(buttonGreenPinhole, INPUT_PULLUP);

  // Pinhole-4 -> INPUT_PULLUP
  // intializing pinhole 4 or the yellow button on RedBoard to be an INPUT_PULLUP
  pinMode(buttonYellowPinhole, INPUT_PULLUP);

  // Pinhole-5 -> INPUT_PULLUP
  // intializing pinhole 5 or the red button on RedBoard to be an INPUT_PULLUP
  pinMode(buttonRedPinhole, INPUT_PULLUP);

  // Pinhole-7 -> OUTPUT
  // intializing pinhole 7 or the speaker on RedBoard to be an OUTPUT
  pinMode(speaker, OUTPUT);

  // Pinhole-10 -> OUTPUT
  // intializing pinhole 10 which is the red light on RedBoard to be an OUTPUT
  pinMode(redLight, OUTPUT);

  // Pinhole-11 -> OUTPUT
  // intializing pinhole 11 which is the green light on RedBoard to be an OUTPUT
  pinMode(greenLight, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // initalizes the state of the respective button
  buttonGreenState = digitalRead(buttonGreenPinhole);
  buttonYellowState = digitalRead(buttonYellowPinhole);
  buttonRedState = digitalRead(buttonRedPinhole);

  //checks the amount of times the user pressed the green button
  if(buttonGreenState == LOW) {
    amountofUserPressedGreenButton++;
    tone(speaker, 466, 100);
    delay(500);
  }

  //checks the amount of times the user pressed the yellow button
  if(buttonYellowState == LOW) {
    amountofUserPressedYellowButton++;
    tone(speaker, 466, 100);
    delay(500);
  }

  //checks the amount of times the user pressed the red button
  if(buttonRedState == LOW) {
    amountofUserPressedRedButton++;
    tone(speaker, 466, 100);
    delay(500);
  }

  //determining if the number of button presses equals the amount of buttom pushes for the secret code
  if((amountofUserPressedGreenButton == amountofGreenButtonPressed) && (amountofUserPressedYellowButton == amountofYellowButtonPressed) && (amountofUserPressedRedButton == amountofRedButtonPressed)) {
    // if logic statement is true a song will play and the green light will turn on.
    digitalWrite(greenLight, HIGH);
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
    digitalWrite(greenLight, LOW);
    //reset values 
    amountofUserPressedGreenButton = 0;
    amountofUserPressedYellowButton = 0;
    amountofUserPressedRedButton = 0;
  }

  //determining if the number of user button presses is greater than the amount of buttom pushes required for the secret code
  //decide where for the user to resume input the code or stop and start over.
  if((amountofUserPressedGreenButton > amountofGreenButtonPressed) || (amountofUserPressedYellowButton > amountofYellowButtonPressed) || (amountofUserPressedRedButton > amountofRedButtonPressed)) {
    // if logic statement is true a red light will turn on.
    digitalWrite(redLight, HIGH);
    delay(750);
    digitalWrite(redLight, LOW);
    //reset values 
    amountofUserPressedGreenButton = 0;
    amountofUserPressedYellowButton = 0;
    amountofUserPressedRedButton = 0;
  }
}
