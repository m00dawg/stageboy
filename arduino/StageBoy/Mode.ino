/**************************************************************************
 * Name:    Timothy Lamb                                                  *
 * Email:   trash80@gmail.com                                             *
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 
/* ***************************************************************************/
/* "Mode" Functions. Deals with changing the setup of arduino.              */
/* ***************************************************************************/

 /*
   setMode will check if the push button is depressed, If it is it will 
   increment the mode number and make sure its in the 
   range 0 to 4 by mod (%). It will then write the mode to memory,
   set the leds to display the mode, and switch the code over to the
   right function.
 */
 

void setMode()
{
  byte state = 0;
  for (count = 0; count < 3; ++count)
    state = (state << 1) | digitalRead(dipSwitches[count]);
  
  if(mode != state) 
  {
    mode = state;
    switchMode();
  }
}


 /*
   switchMode is only called from setMode. its responsible for
   linking the mode number to its corrisponding function, 
   and then calling that function. function. function.
 */
void switchMode()
{
  switch(state)
  {
    case 0:
      modeLSDJSlaveSyncSetup();
      break;
    case 1:
      modeLSDJMasterSyncSetup();
      break;
    case 2:
      modeLSDJKeyboardSetup();
      break;
    case 3:
      modeNanoloopSetup();
      break;
    case 4:
      modeMidiGbSetup();
      break;
    case 5:
      modeLSDJMapSetup();
      break;
    case 6:
      modeLSDJMidioutSetup();
      break;
  }
}


/* ***************************************************************************/
/* General Global Functions Used in more then one of the modes               */
/* ***************************************************************************/

 /*
   sequencerStart is called when either LSDJ has started to play in master mode, 
   or when a MIDI Start or continue command is received in lsdj slave mode.
   Basically it just resets some counters we use and sets a "start" flag.
 */
 
void sequencerStart()
{
  sequencerStarted = true; //Sequencer has started?
  countSyncPulse = 0;      //Used for status LED, counts 24 ticks (quarter notes)
  countSyncTime = 0;       //Used to count a custom amount of clock ticks (2/4/8) for sync effects
  countSyncLightTime=0;
  switchLight=0;
}

 /*
   sequencerStop is called when either LSDJ has stopped sending sync commands for
   some time in LSDJ Master mode, or when a MIDI Stop command is received in
   lsdj slave mode.
   Basically it just resets some counters we use and sets the "start" flag to false.
 */
void sequencerStop()
{
  midiSyncEffectsTime = false;//Turn off MIDI sync effects in LSDJ slave mode
  sequencerStarted = false;   //Sequencer has started?
  countSyncPulse = 0;         //Used for status LED, counts 24 ticks (quarter notes)
  countSyncTime = 0;          //Used to count a custom amount of clock ticks (2/4/8) for sync effects
  countSyncLightTime=0;
  switchLight=0;
  digitalWrite(pinLeds[0],LOW);
  digitalWrite(pinLeds[1],LOW);
  digitalWrite(pinLeds[2],LOW);
  digitalWrite(pinLeds[3],LOW);
  digitalWrite(pinLeds[memory[MEM_MODE]],HIGH);
}


