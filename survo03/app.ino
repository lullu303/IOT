#include <LiquidCrystal_I2C.h>
#include <Analog.h>
#include <SimpleTimer.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;
Button btn(3);

int b_open = false;
const int servo_pin=5;

void open() {
    b_open = true;
    myServo.write(90);
    lcd.setCursor(0,0);
    lcd.print("open");
}

void close() {
    b_open = false;
    myServo.write(0);

    lcd.setCursor(0,0);
    lcd.print("close ");
}

void check() {
    if(!b_open) open();
    else close();
}

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    btn.setCallback(check);
    myServo.attach(servo_pin);
    close();
}

void loop() {
    btn.check();
}