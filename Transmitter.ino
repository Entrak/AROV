// Assigns buttons to pins on the Arduino Nano
#define Button1 2
#define Button2 3
#define Button3 4
#define Button4 5
#define Button5 6
#define Button6 7
#define Button7 8
#define Button8 9
#define Button9 10

// Set the default value of the state. 1 = button up (not active).
struct State
  {
    bool LHF: 1;
    bool LHR: 1;
    bool RHF: 1;
    bool RHR: 1;
    bool VU: 1;
    bool VD: 1;
    bool SL: 1;
    bool SR: 1;
    bool Light: 1;
  };
  State state;

void setup()  
{
  pinMode(Button1, INPUT_PULLUP); 
  pinMode(Button2, INPUT_PULLUP); 
  pinMode(Button3, INPUT_PULLUP); 
  pinMode(Button4, INPUT_PULLUP); 
  pinMode(Button5, INPUT_PULLUP); 
  pinMode(Button6, INPUT_PULLUP); 
  pinMode(Button7, INPUT_PULLUP); 
  pinMode(Button8, INPUT_PULLUP); 
  pinMode(Button9, INPUT_PULLUP);
  Serial.begin(9600);


}

void loop()
{
  //Reads button state: LOW = Button is pressed, HIGH = Button is not pressed.
  state.LHF   = digitalRead(Button1); //LHF - Button Horizontal Left Thruster Forward
  state.LHR   = digitalRead(Button2); //LHR - Button Horizontal Left Thruster Reverse
  state.RHF   = digitalRead(Button3); //RHF - Button Horizontal Right Thruster Forward
  state.RHR   = digitalRead(Button4); //RHR - Button Horizontal Right Thruster Reverse
  state.VU    = digitalRead(Button5); //VU - Button Vertical Thruster Up
  state.VD    = digitalRead(Button6); //VD - Button Vertical Thruster Down
  state.SL    = digitalRead(Button7); //SL - Button Side Thruster Left
  state.SR    = digitalRead(Button8); //SR - Button Side Thruster Right
  state.Light = digitalRead(Button9); //Light - Light on when LOW, off when HIGH

// Commands to be sent to receiver (onboard unit)

 if       (state.LHF == LOW && state.RHF == LOW)  Serial.println('X');  // Forward (X-axis)
 else if  (state.LHR == LOW && state.RHR == LOW)  Serial.println('x');  // Reverse (-X-axis)
 else if  (state.LHF == LOW && state.RHF == HIGH) Serial.println('A');  // Turn left
 else if  (state.LHF == HIGH && state.RHF == LOW) Serial.println('B');  // Turn right
 else if  (state.VU == LOW && state.VD == HIGH)   Serial.println('Z');  // Ascend (Z-axis)
 else if  (state.VU == HIGH && state.VD == LOW)   Serial.println('z');  // Descend (-Z-axis)
 else if  (state.SL == LOW && state.SR == HIGH)   Serial.println('Y');  // Slide Left (Y-axis)
 else if  (state.SL == HIGH && state.SR == LOW)   Serial.println('y');  // Slide Right (-Z-axis)
 else if  (state.Light == LOW)                    Serial.println('L');  // Lights on
 else {                                           Serial.println('O');} // Use default values
}
