#include <Servo.h>

#define DIR_L 0x1
#define DIR_R 0x2

#define MIN_D  0
#define MAX_D  160

#define SERVO_PIN 9

Servo servo;
int pos = 80;

byte val;
byte dir;

void setup()
{
    Serial.begin(9600);
    servo.attach(SERVO_PIN);
    servo.write(pos);
}

void loop()
{
    if (Serial.available() > 0) {
        dir = Serial.read();
        val = Serial.read();
		switch(dir) {
			case DIR_L:
				if (pos - val >= MIN_D) {
					pos -= val;
					servo.write(pos);
                                        Serial.print(pos);
				}
				break;
			case DIR_R:
				if (pos + val <= MAX_D) {
					pos += val;
					servo.write(pos);
                                        Serial.print(pos);
				}
				break;
		}
    }
}


