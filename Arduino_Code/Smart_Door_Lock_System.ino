#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>

#define SS_PIN 10
#define RST_PIN 9
#define PIR_PIN 2
#define RELAY_PIN 7
#define EXIT_PIN 6

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS=4,COLS=4;
char keys[ROWS][COLS]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS]={3,4,5,8};
byte colPins[COLS]={A0,A1,A2,A3};
Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

String password="1234";
String input="";
byte AUTHORIZED_UID[4]={0xDE,0xAD,0xBE,0xEF};

void unlockDoor(){
  digitalWrite(RELAY_PIN,HIGH);
  lcd.clear(); lcd.print("Access Granted");
  delay(5000);
  digitalWrite(RELAY_PIN,LOW);
  lcd.clear(); lcd.print("Door Locked");
}

bool checkRFID(){
  if(!rfid.PICC_IsNewCardPresent()) return false;
  if(!rfid.PICC_ReadCardSerial()) return false;
  if(rfid.uid.size!=4) return false;
  for(int i=0;i<4;i++){
    if(rfid.uid.uidByte[i]!=AUTHORIZED_UID[i]){
      lcd.clear(); lcd.print("Access Denied");
      delay(2000);
      rfid.PICC_HaltA();
      return false;
    }
  }
  rfid.PICC_HaltA();
  return true;
}

void setup(){
  pinMode(PIR_PIN,INPUT);
  pinMode(RELAY_PIN,OUTPUT);
  pinMode(EXIT_PIN,INPUT_PULLUP);
  digitalWrite(RELAY_PIN,LOW);
  SPI.begin();
  rfid.PCD_Init();
  lcd.init();
  lcd.backlight();
  lcd.print("SMART DOOR");
  delay(1500);
  lcd.clear();
}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("Scan/Password ");

  if(checkRFID()){
    unlockDoor();
  }

  char key=keypad.getKey();
  if(key){
    if(key>='0' && key<='9'){
      input+=key;
      lcd.setCursor(input.length()-1,1);
      lcd.print("*");
    }else if(key=='#'){
      if(input==password){
        unlockDoor();
      }else{
        lcd.clear(); lcd.print("Wrong Password");
        delay(2000);
      }
      input="";
      lcd.clear();
    }else if(key=='*'){
      input="";
      lcd.clear();
    }
  }

  if(digitalRead(EXIT_PIN)==LOW){
    unlockDoor();
    delay(300);
  }

  if(digitalRead(PIR_PIN)==HIGH){
    lcd.clear();
    lcd.print("Motion Detect");
    delay(1000);
    lcd.clear();
  }
}
