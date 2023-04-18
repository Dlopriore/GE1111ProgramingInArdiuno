//Dante LoPriore
//James Altham
//Project Lockdown Program
//December 7, 2022


#include <Servo.h>
#include <Keypad.h>

//initialize amount of rows and columns for the keypad
const byte ROWS = 4; 
const byte COLS = 4; 

//initialize locks for the components used for the alarm sequence and audio feedback
const int sensorlock = A0; 
int speaker = 12;
const int threshold = 100;
const int closedBoxThreshold = 15;

//creates servo object to control a servo
Servo myservo;
int angle=0;
String state = "locked";


//to represent the buttons that can be seen on the keypad using an arraylist of an arraylist
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'0', 'F', 'E', 'D'}
};

//initialize the locks for the keypad 
//locks 2-5 represent the rows
//locks 6-9 represent the columns
byte rowlocks[ROWS] = {5, 4, 3, 2}; //connect to the row lockouts of the keypad
byte collocks[COLS] = {9, 8, 7, 6}; //connect to the column lockouts of the keypad

//to represents the keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowlocks, collocks, ROWS, COLS);

//max attempts a user can have
int maxAttempts = 3;

//allowed attempts for a user
int attempts = 0;

//stored correct password
String correctPassword = "1234";
String lockedPassword = "567";

//initialize user's response
String userResponsePassword;

//obtains the photoresistor reading based on the light input from the box being opened or closed. 
int reading; 

void setup(){
  //sets the components to there respective modes to start the program 
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
  pinMode(sensorlock, INPUT); 

  //attaches the servo on lock 10 to the servo object
  myservo.attach(10);
  myservo.write(-20);
  delay(5000);
  
  for (angle=0; angle<=45; angle+=1) //goes from 0 to 45 degrees
  {
    myservo.write(angle); //moves servo back in opposite direction
    delay(20); //waits 20ms between servo commands
   } 
 
}
  
void loop(){
  int lock = 0; // baseline with no passcode input, nothing should happen
// if correct lock entered, lock = 1
// if incorrect lock, lock = 0
// if closing lock entered correct, lock = 2 and mechanism locks
// if closing lock incorrect, lock remains open

  // measure the voltage coming from the photoresistor 
  reading = analogRead(sensorlock);

  //to represent the user's single key press
  char customKey = customKeypad.getKey();

  //deteremines whether the box was opened or closed when the password was not inputed
  //this acts as the alarm system where the photoresistor checks the light input to see 
  //if the box was opened or closed based on the thresholds that was set
  if(reading >= threshold && state == "locked") 
  { 
    //the alarm starts playing a loud noise until the program is terminated.
     pinMode(speaker, OUTPUT);
     for(int i=0; i<100; i++) { //do this 155 times
      tone(speaker, 466, 100); 
      delay(100); //wait 100 milliseconds to repeat 
     }
  } 
  
  //to determined if the user pressed a key on the keypad
  if (customKey){
    //displays the user's key press on the console
    Serial.println(customKey);
    
    //to determine which button the user pressed
    //add the single character to the user's response to the password.
        if(customKey == '1') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 1;
        }
        if(customKey == '2') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 2;
        }
        if(customKey == '3') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 3;
        }
        if(customKey == '4') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 4;
        }
        if(customKey == '5') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 5;
        }
        if(customKey == '6') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 6;
        }
        if(customKey == '7') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 7;
        }
        if(customKey == '8') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 8;
        }
        if(customKey == '9') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 9;
        }
        if(customKey == '0') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 0;
        }
        if(customKey == 'A') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 'A';
        }
        if(customKey == 'B') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 'B';
        }
        if(customKey == 'C') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 'C';
        }
        if(customKey == 'D') {
          tone(speaker, 477, 10); 
          userResponsePassword = userResponsePassword + 'D';
        }
        //to represent an enter key where the user's submits there response 
        //to be checked whether the sumbition of the password is right or wrong
        //to represent the locking button
        if(customKey == 'E') {
          //to represent the locking mechanism and reading <= closedBoxThreshold
          if(correctPassword == userResponsePassword && reading <= closedBoxThreshold && state == "unlocked") {
            for (angle=90; angle>=45; angle-=1) //goes from 45 to 0 degrees
            {
              myservo.write(angle); //moves servo back in opposite direction
              delay(20); //waits 20ms between servo commands
            }
            //changes state to locked
            state = "locked";
            Serial.println("Locked");
           }
           //resets password
           userResponsePassword = "";
         }
        
        //to represent an enter key where the user's submits there response 
        //to be checked whether the sumbition of the password is right or wrong
        //to represent the unlocking button
        if(customKey == 'F') {
          
          //displays the user's submition on the console
          Serial.println(userResponsePassword);

          //to determine where the user's submittion is the password  && reading <= closedBoxThreshold
          if(correctPassword == userResponsePassword && reading <= closedBoxThreshold && state == "locked") {
            //correct answer
            Serial.println("Correct");
              tone(speaker, 300, 50);
              delay(20);
              tone(speaker, 350, 50);
              delay(20);
              tone(speaker, 300, 50); 
              delay(20);
            
            //to represent the unlocking mechanism
            for (angle=45; angle<90; angle+=1) {
                //goes from 0 to 45 degrees in steps of 1 degree
                myservo.write(angle); //directs servo to go to position in variable 'angle'
                delay(20);
                //waits 20ms between servo commands
              }
              Serial.println("Unlocked");
              //resets password and changes state to unlocked
              state = "unlocked";
              userResponsePassword = "";
            }
          else{
            Serial.println("Wrong Password");
            //adds the numbers attempts by one
            attempts = attempts + 1;
            //wrong answer sound
            tone(speaker, 10000,500);
            delay(1000);

            //to determine if the user reached max attempts
            if(attempts >= maxAttempts) {
              //initialize the alarm sequence 
              Serial.println("Better Luck Next Time");
              pinMode(speaker, OUTPUT);
              for(int i=0; i<100; i++) { //do this 100 times
                tone(speaker, 466, 100); //raise the voltage sent out of the lock by 1
                delay(100); //wait 100 milliseconds to repeat 
              }
            }
            delay(100);
          }
          //resets password
          userResponsePassword = "";
        }
  }
}
