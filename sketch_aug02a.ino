int trigPin = 11;      // trig pin of HC-SR04
int echoPin = 12;     // Echo pin of HC-SR04
int revleft2 = 2;       //REVerse motion of Left motor
int fwdleft3 = 3;       //ForWarD motion of Left motor
int revright4 = 4;      //REVerse motion of Right motor
int fwdright5 = 5;      //ForWarD motion of Right motor
long duration, distance;
void setup(){ 

pinMode(revleft2, OUTPUT);      // set Motor pins as output
pinMode(fwdleft3, OUTPUT);
pinMode(revright4, OUTPUT);
pinMode(fwdright5, OUTPUT); 
pinMode(trigPin, OUTPUT);         // set trig pin as output
pinMode(echoPin, INPUT);   
Serial.begin(9600);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); // send waves for 10 us 
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH); // receive reflected waves
distance = duration / 58.2;   // convert to distance
delay(10);
if (distance > 19)            
            {
            digitalWrite(fwdright5, HIGH);    // move forward
            digitalWrite(revright4, LOW);
            digitalWrite(fwdleft3, HIGH);                                
            digitalWrite(revleft2, LOW);                                                       
            }
            if (distance < 18)
             {
             digitalWrite(fwdright5, LOW);  //Stop                
             digitalWrite(revright4, LOW);
             digitalWrite(fwdleft3, LOW);                                
             digitalWrite(revleft2, LOW);
             delay(500);
             digitalWrite(fwdright5, LOW);  //movebackword         
             digitalWrite(revright4, HIGH);
             digitalWrite(fwdleft3, LOW);                                
             digitalWrite(revleft2, HIGH);
             delay(500);
             digitalWrite(fwdright5, LOW);  //Stop                
             digitalWrite(revright4, LOW);
             digitalWrite(fwdleft3, LOW);                                
             digitalWrite(revleft2, LOW);  
             delay(100);  
             digitalWrite(fwdright5, HIGH);       
             digitalWrite(revright4, LOW);   
             digitalWrite(revleft2, LOW);                                 
             digitalWrite(fwdleft3, HIGH);  
             delay(500);
            }
  int smoke=analogRead(7);
  Serial.print("The intensity of smoke is ");
  Serial.println(smoke);

         if(smoke>200)
         {
          Serial.println("\\smoke detected\\");
         }   
         }
