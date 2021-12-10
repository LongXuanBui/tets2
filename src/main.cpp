#include <Arduino.h>
#include "SoftwareSerial.h"
#include <string.h>

#define MYPORT1_TX 26
#define MYPORT1_RX 14
// #define MYPORT2_TX 32
// #define MYPORT2_RX 25
String s;
int Value;

SoftwareSerial myPort1;
SoftwareSerial myPort2;
int a =2;
//  SoftwareSerial mySerial1(14,26); // Rx, TX
//  SoftwareSerial mySerial2(25,32); 
  const int DE1=27;
  const int DE2=33;
  char rdata;
void setup() {
Serial.begin(115200);
myPort1.begin(9600, SWSERIAL_8N1, MYPORT1_RX, MYPORT1_TX, false);
//myPort2.begin(115200, SWSERIAL_8N1, MYPORT2_RX, MYPORT2_TX, false);
  pinMode(27,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(18,OUTPUT);
  digitalWrite(27, HIGH);
  delay(1000);
  if(myPort1.available() == 0)
  {
    myPort1.print('a');
    delay(100);
  }
digitalWrite(27, LOW);
// digitalWrite(33, LOW);
digitalWrite(18, LOW);
Serial.println("hihi");
}

void loop() {
 if (myPort1.available() > 0 ) 
  {
   char rdata = myPort1.read(); 
    s +=rdata;
    Serial.print(rdata);
    if( rdata == '\n')
    {Value = s.toInt();
    s= "";
// end new code
    }
  }
}