#include <MiniCom.h>
#include <Led.h>
#include <Server.h>

MiniCom com;
Led led(9);
Servo servo;

int pir_pin = 7;
int pirState = LOW;
int val = 0;

void setup() {
    com.init();
    com.print(0, "[[Motion]]");
    pinMode(pir_pin, INPUT);
    servo.attach(5);
    servo.write(0);
}

void loop() {
  com.run();
    val = digitalRead (pir_pin);
    if(val == HIGH) {
        if(pirState == LOW) {
            com.print(1, "Motion detected!");
            pirState = HIGH;
            led.on();
            servo.write(90);
        } 
    } else {
        if(pirState == HIGH) {
            com.print(1, "Motion ended!");
            pirState = LOW;
            led.off();
            servo.write(0);
        }
    }
     //led.setValue(val);
}