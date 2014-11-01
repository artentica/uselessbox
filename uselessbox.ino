const int buttonPin = 2;     // the number of the pushbutton pin
int led = 13;      // the number of the LED pin
int leve = 0;
int i = 0;
int pos=0;
int autoleve = 1;
int buttonState = 0;         // variable for reading the pushbutton status
int proximityState = 0;
int buzzer_pin = 3; //pin analogic of the buzzer
int proximity_detector = 6;
//pin à définir
int led_flag_pin=00;
int led_1_pin=00;
int led_2_pin=00;
int led_3_pin=00;
int led_4_pin=00;
int time=0;

#include <Servo.h>
Servo monservo;
Servo monservoflag;

void setup() {
  Serial.begin(9600);
  // initialize the digital pin as an output.
     monservo.attach(9);  
     
   monservo.write(0); 
  monservoflag.attach(12);  
  monservoflag.write(0); 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);    
  pinMode(proximity_detector, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led_flag_pin, OUTPUT);
  pinMode(led_1_pin, OUTPUT);
  pinMode(led_2_pin, OUTPUT);
  pinMode(led_3_pin, OUTPUT);
  pinMode(led_4_pin, OUTPUT);
  
  digitalWrite(led_1_pin, LOW);
  digitalWrite(led_2_pin, LOW);
  digitalWrite(led_3_pin, LOW);
  digitalWrite(led_4_pin, LOW);
      
}





void loop(){

      // read the state of the pushbutton value:
      buttonState = digitalRead(buttonPin);
      proximityState = digitalRead(proximity_detector);
      
    
      // check if the pushbutton is pressed.
      // if it is, the buttonState is HIGH:
      if (buttonState == HIGH) {    //Bouton actionné
        if(leve<=3)monservo.write(90);
        
        if(leve == 4){
          monservo.write(70);
          while(proximityState == HIGH){//détecteur de proximité ne détecte rien
             digitalWrite(led_1_pin, HIGH);
             delay(300);
             digitalWrite(led_1_pin, LOW);
             if(digitalRead(proximity_detector) == LOW){ break;}
             
             digitalWrite(led_2_pin, HIGH);
             delay(300);
             digitalWrite(led_2_pin, LOW);
             if(digitalRead(proximity_detector) == LOW) break;
             
             digitalWrite(led_3_pin, HIGH);
             delay(300);
             digitalWrite(led_3_pin, LOW);
             if(digitalRead(proximity_detector) == LOW) break;
             
             digitalWrite(led_4_pin, HIGH);
             delay(300);
             digitalWrite(led_4_pin, LOW);
             if(digitalRead(proximity_detector) == LOW) break;
             proximityState = digitalRead(proximity_detector);
          }
          flash(250);
          monservo.write(90);  
        }
        
        if(leve >=8 && leve <=10){
           monservo.write(60);
           tremblesort();
           flash(150);
           monservo.write(90);
        }       
        
        if(leve == 11){
            monservo.write(65);
            delay(300);
            flash(200);
            monservo.write(45);
            delay(700);
  
            monservo.write(65);
            delay(500);
            flash(200);
            monservo.write(45);
            delay(600);
            
            monservo.write(65);
            delay(800);
            flash(200);
            monservo.write(45);
            delay(200);
            
            monservo.write(90);
        }
        
        if(leve == 12){
          for(pos = 0; pos<=90; pos+=1)     // goes from 180 degrees to 0 degrees 
            {                                
              monservo.write(pos);              // tell servo to go to position in variable 'pos' 
              delay(15);                       // waits 15ms for the servo to reach the position 
            } 
        }
        
        if(autoleve==1){
          leve++; 
        }
        autoleve = 0;  
      }
      
      
      if(leve >=5 && leve <=7){
        delay(600);
        monservo.write(60);
        while(proximityState == HIGH){//détecteur de proximité ne détecte rien
             digitalWrite(led_1_pin, HIGH);
             delay(300);
             digitalWrite(led_1_pin, LOW);
             if(digitalRead(proximity_detector) == LOW){ break;}
             
             digitalWrite(led_2_pin, HIGH);
             delay(300);
             digitalWrite(led_2_pin, LOW);
             if(digitalRead(proximity_detector) == LOW) break;
             
             digitalWrite(led_3_pin, HIGH);
             delay(300);
             digitalWrite(led_3_pin, LOW);
             if(digitalRead(proximity_detector) == LOW) break;
             
             digitalWrite(led_4_pin, HIGH);
             delay(300);
             digitalWrite(led_4_pin, LOW);
             if(digitalRead(proximity_detector) == LOW) break;
             proximityState = digitalRead(proximity_detector);
          }
        monservo.write(0);
        leve++;
      }
      
      
      if (buttonState == LOW) {    //Bouton repoussé
        if(leve<3)monservo.write(0);
        
        if(leve ==3){
          monservo.write(70);
          delay(1000);
          monservo.write(0);
        }
        
        if(leve == 4){
          monservo.write(0);
        }
        
        if(leve >=8 && leve <=10){
           tremblerentre();
           flash(200);
           monservo.write(0);
        }
        
        if(leve == 11){
          monservo.write(0);
        }
        
        if(leve == 12){
          for(pos = 90; pos>=65; pos-=1)     // goes from 180 degrees to 0 degrees 
          {                                
            monservo.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 
          buzz();
          givingup();
          
          flash(500);
          
          monservo.write(0);
          
          leve = 0;
        }
        delay(150);
        autoleve = 1;
      }
      
  }
  
  
 void tremblesort(){
    for(i=0;i<=7;i++){
      monservo.write(65);
      monservo.write(60);
    }
    monservo.write(80);
    for(i=0;i<=4;i++){
      monservo.write(70);
      monservo.write(75);
    }
 }
 
 void tremblerentre(){
    monservo.write(60);
    for(i=0;i<=4;i++){
      monservo.write(65);
      monservo.write(60);
    }
 }
  
 void givingup(){
   for(i=0; i<=4; i++){
    monservoflag.write(120);
    digitalWrite(led_flag_pin, HIGH);
    delay(400);
    digitalWrite(led_flag_pin, LOW);
    delay(400);
    monservoflag.write(60);
    digitalWrite(led_flag_pin, HIGH);
    delay(400);
    digitalWrite(led_flag_pin, LOW);
    delay(400);
   }
 }
 
 void buzz(){
   for(i=0; i<=6; i++){
        analogWrite(buzzer_pin, 200);      // Almost any value can be used except 0 and 255
        flash(300);
        analogWrite(buzzer_pin, 0);      // Almost any value can be used except 0 and 255
        delay(200);
    }
 }
  
  void flash(int time){
          digitalWrite(led_1_pin, HIGH);
          digitalWrite(led_2_pin, HIGH);
          digitalWrite(led_3_pin, HIGH);
          digitalWrite(led_4_pin, HIGH);
          delay(time);
          digitalWrite(led_1_pin, LOW);
          digitalWrite(led_2_pin, LOW);
          digitalWrite(led_3_pin, LOW);
          digitalWrite(led_4_pin, LOW);
  }
