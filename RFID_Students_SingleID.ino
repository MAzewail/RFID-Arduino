#include <RFID.h>

RFID rfid(10,9);
const byte mySer[2][5]={69, 216, 55, 40, 130};
bool error_flag=0;
void setup() {
Serial.begin(9600);
SPI.begin();
rfid.init();
}

void loop() {
 if(rfid.isCard()){
  if(rfid.readCardSerial()){
    for(byte i =0;i<5;i++)
    if(rfid.serNum[i]!= mySer[i] ){error_flag=1;break;}
    if(error_flag){
    Serial.println("Wrong Card");
    error_flag=0;
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
