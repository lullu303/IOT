const int var_pin =A0; //가변저항 연결핀
int analog_val; //아날로그 값 저장 변수

void setup() {
    Serial.begin(115200);
}
void loop() {
    int digital_val;
    float ff;

    digital_val =analogRead(var_pin);   //아날로그 값 디지털 변환
    ff = (float)digital_val /1023. * 5.0;   //전압값 계산

    Serial.print("Input Voltage(0~5V) = ");
    Serial.print(ff);   //입력 전압값 출력(0~5v)

    Serial.print("Digital Value(0~1023) = ");
    Serial.println(digital_val);    //변환된 디지털 값 출력(0~1023)
    Serial.println("-----------------------------------------------------------");

    delay(2000);
}