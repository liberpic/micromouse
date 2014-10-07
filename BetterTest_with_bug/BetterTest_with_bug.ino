#define echoPin 13 // Echo Pin
#define trigPin 12 // Trigger Pin

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int const RPWMPin=9;
int const RIn2=8;
int const RIn1=7;
int const LIn1=2;
int const LPWMPin=3;      
int const LIn2=4;
int const REncoderPin=5;
int const LEncoderPin=6;

//int const ir_left = A0;
int const ir_right = A1;

int Lcount=0;
int Rcount=0;

void front_distancer() {
    
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  
 
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
 
  if (distance >= maximumRange || distance <= minimumRange){
  /* Send a negative number to computer and Turn LED ON 
  to indicate "out of range" */
//  Serial.println("-1");
  }
  else {
  /* Send the distance to the computer using Serial protocol, and
  turn LED OFF to indicate successful reading. */
  Serial.println(distance);
}
 //Delay 50ms before next reading.
 delay(50);
}

//void side_ir_distancer() {
//  int ir_left;
//  int ir_right;
//  
//}


void go() {
  int LsensorVal = digitalRead(LEncoderPin);
  if (LsensorVal==1)
  {
    Lcount=Lcount+1;
  }
//  Serial.println(Lcount);
//  if (count<1500)
//  {
    digitalWrite(RIn1,LOW); 
    digitalWrite(RIn2,HIGH);
    digitalWrite(LIn1,HIGH); 
    digitalWrite(LIn2,LOW);
    analogWrite(RPWMPin,50); 
    analogWrite(LPWMPin,50);
//  }
}

//void irRead_left() { 
//  int result = analogRead(ir_left);
//  //Serial.println(result);
//  delay(50);
//}

void irRead_right() { 
  int result = analogRead(ir_right);
  //Serial.println(result);
  delay(50);
}

void setup()
{
  
//  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(LPWMPin, OUTPUT);
  pinMode(RPWMPin, OUTPUT);
  pinMode(RIn2, OUTPUT);
  pinMode(RIn1,OUTPUT);
  pinMode(LIn2, OUTPUT);
  pinMode(LIn1, OUTPUT);
  pinMode(REncoderPin, INPUT);
  pinMode(LEncoderPin, INPUT);
  
//  pinMode(ir_left, INPUT);
  pinMode(ir_right, INPUT);
}

void loop()
{
  


//  irRead_left();
  irRead_right();
//  front_distancer();
  go();
}
