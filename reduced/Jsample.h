#ifndef JSAMPLE_H_INCLUDED
#define JSAMPLE_H_INCLUDED
#include"json.hpp"
#include<string>
using json = nlohmann::json;

class Jsample
{
    public:

    int GetBaudRate(json j);
    int GetStopbits(json j);
    std::string GetParity(json j);
    std::string GetPath(json j);
    int GetLED1_Number(json j);
    int GetLED2_Number(json j);
    int GetLED3_Number(json j);
    int GetLED1_Inten(json j);
    int GetLED2_Inten(json j);

};
#endif 