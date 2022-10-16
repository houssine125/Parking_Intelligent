#include<LiquidCrystal.h>
#include <Servo.h>  // on inclut la bibliothèque servo
Servo servoMoteur;   // on crée un objet servo appelé servoMoteur
static const int servoPin = 9 ;
#define cap 8
#define LEDV 10
#define LEDR 11

LiquidCrystal lcd (1,2,4,5,6,7);
String clavier;


void setup()
{
  lcd.begin(16,2);
  lcd.clear();
 
  
   clavier= String("codeCorrect");
  
  
  pinMode(cap, INPUT);
  pinMode(LEDV, OUTPUT);
  pinMode(LEDR, OUTPUT);

  
  servoMoteur.attach(servoPin);
  servoMoteur.write(0);
  
  
 }


void loop()
{
lcd.clear();
   
    int etat = digitalRead(cap);


    if (etat == HIGH && clavier == "codeCorrect") {
      lcd.setCursor(0,0);
      lcd.print("Access Correct");
      lcd.setCursor(0,1);
      lcd.print("Bienvenue");
      delay(600);
      digitalWrite(LEDV, HIGH);
      digitalWrite(LEDR, LOW);
      servoMoteur.write(90);
      delay(4000);
      servoMoteur.write(0);
    }
   // stringOne = "This";
  //stringTwo = "this";
else if (etat == HIGH &&  clavier.compareTo("codeIncorrect") < 0 ) {
      lcd.setCursor(0,0);
      lcd.print("Code Incorrect");
      lcd.setCursor(0,1);
      lcd.print("Ressayer");
      delay(600);
      digitalWrite(LEDV, LOW);
      digitalWrite(LEDR, HIGH);
      servoMoteur.write(0);
    }

  
 
  
  
  else if (etat == LOW) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Aucun Access");
      lcd.setCursor(0,1);
      digitalWrite(LEDV, LOW);
      digitalWrite(LEDR, LOW);
      servoMoteur.write(0);
  }
  
  delay(1000);


}
