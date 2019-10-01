#ifndef MorseHelper_h
#define MorseHelper_h
#include <string>
//The variables declared as extern can be accessed through out the project anywhere
extern  int speaker_PIN ;
extern  int dit_LED_PIN;
extern  int dah_LED_PIN;
extern  int SOS_Button_PIN;
extern  int timeunit  ;
void initializeCodes();
void resolveMorseCode(std::string message);
#endif