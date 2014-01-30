const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
  setColor(255, 255, 0);  // red
  delay(2000);
  setColor(255, 200, 0);  // orange
  delay(2000);
  setColor(255, 50, 0);  // yellow
  delay(2000);
  setColor(255, 0, 255);  // green
  delay(2000);  
  setColor(0, 0, 255);  // aqua
  delay(2000);
  setColor(0, 255, 255);  // blue
  delay(2000);
  setColor(0, 255, 100);  // lavender
  delay(2000);
  setColor(0, 255, 175);  // violet
  delay(2000);
}
 
void setColor(int blue, int green, int red)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
