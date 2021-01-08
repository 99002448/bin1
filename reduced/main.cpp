#include <stdio.h>
#include <string.h>
#include <fcntl.h>   
#include <termios.h> 
#include <unistd.h>  
#include <errno.h>   
#include <iostream>   
#include <fstream>
#include "uartsettings.h"
#include "uartsettings.cpp"
#include "Jsample.h"
#include "Jsample.cpp"
#include"json.hpp"

#include"ui.h"
#include"ui.cpp"
using json = nlohmann::json;



int main()
{
    std::ifstream d("DefaultConfiguration.json");
    json j;
    d>>j;

	Jsample jsam;
    jsam.GetBaudRate(j);
	jsam.GetStopbits(j);
	jsam.GetParity(j);
	jsam.GetPath(j);
    jsam.GetLED1_Number(j);
    jsam.GetLED2_Number(j);
    jsam.GetLED3_Number(j);
    jsam.GetLED1_Inten(j);
    jsam.GetLED2_Inten(j);
 
	Uart ut;
	ut.defaultsettings();
    UserInterface use;
    use.takechoice();
}
