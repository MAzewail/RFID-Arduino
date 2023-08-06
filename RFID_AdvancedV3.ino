#include <RFID.h>

RFID rfid(10,9);
const byte savedID[5]={105,89,11,01,45};
const byte mySer[2][5]={
  {69, 216, 55, 40, 130},
  {218, 199, 40, 64, 117}
};
byte error_counts=0;
void setup() {
Serial.begin(9600);
SPI.begin();
rfid.init();
}

void loop() {
 if(rfid.isCard()){
  if(rfid.readCardSerial()){
    error_counts=0;
    for(byte j=0;j<2;j++)
    for(byte i =0;i<5;i++)
    if(rfid.serNum[i]== mySer[j][i] )error_counts++;
    if(error_counts<5){
    Serial.println("Wrong Card");
   }
   else {
    Serial.println("Welcome!");
   }
  }
   else {
  Serial.println("Not a Card");
 }
 }

}
