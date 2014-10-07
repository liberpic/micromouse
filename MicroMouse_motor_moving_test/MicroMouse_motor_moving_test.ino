int const LEnablePin=5; // L stands for left
int const LPhasePin=4;
//int count=0;
int const REnablePin=3; // R stands for right
int const RPhasePin=2;

void setup()
{
  pinMode(LEnablePin, OUTPUT);
  pinMode(LPhasePin, OUTPUT);
  //pinMode(7, INPUT);
  //Serial.begin(9600);
  pinMode(REnablePin, OUTPUT);
  pinMode(RPhasePin, OUTPUT);
  //pinMode(7, OUTPUT);
}

void loop()
{
  //int sensorVal = digitalRead(7);
  //if (sensorVal==1)
  //{
  //  count=count+1;
  //}
  //Serial.println(count);
  //if (count<1500)
  //{
  digitalWrite(RPhasePin,0); // Phase controls direction. Possible inputs: 0, 1
  digitalWrite(LPhasePin,0);
  analogWrite(REnablePin,200); // Don't know the the max speed yet, but 200 seems fast
                              // enough. To reach full speed, change the code to
                              // digitalWrite(REnablePin, HIGH);
  analogWrite(LEnablePin,200);
  //}
  //else
  //{
  //  analogWrite(LEnablePin,0);
  //  analogWrite(REnablePin,0);
  //  shutdown();
  //}
}
void shutdown()
{
  // add you emergency shutdown code here
  while(1);  // endless loop
}
