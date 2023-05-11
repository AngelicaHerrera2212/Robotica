/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

// notes in the melody:
int lose_melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};            // SONIDO PERDER
int F0_melody[] = { NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_F4, NOTE_G4};   // SONIDO FASE 0
int F1_melody[] = { NOTE_C4, NOTE_E4, NOTE_G4};                                                     // SONIDO FASE 1
int F2_melody[] = { NOTE_F4, NOTE_A4, NOTE_C5};                                                     // SONIDO FASE 2
int F3_melody[] = { NOTE_A3, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_CS4, NOTE_DS4, NOTE_A3};  // SONIDO FASE 3
int F4_melody[] = { NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4};                                            // SONIDO FASE 4
int F5_melody[] = { NOTE_B3, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_B3, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_B3, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_B4, NOTE_B4, NOTE_B4};  // SONIDO FASE 5


// note durations: 4 = quarter note, 8 = eighth note, etc.:
int lose_Durations[] = {4, 8, 8, 4, 4, 4, 4, 4};                  // DURACION SONIDO PERDER
int F0_Durations[] = {8, 8, 8, 8, 8, 8, 4, 2};                    // DURACION SONIDO FASE 0
int F12_Durations[] = {2, 2, 2};                                  // DURACION SONIDO FASE 1-2
int F3_Durations[] = {3, 2, 6, 3, 2, 3, 1, 1, 2, 6, 3, 2, 3, 1};  // DURACION SONIDO FASE 3
int F4_Durations[] = {2, 2, 2, 2};                                // DURACION SONIDO FASE 4
int F5_Durations[] = {8, 8, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 4, 8, 8, 4, 8, 8, 4, 4, 2};  // DURACION SONIDO FASE 5

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 22; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / F5_Durations[thisNote];
    tone(5, F5_melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
