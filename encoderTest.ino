void setup()
{
  pinMode(2, INPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int sensorVal = digitalRead(2);
  int sensorVal2 = digitalRead(4);
  Serial.print(sensorVal);
  Serial.print(" ");
  Serial.println(sensorVal2);
  delay(1);
}
