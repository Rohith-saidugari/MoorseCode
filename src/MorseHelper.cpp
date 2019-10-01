using namespace std;

#include "spark_wiring_tone.h"
#include "MorseHelper.h"

#include <string>
#include <map>

//Method Delarations
void playPattern(string code);
void playDit();
void playDah();
void letterdelay();

//Variables Declaration
std::map<char, string> pattern;
int ditDuration;
int dahDuration;
int ditDahDelay;
int letterDelay;
int frequency;
int timeunit;

/*
 * This Method is used to initialize morse codes and other variables like 
 */
void initializeCodes()
{
  timeunit = 100;
  ditDuration = timeunit;
  dahDuration = 3 * timeunit;
  ditDahDelay = timeunit;
  letterDelay = 3 * timeunit;
  frequency = 500;
  pattern['A'] = ".-";
  pattern['B'] = "-...";
  pattern['C'] = "-.-.";
  pattern['D'] = "-..";
  pattern['E'] = ".";
  pattern['F'] = "..-.";
  pattern['G'] = "--.";
  pattern['H'] = "....";
  pattern['I'] = "..";
  pattern['J'] = ".---";
  pattern['K'] = "-.-";
  pattern['L'] = ".-..";
  pattern['M'] = "--";
  pattern['N'] = "-.";
  pattern['O'] = "---";
  pattern['P'] = ".--.";
  pattern['Q'] = "--.-";
  pattern['R'] = ".-.";
  pattern['S'] = "...";
  pattern['T'] = "-";
  pattern['U'] = "..-";
  pattern['V'] = "...-";
  pattern['W'] = ".--";
  pattern['X'] = "-..-";
  pattern['Y'] = "-.--";
  pattern['Z'] = "--..";
}

/* This method takes string pattern  , Pattern consists of . and -s 
 * Plays a morse code pattern
 */
void playPattern(string code)
{
  unsigned int i;
  for (i = 0; i < code.length(); i++)
  {
    if (code[i] == '.')
      playDit();
    else if (code[i] == '-')
      playDah();
    else
      letterdelay();
  }
}
/*
 * This Method Takes actual message.
 * Breaks down message into each characters 
 * fetches pattern for each character in message from pattern map
 * calls playPattern method to play a pattern 
 * 
 * */
void resolveMorseCode(string message)
{
  unsigned int i;
  for (i = 0; i < message.length(); i++)
  {
    message[i];
    string code = pattern[message[i]];
    std::string stdString(code);
    playPattern(code);
    letterdelay();
  }
}
/*
 * This Method plays a dit sound and blinks dit led 
 * 
 * */
void playDit()
{
  digitalWrite(dit_LED_PIN, HIGH);
  tone(speaker_PIN, frequency, ditDuration);
  digitalWrite(dit_LED_PIN, LOW);
  delay(2 * ditDahDelay);
}
/*
 *
 * This Method plays Dah Sound on speaker 
 * Blinks Dah led on the circuit
 * 
 * */
void playDah()
{
  digitalWrite(dah_LED_PIN, HIGH);
  tone(speaker_PIN, frequency, dahDuration);
  digitalWrite(dah_LED_PIN, LOW);
  delay(4 * ditDahDelay);
}
/*
 * This method just performs delay operation
 * 
 */
void letterdelay()
{
  delay(3 * timeunit);
}