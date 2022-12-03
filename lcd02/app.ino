#include <LiquidCrystal_I2C.h>
#include <Button.h>
#include <SimpleTimer.h>


//set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
Button btn(3);
SimpleTimer timer;


//boolean bBacklight = false;

void backlightOnOff() {
    lcd.noBacklight();
}

void backlightOnOff() { //버튼 처리 핸들러
    lcd.backlight();
    timer.setTimeout(3000, backlightOnOff);
    // bBacklight =!bBacklight;
    // if(bBacklight) {
    //     lcd.backlight();
    // }else {
    //     lcd.noBacklight();
    // }
}


void setup() {
    //pull your setup code here, to run once:
    lcd.init();
    lcd.backlight();
    
    lcd.setCursor(0,0);     //커서 홈(0,0)
    lcd.print("1++++++++23----------45******67########8");      //40문자 저장

    lcd.setCursor(0,1);     //커서 2행 1열(0,1)
    lcd.print("1++++++++23----------45******67########8");      //40문자 저장
}

void loop() {
    //put your main code here, to run repeatedly:
    int n;

    btn.check();
    timer.run();

    // for(n =0; n <80; n++){
    //     lcd.scrollDisplayLeft();    //왼쪽으로 한 칸씩 이동
    //     delay(500);
    // }
    // delay(4000);    //4초 대기

    // for(n=0; n<80; n++) {
    //     lcd.scrollDisplayRight();   //오른쪽으로 한 칸씩 이동
    //     delay(500);
    // }
    // delay(4000);     //4초 대기

}