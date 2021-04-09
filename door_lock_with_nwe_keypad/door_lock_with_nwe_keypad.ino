#include <LiquidCrystal.h>  // library for 16*2 LCD
#include <Servo.h>          // library for servo moter

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // LDC initialisation

Servo s;                                // servo motor initialisation
////////////// varaibles /////////////////////
int keyread=0;
int pin[]={0,0,0,0};
int originalpin[]={1,2,3,4};           // your Pin
int a;

void setup()
{
  s.attach(10);
  lcd.begin(16, 2);
  pinMode(A0,INPUT); 
}

void loop()
{
 lcd.clear();
 for(int i=0;i<=3;i++)
 {
      while(pin[i]==0)
      {
        lcd.setCursor(0,0);
        lcd.print("ENTER PIN:");
        lcd.setCursor(0,1);
        lcd.print("PIN HAS 4 DIGIT");
        lcd.setCursor(10+i,0);
        keypad();  
        pin[i]=a;
      }
   delay(10);
   a=0;
 }
  if(originalpin[0]==pin[0]&&originalpin[1]==pin[1]&&originalpin[2]==pin[2]&&originalpin[3]==pin[3])
  {
     lcd.clear(); 
     lcd.setCursor(0,0);
     lcd.print("ENTER PIN:****");
     lcd.setCursor(2,1);
     lcd.print("CORRECT PIN");
     pin[0]=0;
     pin[1]=0;
     pin[2]=0;
     pin[3]=0;
     for(int j=0;j<=180;j++)
     {
       s.write(j);
       delay(5);
     }
     delay(2000);
     lcd.clear(); 
     while(a==0)
     {
       lcd.setCursor(0,0);
       lcd.print("FOR LOCK A DOOR");
       lcd.setCursor(0,1);
       lcd.print("PRESS:#");
       keypad();
       if(a==35)
       {
         for(int j=180;j>=0;j--)
           {
             s.write(j);
             delay(5);
           } 
       }
     }
     a=0;
  }
  else
  {
     lcd.clear(); 
     lcd.setCursor(0,0);
     lcd.print("ENTER PIN:****");
     lcd.setCursor(1,1);
     lcd.print("INCORRECT PIN");
     delay(3000);
     pin[0]=0;
     pin[1]=0;
     pin[2]=0;
     pin[3]=0;
     a=0;   
  }
}
/////////////////////////////// keypad function //////////////////////////////////
void keypad()
{
   keyread=analogRead(A0);
  
    if(keyread==1023)
    {
      lcd.print("*");
      a=1;
      delay(500);
    }
  
    if(keyread==358)
    {
      lcd.print("*");
      a=2;
      delay(500);
    }
  
    if(keyread==216)
    {
      lcd.print("*");
      a=3;
      delay(500);
    }
  
    if(keyread==98)
    {
      lcd.print("*");
      a=4;
      delay(500);
    }
  
    if(keyread==121)
    {
      lcd.print("*");
      a=5;
      delay(500);
    }
  
    if(keyread==155)
    {
      lcd.print("*");
      a=6;
      delay(500);
    }
  
    if(keyread==83)
    {
      lcd.print("*");
      a=7;
      delay(500);
    }
  
    if(keyread==71)
    {
      lcd.print("*");
      a=8;
      delay(500);
    }
  
    if(keyread==63)
    {
      lcd.print("*");
      a=9;
      delay(500);
    }
  
    if(keyread==50)
    {
      lcd.print("*");
      a=0;
      delay(500);
    }
  
    if(keyread==48)
    { 
      lcd.print("*");
      a='*';
      delay(500);
    }
  
    
    if(keyread==56)
    {
      lcd.print("*");
      a='#';
      delay(500);
    }
}
