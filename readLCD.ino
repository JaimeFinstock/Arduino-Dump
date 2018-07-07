#include <hd44780.h>
#include <hd44780ioClass/hd44780_pinIO.h>

const int rs=12, rw=A0, en=11, db4=5, db5=4, db6=3, db7=2;

hd44780_pinIO lcd(rs, rw, en, db4, db5, db6, db7);

String a;

void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  lcd.begin(16,2);
  lcd.lineWrap();
}

void loop() {
  int rdata;
  while(Serial.available()) {

    a = Serial.readString();// read the incoming data as string

    Serial.println(a);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.setCursor(0,0);
    
    String lcdString;
    for (int i=0;i<32; i++) {
      rdata = lcd.read();
      lcdString[i] = rdata;
    }

    //Serial.println(rdata);
  }
  if (lcdString!="") Serial.println(lcdString);

}
