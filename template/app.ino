#include <MiniCom.h>

MiniCom com;

void setup() {
    com.init();
    com.setInterval(1000, check);
}

void loop() {
    com.run();
}