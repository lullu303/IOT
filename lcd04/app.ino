#include <LiquidCrystal_I2C.h>
#include <Analog.h>
#include <SimpleTimer.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);
Analog temp(A0, 40, -10);
SimpleTimer timer;

byte customChar[] = {
  0x00,
  0x0A,
  0x15,
  0x11,
  0x0A,
  0x04,
  0x00,
  0x00
};

byte high_temp[] = { 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x1E, 0x1E };

byte mid_temp[] = { 0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x1E, 0x1E, 0x1E };

byte low_temp[] = { 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E, 0x1E, 0x1E };

void check() {
    int value =temp.read();
    char buf[17];
    sprintf(buf, "Temp: %3 C", value);
    lcd.setCursor(0,0);
    lcd.print(buf);

    lcd.setCursor(0,1);
    if(value > 25) {
        lcd.write(2);
    } else if(value >0) {
        lcd.write(1);
    } else {
        lcd.write(0);
    }
}

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.createChar(0, low_temp);
    lcd.createChar(1, mid_temp);
    lcd.createChar(2, high_temp);
    timer.setInterval(100, check);

    // lcd.home();     //좌측상단으로 커서 이동
    // lcd.write(0);   //출력
}

void loop() { 
    timer.run();
}
//Open Source web tool By IOXhop