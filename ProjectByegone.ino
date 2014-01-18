/**
  * This sketch displays lyrics and flashes lights to the beats of the song "Byegone" by Volcano Choir.
  * The beats are coded in via millisecond timings read from frequency-measuring audio software.
  * Programming for beat frequency detection is an alternative to this method.
  * The hardware setup includes an Arduino Uno, a breadboard, six LEDs, a 16x2 LCD, and a potentiometer (to control the contrast of the LCD).
  * For more information about this project, please visit http://www.ryan-taylor.me/portfolio/software/arduino-light-show/ 
  */
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int lcdPower = A5;
long currentTime;
long previousTime1 = 0;
long previousTime2 = 0;
int leds[] = {6, 7, 8, 9, 10, A0};
int ledStates[] = {LOW, LOW, LOW, LOW, LOW, LOW};
int numLEDs = 6;
long thumperInterval = 95;
long twinkleInterval1 = 427;
long twinkleInterval2 = 250;
int elevateInterval = 190;
int ledIndex = 0;
int prevLEDIndex = 0;
char play = '0';
int chord = 1300;
int counter = 0;

void setup() {
  // Allow for serial communication with computer software (Processing)
  Serial.begin(9600);
  // Initialize all the LEDs as output
  for(int i = 0; i < numLEDs; i++) {
    pinMode(leds[i], OUTPUT);
  }
  // Initialize the LCD as an output with two rows and two columns
  pinMode(lcdPower, OUTPUT);
  lcd.begin(16, 2);
  digitalWrite(lcdPower, LOW);
}

void loop() {
  // Perform a busy wait until the play function is called in Processing; Processing will write a '1' to the serial port when play is called
  play = Serial.read()-'0';
  if (play >= 1) {
    //delay(75);
    currentTime = millis();
    
    // Introduction
    // Thumper sequence
    while(currentTime < 34250) {
      currentTime = millis();
      if(currentTime - previousTime1 > thumperInterval) {
        previousTime1 = currentTime;
        if(ledStates[0] == LOW)
          ledStates[0] = HIGH;
        else
          ledStates[0] = LOW;
        digitalWrite(leds[0], ledStates[0]);
      }
      
      // Twinkle sequence
      currentTime = millis();
      if(currentTime > 6800) {
        if(currentTime - previousTime2 > twinkleInterval1) {
          previousTime2 = currentTime;
          if(prevLEDIndex != 0)
            digitalWrite(leds[prevLEDIndex], LOW);
            
          while(ledIndex == prevLEDIndex) {
            ledIndex = (int)random(5) + 1;
          }
          digitalWrite(leds[ledIndex], HIGH);
          prevLEDIndex = ledIndex;
        }
      }
    }
    
    // Elevate sequence
    lightsOut(10);
    delay(75);
    for(int i = 0; i < 4; i++) {
      lightsOn(798);
      lightsOut(2);
      digitalWrite(leds[0], HIGH);
      delay(elevateInterval);
      digitalWrite(leds[0], LOW);
      for(int index = 1; index < numLEDs; index++) {
        digitalWrite(leds[index], HIGH);
        delay(elevateInterval);
        digitalWrite(leds[index], LOW);
      }
      delay(4910);
    }
    delay(50);
    lightsOn(4000);
    lightsOut(1394);
    
    // Turn on the LCD and display the lyrics of the current verse
    digitalWrite(lcdPower, HIGH);
    lcdPrint("Day dead_bye-gone");
    delay(475);
    lyricalLightsOn(150);
    lyricalLightsOut(100);
    lyricalLightsOn(175);
    lyricalLightsOut(275);
    lyricalLightsOn(150);
    lyricalLightsOut(100);
    lyricalLightsOn(200);
    lyricalLightsOut(1250);

    lcdPrint("Laying near_the lights");
    delay(1000);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(125);
    lightsOn(425);
    lightsOut(500);

    lcdPrint("Of the knights");
    delay(600);
    lyricalLightsOn(90);
    lyricalLightsOut(80);
    lyricalLightsOn(90);
    lyricalLightsOut(80);
    lyricalLightsOn(360);
    lcdPrint("of the northern_lodges");
    lyricalLightsOut(200);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(300);
    lyricalLightsOut(1050);

    lcdPrint("There's a_border road");
    delay(1000);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(500);
    lyricalLightsOut(100);
    lyricalLightsOn(200);
    lyricalLightsOut(100);
    lyricalLightsOn(300);
    lyricalLightsOut(700);

    lcdPrint("No one_slip slides");
    delay(700);
    lyricalLightsOn(150);
    lyricalLightsOut(150);
    lyricalLightsOn(150);
    lyricalLightsOut(150);
    lyricalLightsOn(150);
    lyricalLightsOut(150);
    lyricalLightsOn(250);
    lcdPrint("or is stoppin'");
    lyricalLightsOut(300);
    lyricalLightsOn(100);
    lyricalLightsOut(50);
    lyricalLightsOn(100);
    lyricalLightsOut(50);
    lyricalLightsOn(150);
    lyricalLightsOut(150);
    lyricalLightsOn(250);
    lyricalLightsOut(950);

    lcdPrint("And the_neighborly,");
    delay(950);
    lyricalLightsOn(200);
    lyricalLightsOut(200);
    lyricalLightsOn(200);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(250);
    lyricalLightsOut(600);
    lcdPrint("sleeping in_a coffin");
    delay(500);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    delay(300);
    lyricalLightsOut(100);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    delay(300);
    lyricalLightsOut(1400);

    lcdPrint("With enough kief");
    delay(1000);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(80);
    lyricalLightsOut(80);
    lyricalLightsOn(100);
    lyricalLightsOut(250);
    lyricalLightsOn(300);
    lyricalLightsOut(800);

    lcdPrint("You could really_bore someone");
    delay(800);
    lyricalLightsOn(110);
    lyricalLightsOut(100);
    lyricalLightsOn(115);
    lyricalLightsOut(100);
    lyricalLightsOn(75);
    lyricalLightsOut(75);
    lyricalLightsOn(75);
    lyricalLightsOut(75);
    lyricalLightsOn(500);
    lyricalLightsOut(150);
    lyricalLightsOn(150);
    lyricalLightsOut(125);
    lyricalLightsOn(250);
    lyricalLightsOut(800);

    lcdPrint("Took a rat_trap out");
    delay(750);
    lyricalLightsOn(125);
    lyricalLightsOut(100);
    lyricalLightsOn(52);
    lyricalLightsOut(52);
    lyricalLightsOn(210);
    lyricalLightsOut(100);
    lyricalLightsOn(210);
    lyricalLightsOut(100);
    lyricalLightsOn(300);
    lcdPrint("to the Ache Inn");
    lyricalLightsOut(400);
    lyricalLightsOn(50);
    lyricalLightsOut(50);
    lyricalLightsOn(50);
    lyricalLightsOut(100);
    lyricalLightsOn(150);
    lyricalLightsOut(100);
    lyricalLightsOn(300);
    lyricalLightsOut(450);

    lcdPrint("We were drinking");
    delay(450);
    lyricalLightsOn(80);
    lyricalLightsOut(80);
    lyricalLightsOn(80);
    lyricalLightsOut(80);
    lyricalLightsOn(80);
    lyricalLightsOut(80);
    lyricalLightsOn(100);
    lcdPrint("all the ways_to down");
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(350);
    lyricalLightsOut(150);
    lyricalLightsOn(100);
    lyricalLightsOut(100);
    lyricalLightsOn(200);
    lyricalLightsOut(50);
    
    // 2 3 2 chords
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[4], HIGH);
    delay(chord);
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[4], LOW);
    delay(400);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    lcdPrint("Door 'as_wide open");
    delay(chord);
    digitalWrite(leds[2], LOW);
    digitalWrite(leds[3], LOW);
    delay(400);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[4], HIGH);
    delay(chord);
    lcdPrint("You know what_we're saying");
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[4], LOW);
    delay(2090);
    
    // 2 3 1 chords
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[4], HIGH);
    delay(chord);
    lcdPrint("'bout us now");
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[4], LOW);
    delay(490);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    delay(chord);
    digitalWrite(leds[2], LOW);
    digitalWrite(leds[3], LOW);
    delay(430);
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[5], HIGH);
    delay(chord);
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[5], LOW);
    delay(1010);
    lcdPrint("He's a legend");
    delay(1020);
    
    // 1 1 2 3 4 chords
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[5], HIGH);
    delay(chord);
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[5], LOW);
    delay(1100);
    lcdPrint("I'm a legend");
    delay(1110);
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[5], HIGH);
    delay(chord);
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[5], LOW);
    delay(1100);
    lcdPrint("And we both_go tripping");
    delay(1000);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[4], HIGH);
    delay(chord);
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[4], LOW);
    delay(1100);
    lcdPrint("through the door");
    delay(1000);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    delay(chord);
    digitalWrite(leds[2], LOW);
    digitalWrite(leds[3], LOW);
    delay(400);
    digitalWrite(leds[5], HIGH);
    delay(chord);
    digitalWrite(leds[5], LOW);
    delay(250);
    
    // Twinkle sequence
    currentTime = millis();
    previousTime1 = 0;
    prevLEDIndex = 0;
    while(currentTime < 157800) {
      if(currentTime - previousTime1 > twinkleInterval2) {
        previousTime1 = currentTime;
        digitalWrite(leds[prevLEDIndex], LOW);
          
        while(ledIndex == prevLEDIndex) {
          ledIndex = (int)random(6);
        }
        digitalWrite(leds[ledIndex], HIGH);
        prevLEDIndex = ledIndex;
      
        counter++;
        switch(counter) {
          case 2: lcdPrint("You know that we_are northern now"); break;
          case 12: lcdPrint("I heard you_promise me"); break;
          case 22: lcdPrint("at the north_end of monogamy"); break;
          case 32: lcdPrint("Cut there from_filament lead"); break;
          case 45: lcdPrint("Somewhere I_heard you scream"); break;
          case 61: lcdPrint("For others'_hearts"); break;
          case 71: lcdPrint("In the limiest_of lights"); break;
          case 82: lcdPrint("Hold the keys to_a Cuban flight"); break;
          case 93: lcdPrint("that you won't_ever ride"); break;
          case 102: lcdPrint("It's time to_up and die"); break;
        }
      }
      currentTime = millis();
    }
    
    // Hook with bounce sequence
    lcd.clear();
    lightsOn(600);
    lightsOut(100);
    bounce();
    lightsOut(1050);
    sail();
    
    lightsOut(477);
    lightsOn(600);
    lightsOut(225);
    bounce();
    lightsOut(1025);
    sail();
    
    lightsOut(477);
    lightsOn(525);
    lightsOut(200);
    bounce();
    lightsOut(1125);
    sail();
    
    lightsOut(477);
    lightsOn(525);
    lightsOut(200);
    bounce();
    lightsOut(1125);
    sail();
    
    lightsOn(600);
    lightsOut(190);
    
    // Elevate and flashback sequence
    for(int index = 0; index < numLEDs; index++) {
      digitalWrite(leds[index], HIGH);
      delay(elevateInterval);
      digitalWrite(leds[index], LOW);
      if(index == numLEDs-4)
        lcdPrint("Hon, you plenty_competent");
    }
    flashBack(110);
    delay(250);
    lightsOn(300);
    lightsOut(875);
    
    lcdPrint("So why aren't_you confident");
    delay(250);
    flashBack(150);
    delay(200);
    lightsOn(300);
    lightsOut(300);
    for(int index = 0; index < numLEDs; index++) {
      digitalWrite(leds[index], HIGH);
      if(index == numLEDs-1)
        delay(elevateInterval/2);
      else
        delay(elevateInterval);
      digitalWrite(leds[index], LOW);
      if(index == numLEDs-4)
        lcdPrint("It's softening_to be softening");
    }
    delay(60);
    flashBack(130);
    lightsOn(330);
    lcdPrint("Then why are you");
    digitalWrite(lcdPower, LOW);
    lightsOut(315);
    digitalWrite(lcdPower, HIGH);
    lightsOn(315);
    digitalWrite(lcdPower, LOW);
    lightsOut(315);
    digitalWrite(lcdPower, HIGH);
    lightsOn(315);
    digitalWrite(lcdPower, LOW);
    lightsOut(315);
    lcdPrint("so constant_then?");
    digitalWrite(lcdPower, HIGH);
    lightsOn(315);
    digitalWrite(lcdPower, LOW);
    lightsOut(315);
    digitalWrite(lcdPower, HIGH);
    lightsOn(315);
    digitalWrite(lcdPower, LOW);
    lightsOut(155);
    digitalWrite(lcdPower, HIGH);
    lightsOn(315);
    digitalWrite(lcdPower, LOW);
    lightsOut(155);
    digitalWrite(lcdPower, HIGH);
    lightsOn(315);
    lightsOut(300);
    
    lcdPrint("Are we going_on a coat ride?");
    for(int index = 0; index < numLEDs-1; index++) {
      digitalWrite(leds[index], HIGH);
      delay(elevateInterval);
      digitalWrite(leds[index], LOW);
    }
    lightsOn(125);
    lightsOut(100);
    lightsOn(125);
    lightsOut(100);
    lightsOn(125);
    lightsOut(100);
    lightsOn(80);
    lightsOut(100);
    lightsOn(80);
    lightsOut(115);
    lightsOn(225);
    lightsOut(115);
    lightsOn(300);
    lightsOut(235);
    
    lcdPrint("Well, we're off");
    lightsOn(800);
    lightsOut(420);
    
    lightsOn(125);
    lcdPrint("and definitely_stumbling");
    lightsOut(125);
    lightsOn(125);
    lightsOut(125);
    lightsOn(125);
    lightsOut(125);
    
    lightsOn(100);
    lightsOut(100);
    lightsOn(80);
    lightsOut(80);
    lightsOn(80);
    lightsOut(80);
    lightsOn(100);
    lightsOut(90);
    lightsOn(70);
    lightsOut(30);
    lightsOn(50);
    lightsOut(30);
    lightsOn(300);
    lightsOut(230);
    
    lightsOn(630);
    lightsOut(200);
    
    int index = 2;
    lcdPrint("Tossin' off_your compliments");
    for(int counter = 0; counter < numLEDs-1; counter++) {
      if(counter % 2 == 0) {
        digitalWrite(leds[index], HIGH);
        delay(elevateInterval);
        digitalWrite(leds[index], LOW);
        index+=counter+1;
      } else {
        digitalWrite(leds[index], HIGH);
        delay(elevateInterval);
        digitalWrite(leds[index], LOW);
        index-=counter+1;
      }
    }
    
    lightsOn(150);
    lightsOut(100);
    lightsOn(100);
    lightsOut(100);
    lightsOn(125);
    lightsOut(100);
    lightsOn(125);
    lightsOut(100);
    lightsOn(125);
    lightsOut(100);
    lightsOn(100);
    lightsOut(100);
    lightsOn(100);
    lcdPrint("Wow");
    lightsOut(125);
    lightsOn(625);
    lcdPrint("Sexing all_your Parliaments");
    lightsOut(1000);
    
    lightsOn(130);
    lightsOut(75);
    lightsOn(115);
    lightsOut(100);
    lightsOn(120);
    lightsOut(100);
    lightsOn(120);
    lightsOut(100);
    lightsOn(130);
    lightsOut(90);
    lightsOn(90);
    lightsOut(90);
    lightsOn(300);
    lightsOut(175);
    
    // Conclusion
    // Turn off the LCD + thumper and elevate sequence
    lcd.clear();
    digitalWrite(lcdPower, LOW);
    lightsOn(4000);
    lightsOut(5);
    
    previousTime1, previousTime2 = 0;
    currentTime = millis();
    while(currentTime < 246800) {
      currentTime = millis();
      if(currentTime - previousTime1 > thumperInterval) {
        previousTime1 = currentTime;
        if(ledStates[0] == LOW)
          ledStates[0] = HIGH;
        else
          ledStates[0] = LOW;
        digitalWrite(leds[0], ledStates[0]);
      }
      
      currentTime = millis();
      if(currentTime > 223000) {
        if(currentTime - previousTime2 > 3400) {
          previousTime2 = currentTime;
          for(int index = 1; index < numLEDs; index++) {
            digitalWrite(leds[index], HIGH);
            digitalWrite(leds[0], LOW);
            delay(thumperInterval);
            digitalWrite(leds[0], HIGH);
            delay(thumperInterval);
            digitalWrite(leds[index], LOW);
          }
        }
      }
    }
    delay(94);
    digitalWrite(leds[0], HIGH);
    delay(6500);
    digitalWrite(leds[0], LOW);
    while(1){}
  }
}

// Turn all the LEDs on and wait for a given duration
void lightsOn(int duration) {
  for(int index = 0; index < numLEDs; index++)
    digitalWrite(leds[index], HIGH);
  delay(duration);
}

// Turn all the LEDs off and wait for a given duration
void lightsOut(int duration) {
  for(int index = 0; index < numLEDs; index++) {
    digitalWrite(leds[index], LOW);
  }
  delay(duration);
}

// Turn the middle four lights on and wait for a given duration
void lyricalLightsOn(int duration) {
  for(int index = 1; index < numLEDs-1; index++)
    digitalWrite(leds[index], HIGH);
  delay(duration);
}

// Turn the middle four lights off and wait for a given duration
void lyricalLightsOut(int duration) {
  for(int index = 1; index < numLEDs-1; index++)
    digitalWrite(leds[index], LOW);
  delay(duration);
}

// Perform the hook of the song (four sequences)
void sail() {
  lcd.print("Set ");
  lightsOn(275);
  lightsOut(150);
  lcd.print("sail!");
  lightsOn(3000);
  lcd.clear();
}

// Turn LEDs 2, 3, 1, 4, 0, 5 on and off in that order
void bounce() {
  int index = 2;
  for(int counter = 0; counter < numLEDs; counter++) {
    if(counter % 2 == 0) {
      digitalWrite(leds[index], HIGH);
      delay(elevateInterval);
      digitalWrite(leds[index], LOW);
      index+=counter+1;
    } else {
      digitalWrite(leds[index], HIGH);
      delay(elevateInterval);
      digitalWrite(leds[index], LOW);
      index-=counter+1;
    }
  }
}

// Blink the LEDs, incrementally skipping an LED each iteration
void flashBack(int duration) {
  lightsOn(duration);
  lightsOut(duration);
  for(int index = numLEDs-2; index >= 0; index--) {
    for(int i = index; i >= 0; i--)
      digitalWrite(leds[i], HIGH);
    delay(duration);
    lightsOut(duration);
    digitalWrite(leds[index], LOW);
  }
}

// Write the given lyrics to the LCD, moving the cursor to the second row when a '_' is found in the String
void lcdPrint(String lyrics) {
  String line1 = "";
  String line2 = "";
  int middle = 0;
  char split = lyrics.charAt(middle);
  lcd.clear();
  if(lyrics.length() > 16) {
    while(split != '_') {
      middle++;
      split = lyrics.charAt(middle);
    }
    line1 = lyrics.substring(0, middle);
    line2 = lyrics.substring(middle+1);
      
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);
  } else
    lcd.print(lyrics);
}
