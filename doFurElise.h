#include "pitches.h"

int fur_melody[] = {
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B5, NOTE_D5, NOTE_C5, NOTE_A3, NOTE_E3, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_A5, NOTE_E2, NOTE_E3, NOTE_GS3, NOTE_E4, NOTE_GS4, NOTE_B5, NOTE_A3, NOTE_E3, NOTE_A4, NOTE_E4, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B5, NOTE_D5, NOTE_C5, 
  NOTE_A3, NOTE_E3, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_A5, NOTE_E2, NOTE_E3, NOTE_GS3, NOTE_E4, NOTE_C5, NOTE_B5, NOTE_A3, NOTE_E3, NOTE_A4,  NOTE_A3, NOTE_E3, NOTE_A4, NOTE_B5, NOTE_C5, NOTE_D5,  NOTE_C3, NOTE_G4, NOTE_C4, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_G3, NOTE_G4, NOTE_B4, NOTE_F4, NOTE_E5, NOTE_D5  
  };
  //65 notes ^ total, 32 top, 33 bottom
int noteDurations2 = 16;

void doFurElise() 
{ 
  for (int thisNote = 0; thisNote < note_no; thisNote++) 
  {
     int noteDuration = tempo / noteDurations2;//[thisNote];
     tone(10, fur_melody[thisNote], noteDuration);
     int pauseBetweenNotes = noteDuration * 1.7;
     delay(pauseBetweenNotes);
     noTone(10);    
   }
}
