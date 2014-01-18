/* This sketch allows for proper syncing between playing the song and initializing the Arduino. */

import processing.serial.*;
import ddf.minim.*;
import ddf.minim.analysis.*;

Serial arduinoPort;
Minim minim;
AudioPlayer song;

void setup() {
  println(Serial.list());
  // Open communication to the Arduino
  arduinoPort = new Serial(this, Serial.list()[0], 9600);
  
  minim = new Minim(this);
  song = minim.loadFile("Byegone.wav", 2048);
  delay(150);
  song.play();
}

void draw() {
  // Write a 1 to the Arduino to signal the song as started
  arduinoPort.write('1');
} 

void stop() {
  arduinoPort.clear();
  arduinoPort.write('0');
  arduinoPort.stop();

  song.close();
  minim.stop();
  // close the sketch
  super.stop();
}
