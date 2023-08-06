#include <RFID.h>

RFID rfid(10,9);
const byte savedID[5]={105,89,11,01,45};
const byte mySer[2][5]={
  {69, 216, 55, 40, 130},
  {218, 199, 40, 64, 117}
};
byte error_counts=0,i=0;
void setup() {
Serial.begin(9600);
SPI.begin();
rfid.init();
}

void loop() {
 if(rfid.isCard()&&rfid.readCardSerial()){
    error_counts=0;
  }
    if(rfid.serNum[i%5]== *(*mySer+(i%10)) )error_counts++;
    Serial.println((error_counts<5)?"Wrong Card":"Welcome!");
    i++;
 }
