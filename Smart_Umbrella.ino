#include<SoftwareSerial.h>
SoftwareSerial bt(0, 1);
char Incoming_value = 0;
char BUTTON_PIN = 8;
bool pressed = false;
                
void setup() 
{
  
  // Serial.begin(9600);         
  pinMode(13, OUTPUT);    
  pinMode(7, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
  bt.begin(9600); 
}

void loop()
{
    // Sending value to phone...
    // bt.println("loop");
    delay(500);
    bool current_state = digitalRead(BUTTON_PIN); 
    if(current_state == pressed){
    while(digitalRead(BUTTON_PIN) == pressed){
        if(bt.available()==0){     
        bt.println("clicked");
        digitalWrite(7, HIGH);
        delay(2000); 
        }
      }
    }
  
  if(bt.available() > 0)  
  { 
    // Comming from phone...
    Incoming_value = bt.read();      
    bt.println(Incoming_value);                
    if(Incoming_value == '1')             
      digitalWrite(13, HIGH);  
    else if(Incoming_value == '0')       
      digitalWrite(13, LOW);   
    else if(Incoming_value == '3')       
      digitalWrite(7, HIGH);
    else if(Incoming_value == '4')       
      digitalWrite(7, LOW); // comment4
  }
} 
