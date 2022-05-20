#include <SoftwareSerial.h>
#define BTTX 9
#define BTRX 10
#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    3

#define LED_PIN_2     7
#define NUM_LEDS_2    3

#define LED_PIN_3     8
#define NUM_LEDS_3    3


CRGB leds[NUM_LEDS];
CRGB leds_2[NUM_LEDS_2];
CRGB leds_3[NUM_LEDS_3];
SoftwareSerial SerialBT(BTTX, BTRX); 
unsigned long minutes = 60000;
unsigned long previousMillis = 0;
unsigned long runTime = 0;

// replace the every "Serial" with "SerialBT" and delete serial monitor initialization
// everything right now kills itself after one minute instead of the 30 minutes like we are intending

void setup() {
  // put your setup code here, to run once:

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); // define signal pins
  FastLED.addLeds<WS2812, LED_PIN_2, GRB>(leds_2, NUM_LEDS_2);
  FastLED.addLeds<WS2812, LED_PIN_3, GRB>(leds_3, NUM_LEDS_3);
  
  pinMode(5,OUTPUT); // set pin 5 to output

  // bluetooth setup
  SerialBT.begin(9600);                                
  SerialBT.println("Bluetooth connection established, choose heat level high medium low or off"); 

  // serial monitor test
  // Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // everything here is assuming we have a 9v power supply

  // Serial.println(runTime);
  // runTime = 0;
  
  if (runTime < minutes * 1) { // run heat/LEDs for only 30 minutes

    SerialBT.println("Set heat level to high medium low or off"); // initial string the user sees
    runTime = 0;
    while(SerialBT.available() == 0) { 
    }
    if (SerialBT.available()) {
      String msg = SerialBT.readString();
      if(msg == "low\r\n") {
        SerialBT.println("Heat level set to low, if you would like to change heat, type change");
        
        leds[0] = CRGB(255, 0, 0); // turn on LEDs
        FastLED.show();
        delay(100);  
        leds[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
      
        leds_2[0] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);  
        leds_2[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds_2[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
      
        leds_3[0] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);  
        leds_3[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds_3[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        
        analogWrite(5,43); // set voltage to ~1.5V
        previousMillis = millis(); // take the time at which the heat started
        runTime = 0;
        while(runTime < minutes * 1) {
          // do nothing for 30 minutes, let heat run
          runTime = millis() - previousMillis;
          if(SerialBT.available()) { // if 'change' is typed, set runTime to max value to exit this entire if statement and go to the ending else statement
            msg =  SerialBT.readString();
            if (msg == "change\r\n") {
              runTime = minutes * 1;
            }
          }
        }
      }

      else if(msg == "medium\r\n") {
        SerialBT.println("Heat level set to medium, if you would like to change heat, type change");
        
        leds[0] = CRGB(255, 0, 0); // turn on LEDs
        FastLED.show();
        delay(100);  
        leds[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
      
        leds_2[0] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);  
        leds_2[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds_2[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
      
        leds_3[0] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);  
        leds_3[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds_3[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        
        analogWrite(5,85); // set voltage to 3V
        previousMillis = millis(); // take the time at which the heat started
        runTime = 0;
        while(runTime < minutes * 1) {
          // do nothing for 30 minutes, let heat run
          runTime = millis() - previousMillis;
          if(SerialBT.available()) { // if 'change' is typed, set runTime to max value to exit this entire if statement and go to the ending else statement
            msg =  SerialBT.readString();
            if (msg == "change\r\n") {
              runTime = minutes * 1;
            }
          }
        }
      }

      else if(msg == "high\r\n") {
        SerialBT.println("Heat level set to high, if you would like to change heat, type change");
        
        leds[0] = CRGB(255, 0, 0); // turn on LEDs
        FastLED.show();
        delay(100);  
        leds[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
      
        leds_2[0] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);  
        leds_2[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds_2[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
      
        leds_3[0] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);  
        leds_3[1] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);
        leds_3[2] = CRGB(255, 0, 0);
        FastLED.show();
        delay(100);

        analogWrite(5,184); // set voltage to 6.5V
        previousMillis = millis(); // take the time at which the heat started
        runTime = 0;
        while(runTime < minutes * 1) {
          // do nothing for 30 minutes, let heat run
          runTime = millis() - previousMillis;
          if(SerialBT.available()) { // if 'change' is typed, set runTime to max value to exit this entire if statement and go to the ending else statement
            msg =  SerialBT.readString();
            if (msg == "change\r\n") {
              runTime = minutes * 1;
            }
          }
        }
      }

      else if(msg == "off\r\n") {
        SerialBT.println("Heat level set to 0, if you would like to change heat, type change");
        digitalWrite(6,HIGH);
        // analogWrite(7,0);
        // analogWrite(8,0);
        analogWrite(5,0); // set voltage to 0V
        previousMillis = millis(); // take the time at which the heat started
        runTime = 0;
        while(runTime < minutes * 1) {
          // do nothing for 30 minutes, let heat run
          runTime = millis() - previousMillis;
          if(SerialBT.available()) { // if 'change' is typed, set runTime to max value to exit this entire if statement and go to the ending else statement
            msg =  SerialBT.readString();
            if (msg == "change\r\n") {
              runTime = minutes * 1;
            }
          }
        }
      }

      else {
        analogWrite(5,0); // set voltage to 0 for unrecognized commands
        digitalWrite(6,HIGH);
        // analogWrite(7,0);
        // analogWrite(8,0);
        SerialBT.println("Invalid command, heat is off");
        runTime = 0;
      }
    }

    else {
      analogWrite(5,0); // set voltage to 0 for no command given
      digitalWrite(6,HIGH);
      // analogWrite(7,0);
      // analogWrite(8,0);
      SerialBT.println("No command given, heat is off");
      runTime = 0;
    }

    // currentMillis = millis();
    // runTime = currentMillis - previousMillis;
  }
  else { // 30 minutes is up
    analogWrite(5,0); // set voltage to 0
    digitalWrite(6,HIGH);
    // analogWrite(7,0);
    // analogWrite(8,0);
    SerialBT.println("Heat is off. Would you like to restart the heat? (type yes to restart)");
    // Serial.println(runTime);
    while(runTime >= minutes * 1) {
      while(SerialBT.available() == 0) { 
      }
      if (SerialBT.available()) {
        String msg = SerialBT.readString();
        if(msg == "yes\r\n") {
          runTime = 0;
          // Serial.println(runTime);
        }
        else {
          // delay(5000);
          SerialBT.println("command not understood");
          SerialBT.println("Heat is off. Would you like to restart the heat? (type yes to restart");
        }
      }
    }
    previousMillis = millis();
  }
}
