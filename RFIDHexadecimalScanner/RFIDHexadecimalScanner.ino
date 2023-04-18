/*------------------------------------------------------------------
This is a sample code for RDM630 RFID reader by Spekel(Spekel.se)
This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-nc-sa/3.0/
-------------------------------------------------------------------*/
#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1
char code[20];
int val = 0;
int bytesread = 0;
//------------------------------------
//create a Serial object RFID
SoftwareSerial RFID= SoftwareSerial(rxPin, txPin);

void setup()
{
  Serial.begin(9600);
  Serial.println("Serial Ready");
  RFID.begin(9600);
  Serial.println("RFID Ready");
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}
void loop()
{
  val = 0;
  bytesread = 0;

  while(bytesread < 12)
  {
    // read 12 digit code
    val = RFID.read();
    if(val == 3)
    { // if header or stop bytes before the 10 digit reading
      break; // stop reading
    }

    if(val != 2)
    {
      code[bytesread] = val; // add the digit
      bytesread++; // ready to read next digit
      code[bytesread] = '\0'; // add the NULL
    }
  }

  if(bytesread >= 12)
  { // if 12 digit read is complete
    Serial.print("Tag: [");
     delay(3000);
    for(int i=0; code[i]!='\0' ; i++)
    {
      Serial.print(code[i]);
    }
    Serial.println("]"); //print the whole 13 bytes
  }
  
  delay(3000);
}
