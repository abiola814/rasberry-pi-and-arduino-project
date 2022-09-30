#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int trigpin = 8;
int echopin = A0;
int trigpin2 = 7;
int echopin2 = 10;

long disa = 0 ,disb =0;
int flag1 =0 ,flag2=0;
int person = 0;
void ultraupdate(int first,int second,long &result) {
long time;
pinMode(first,OUTPUT);
pinMode(second,INPUT);
digitalWrite(first,LOW);
delayMicroseconds(2);
digitalWrite(first,HIGH);
delayMicroseconds(10);
time = pulseIn(second,HIGH);
result = time/29/2;
 }
void setup()      buttonstate2 = digitalRead(buttonPin2);
  // put your setup code here, to run once:
Serial.begin(9600);

lcd.begin(20, 4);
lcd.setCursor(0, 0);
lcd.print("welcome to lasu...");
delay(2000);
lcd.setCursor(0, 1);
lcd.print("starting system.... ");
delay(3000);
lcd.setCursor(0, 2);
lcd.print("50% ready....... ");
delay(3000);
lcd.setCursor(0, 3);
lcd.print("launching.... ");
delay(2000); // Waiting for a while
lcd.clear(); 
}



















void loop() {
  // put your main code here, to run repeatedly:
ultraupdate(trigpin,echopin,disa); delay(30);
ultraupdate(trigpin2,echopin2,disb); delay(30);////
///////////////////////////////////////////////////
Serial.print("da:");Serial.println(disa);
Serial.print("db:");Serial.println(disb);   

if(disa<25 && flag1==0){flag1=1;
if(flag2==0){person = person+1;}
}

if(disb<25 && flag2==0){flag2=1;
if(flag1==0){person = person-1;}
}

if(disa>25 && disb>25 && flag1==1 && flag2==1){
flag1=0, flag2=0;
delay(1000); 
}
lcd.setCursor(0, 0);
lcd.print("counter: ");
lcd.setCursor(10,0); 
lcd.print(person);
lcd.setCursor(0, 2);
lcd.print("sensor 1: ");
lcd.setCursor(10,2); 
lcd.print(disa);
lcd.setCursor(0, 3);
lcd.print("sensor 2: ");
lcd.setCursor(10,3); 
lcd.print(disb);
;



Serial.print("person:");Serial.println(person);
}
