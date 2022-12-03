#pragma once

#include <PWDLed.h>

class ColorLed {
    protected:
        PWMLed red;
        PWMLed green;
        PWMLed blue;
    
    public:
        ColorLed(int red, int green, int blue); //핀번호
        void rgb(int r, int g, int b);  //색상 출력
        void off(int delay_time=0);
        void random();
};