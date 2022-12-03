//led에 pwm 신호 출력하기
const int led_pin =9; //led 연결핀(pwm 출력핀)

void setup()
{
    pinMode(led_pin, OUTPUT); //PWN 출력 핀 출력 방향 설정
    digitalWrite(led_pin,0); //led off
}

void loop() {

    int pwm_val;

    for (pwm_val =0; pwm_val <256; pwm_val +=5) {
        analogWrite(led_pin, pwm_val); //pwm 신호 출력
        delay(100);
    }

    digitalWrite(led_pin, 0); //led off
    delay(2000);              // 2초 대기
}