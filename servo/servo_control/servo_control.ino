#include <Servo.h>

#define DIR_L 0x1
#define DIR_R 0x2

#define MIN_D  0
#define MAX_D  160

#define SERVO_PIN 9

#define ERROR_DIR -1
#define ERROR_OFFSET -2


Servo servo;
int pos = 80;
byte val = 0;
byte dir = 0;
char buf[2];

void setup()
{
    Serial.begin(9600);
    servo.attach(SERVO_PIN);
    servo.write(pos);
}

void loop()
{
    if (Serial.available() > 0) {
        Serial.readBytes(buf,2);
        dir = byte(buf[0]);
        val = byte(buf[1]);
        //Serial.println(dir);
        //Serial.println(val);
       
		switch(dir) {
			case DIR_L:
				if (pos - val >= MIN_D) {
					pos -= val;
					servo.write(pos);

                    //Serial.write(pos);
				} 
				break;
			case DIR_R:
				if (pos + val <= MAX_D) {
					pos += val;
					servo.write(pos);

                    //Serial.write(pos);
				}
				break;
            default:
                //Serial.write(ERROR_DIR);
                break;
		}
    }
}


