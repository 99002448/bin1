
#ifndef SETTINGS_LIBRARY
#define SETTINGS_LIBRARY
#include"ui.h"
class Uart{
    public:
    int defaultsettings();
    int defset();
    int buttonread();
    int functionprotocolinten(int choice,int ledchoice,int userinten);
    int functionprotocolpattern(int choice,int ledchoice,int pattern);
};
#endif