
#include <SFEMP3Shield.h>
#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>

#include <BlockDriver.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SysCall.h>


SdFat sd; // Create SDFat object. 

SFEMP3Shield MP3player; // Create SFEMP3Shield object

//Settings for MP3 player
const uint8_t volume = 60; // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max


//In void setup you need two functions which are defined below
void setup(){
  initSD();  // Initialize the SD card
  initMP3Player(); // Initialize the MP3 Shield
}

void loop()
{
  
  uint8_t result = MP3player.playTrack(5); //plays track 1 (track001.mp3)
  delay(3000); //delay for a little sanity between sounds
 }
 

//function to intialize SD card. Leave it alone unless you know what you're doing.

void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}


//function to intialize MP3 player. Leave it alone unless you know what you're doing

void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    // Error checking can go here!
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}

