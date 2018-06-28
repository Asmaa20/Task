//switch
const int button =2;
int buttonState;
const int led =8;
char state;

//temprature 
float temp;
int tempPin = A1;

void temprature()
{
  temp = analogRead(tempPin);
  Serial.print("RAW DATA: ");
  Serial.print (temp);
  Serial.println(" ");
  temp = temp * 0.48828125;
  Serial.print("CELSIUS: ");
  Serial.print(temp);
  Serial.println("*C ");
  //converts celsius into fahrenheit 
  temp = temp *9 / 5;
  temp = temp + 32;
  Serial.print("FAHRENHEIT: ");
  Serial.print(temp);
  Serial.println("*F");
  delay(1000);
}

  void ON_OFF_Switch()
{
  buttonState= digitalRead(button);
  if(buttonState==LOW)
  {
    Serial.println("Pressed");
    Serial.println("Led is ON");
    digitalWrite(led ,HIGH);
    //delay(1000);
  }
   else
  {
    Serial.println("Led is OFF");
    digitalWrite(led,LOW);
    delay(1000);
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(button,HIGH);
  digitalWrite(led,LOW);
}

void loop() 
{
 // put your main code here, to run repeatedly:
 ON_OFF_Switch();
 temprature();
}
