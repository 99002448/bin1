#include"Jsample.h"
#include<iostream>
#include<fstream>
#include<string>
#include"json.hpp"
using json = nlohmann::json;

extern int brt,stb;
extern std::string pr,pt;
extern int ln1,ln2,ln3;
extern int itn1,itn2;

int Jsample::GetBaudRate(json j)
{       
    brt=j["UARTConfiguration"]["BaudRate"];
    //std::cout<<brate;
    return brt;
}
int Jsample::GetStopbits(json j)
{       
    stb= j["UARTConfiguration"]["StopBits"];
    //std::cout<<stopb;	
    return stb;
}

std::string Jsample::GetParity(json j)
{   
	  
    //strcpy(par,j["UARTConfiguration"]["Parity"]);
    pr=j["UARTConfiguration"]["Parity"];
    return pr;
}
std::string Jsample::GetPath(json j)
{       
    pt=j["UARTConfiguration"]["Path"];
    return pt;
}


int Jsample::GetLED1_Number(json j)
{       
    ln1=j["LedConfiguration"]["Led_1"]["LEDNumber"];
    return ln1;
}
int Jsample::GetLED2_Number(json j)
{       
    ln2= j["LedConfiguration"]["Led_2"]["LEDNumber"];
    return ln2;
}
int Jsample::GetLED3_Number(json j)
{       
    ln3= j["LedConfiguration"]["Led_3"]["LEDNumber"];
    return ln3;
}

int Jsample::GetLED1_Inten(json j)
{       
    itn1= j["LedConfiguration"]["Led_1"]["Intensity"];
    return itn1;
}
int Jsample::GetLED2_Inten(json j)
{       
    itn2=j["LedConfiguration"]["Led_2"]["Intensity"];
    return itn2;
}