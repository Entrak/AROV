//Button input for one engine with PWM control

#define PWM1 11 //PWM Left Front Horizontal Thruster
#define PWM2 9  //PWM Left Rear VerticalThruster
#define PWM3 4  //PWM Right Rear Horizontal Thruster
#define PWM4 2  //PWM Right Right Thruster
#define DIR1 10 //Dir Left Horizontal
#define DIR2 8  //Dir Left Vertical
#define DIR3 5  //Dir Right Horizontal
#define DIR4 3  //Dir Right Slide
#define LIGHT 7 //Lights

int pwm_val = 100; //PWM max value (Add Variable resistor as control?)
bool Light_state = HIGH;

void setup()
{
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PWM3, OUTPUT);
  pinMode(PWM4, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(DIR3, OUTPUT);
  pinMode(DIR4, OUTPUT);
  pinMode(LIGHT, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available())
  {
    int value;
    const char command = Serial.read();
    // Commands using lower case letters have an argument:
    // if ( islower(command) ) value = Serial.parseint();
    switch (command)
    {
      case 'O':
        analogWrite(PWM1, 0);
        analogWrite(PWM2, 0);
        analogWrite(PWM3, 0);
        analogWrite(PWM4, 0);
        analogWrite(LIGHT, Light_state);
        break;
        
      case 'A':
        digitalWrite(DIR1, 0);
        digitalWrite(DIR3, 1);
        analogWrite(PWM1, pwm_val);
        analogWrite(PWM3, pwm_val);
        break;
        
      case 'B':
        digitalWrite(DIR1, 1);
        digitalWrite(DIR3, 0);
        analogWrite(PWM1, pwm_val);
        analogWrite(PWM3, pwm_val);
        break;

      case 'X':
        digitalWrite(DIR3, 1);
        digitalWrite(DIR1, 1);
        analogWrite(PWM1, pwm_val);
        analogWrite(PWM3, pwm_val);
        break;

      case 'x': 
        digitalWrite(DIR3, 0);
        digitalWrite(DIR1, 0);
        analogWrite(PWM1, pwm_val);
        analogWrite(PWM3, pwm_val);
        break;
      
      case 'Z':
        digitalWrite(DIR2, 1);
        analogWrite(PWM2, pwm_val);
        break;
      
      case 'z':
        digitalWrite(DIR2, 0);
        analogWrite(PWM2, pwm_val);
        break;
      
      case 'Y':
        digitalWrite(DIR4, 1);
        analogWrite(PWM4, pwm_val);
        break;
      
      case 'y':
        digitalWrite(DIR4, 1);
        analogWrite(PWM4, pwm_val);
        break;

      case 'L':
        Light_state = !Light_state;
        break;
    }
  }
}
