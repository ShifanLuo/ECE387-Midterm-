
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
const int buzzer =5;
void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    int text;
    radio.read(&text, sizeof(text));
    if(text == 1){
       
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  
       Serial.println(text);
    }else{
       Serial.println(text);
    }
   
  }
}
