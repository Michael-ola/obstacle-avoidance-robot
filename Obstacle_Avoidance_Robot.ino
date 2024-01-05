int trigPin = 6; 
int echoPin = 7; 
int motL_A = 2;
int motL_B = 3;
int motR_A = 4;
int motR_B = 5;

long duration;


int state ;
void setup() 
{
   Serial.begin(9600); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

  pinMode(motL_A,OUTPUT);
  pinMode(motL_B,OUTPUT);
  pinMode(motR_A,OUTPUT);
  pinMode(motR_B,OUTPUT);

  digitalWrite(motL_A,LOW);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,LOW);
  digitalWrite(motR_B,LOW);   
}

void loop() 
{
   //Emit USonic
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   
   //Detect USonic
   duration = pulseIn(echoPin, HIGH);
   int distance = duration/29/2;
   Serial.print(distance);
   Serial.println();
   delay(100);
   if ((distance < 6) && (state == 0))
   {
    Serial.println("Right");
    right();
    delay(2000);
    stopp();
    state =1;
   }
   else if((distance < 6) && (state == 1))
   {
    Serial.println("Left");
    left();
    delay(2000);
    stopp();
    state =0;
   }
   else
   {
    Serial.println("Forward");
    forward();
   }
}

void forward()
{
  digitalWrite(motL_A,HIGH);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,HIGH);
  digitalWrite(motR_B,LOW);  
}
void right()
{
  digitalWrite(motL_A,HIGH);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,LOW);
  digitalWrite(motR_B,HIGH);  
}

void left()
{
  digitalWrite(motL_A,LOW);
  digitalWrite(motL_B,HIGH);
  digitalWrite(motR_A,HIGH);
  digitalWrite(motR_B,LOW);  
}
void stopp()
{
  digitalWrite(motL_A,LOW);
  digitalWrite(motL_B,LOW);
  digitalWrite(motR_A,LOW);
  digitalWrite(motR_B,LOW);  
}
