
const int out=3;
const int in=4;
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
int SentMessage = 0;
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(out,OUTPUT);
  pinMode(in,INPUT);
}
void loop() {
  const int TC = 1;
   const int TF = 0;
  long dur;
  digitalWrite(out,LOW);
  delayMicroseconds(2);

  digitalWrite(out,HIGH);
  delayMicroseconds(10);
  digitalWrite(out,LOW);
  dur=pulseIn(in,HIGH);
  delay(200);
   if(dur <500){
    radio.write(&TC, sizeof(TC));
  }else{
   radio.write(&TF, sizeof(TF));
  }
 delay(1000);
  
}
