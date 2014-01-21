const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

int redAmount = 0;
int greenAmount = 0;
int blueAmount = 0;
const int fadeAmount = 5;

const int serialPin = 0;
const int threshold = 249;

void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
resetLoop:
  Serial.println(analogRead(serialPin)/4);
  
  if ((analogRead(serialPin)/4) >= threshold)
  {
    // Initialize redLed fade before multicolour fade loop.
    
    while (redAmount < 255)
    {
      if ((analogRead(serialPin)/4) < threshold)
      {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
        goto resetLoop;
      }
      redAmount += fadeAmount; // Increment by fadeAmount
      analogWrite(redPin, redAmount); // Write value to LED
      delay(30); // Wait 30 nanoseconds
    }
    
    // Start of multicolour fade loop.
    while ((analogRead(serialPin)/4) >= threshold) // Loop forever
    {    
      // Fade greenLed on to max value.
      
      while (greenAmount < 255)
      {
        if ((analogRead(serialPin)/4) < threshold)
        {
          analogWrite(redPin, 0);
          analogWrite(greenPin, 0);
          analogWrite(bluePin, 0);
          break;
        }
        greenAmount += fadeAmount; // Increment by fadeAmount
        analogWrite(greenPin, greenAmount); // Write value to LED
        delay(30); // Wait 30 nanoseconds
      }
      
      // Fade redLed off to minimum value and 0 it out to be sure.
      
      while (redAmount > 0)
      {
        if ((analogRead(serialPin)/4) < threshold)
        {
          analogWrite(redPin, 0);
          analogWrite(greenPin, 0);
          analogWrite(bluePin, 0);
          break;
        }
        redAmount -= fadeAmount; // Decrement by fadeAmount
        analogWrite(redPin, redAmount); // Write value to LED
        delay(30); // Wait 30 nanoseconds
      }
      redAmount = 0; // zero it out
      
      // Fade blueLed on to max value.
      
      while (blueAmount < 255)
      {
        if ((analogRead(serialPin)/4) < threshold)
        {
          analogWrite(redPin, 0);
          analogWrite(greenPin, 0);
          analogWrite(bluePin, 0);
          break;
        }
        blueAmount += fadeAmount; // Increment by fadeAmount
        analogWrite(bluePin, blueAmount); // Write value to LED
        delay(30); // Wait 30 nanoseconds
      }
      
      // Fade greenLed off to minimum value and zero it out to be sure.
      
      while (greenAmount > 0)
      {
        if ((analogRead(serialPin)/4) < threshold)
        {
          analogWrite(redPin, 0);
          analogWrite(greenPin, 0);
          analogWrite(bluePin, 0);
          break;
        }
        greenAmount -= fadeAmount; // Decrement by fadeAmount
        analogWrite(greenPin, greenAmount); // Write value to LED
        delay(30); // Wait 30 nanoseconds
      }
      greenAmount = 0; // 0 it out
      
      // Fade redLed on to max value.
      
      while (redAmount < 255)
      {
        if ((analogRead(serialPin)/4) < threshold)
        {
          analogWrite(redPin, 0);
          analogWrite(greenPin, 0);
          analogWrite(bluePin, 0);
          break;
        }
        redAmount += fadeAmount; // Increment by fadeAmount
        analogWrite(redPin, redAmount); // Write value to LED
        delay(30); // Wait 30 nanoseconds
      }
      
      // Fade blueLed off to minimum value and 0 it out to be sure.
      
      while (blueAmount > 0)
      {
        if ((analogRead(serialPin)/4) < threshold)
        {
          analogWrite(redPin, 0);
          analogWrite(greenPin, 0);
          analogWrite(bluePin, 0);
          break;
        }
        blueAmount -= fadeAmount; // Decrement by fadeAmount
        analogWrite(bluePin, blueAmount); // Write value to LED
        delay(30); // Wait 30 nanoseconds
      }
      blueAmount = 0; // 0 it out
    }
    
  }

}
