#include"ui.h"
#include"Jsample.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

extern int userinten; 
extern int userpattern;
extern int choice;
extern int ledchoice;
Uart ut;
int UserInterface::takechoice()
{
    cout<<"\n*------------Enter your choice:-----------*\n";
    cout<<"|\t1-Intensity                       |\n";
    cout<<"|\t2-Pattern                         |\n";
    cout<<"|\t'Enter any other key to exit'     |\n";   
    cout<<"\t";
    cin>>choice;
    cout<<"*-----------------------------------------*\n\n";
    if(choice==1)
    {
        intensity();
    }
    else if (choice==2)
    {
        pattern();
    }
    else
    {
        exit(0);
    }
    return 0;
}
    

int UserInterface::intensity()
{   
    chooseled();
    cout<<"Selected led is:  "<<ledchoice<<" \n\n";
    
    if (ledchoice==1)                                      
    {                                                     
        cout<<"*\tEnter the intensity(0-100)       *   \n";
        cout<<"      'Press 101 to exit the program.'\n";
        cin>>userinten;
        cout<<"*-----------------------------------------*\n";
        if(userinten>=0 && userinten<=100)
        {   
            cout<<"\n  Selected intensity is:"<<userinten<<"\n";
            return ut.functionprotocolinten(choice,ledchoice,userinten);
        }
        else if (userinten==101)
        {
            exit(0);
        }
        
        else
        {
        cout<<"\n\tInvalid Intensity!!!\n\n";
        cout<<"*-----------------------------------------*\n";
        intensity();
        }
    }
    if (ledchoice==2)
    {
        cout<<"*\tEnter the intensity(0-100)          *\n";
        cout<<"      'Press 101 to exit the program.'\n";
        cin>>userinten; 
        cout<<"*-----------------------------------------*\n";
        if(userinten<=100)
        {  
            cout<<"\n  Selected intensity is:\t"<<userinten<<"\n";
            return ut.functionprotocolinten(choice,ledchoice,userinten);
        }
        else if (userinten==101)
        {
            exit(0);
        }
        else
        {
        cout<<"\n\tInvalid Intensity!!!\n\n";
        cout<<"*-----------------------------------------*\n";
        intensity();
        }
        chooseled();
    }
    if (ledchoice==3)
    {
        cout<<"*\tEnter the intensity(0-100)          *\n";
        cout<<"      'Press 101 to exit the program.'\n";
        cin>>userinten; 
        cout<<"*-----------------------------------------*\n";
        if(userinten <=100)
        { 
            cout<<"\n  Selected intensity is:\t"<<userinten<<"\n\n"; 
            return ut.functionprotocolinten(choice,ledchoice,userinten);
        }
        else if (userinten==101)
        {
            exit(0);
        }
        else
        {
        cout<<"\n\tInvalid Intensity!!!\n\n";
        cout<<"*-----------------------------------------*\n";
        intensity();
        }
    }
}

int UserInterface::pattern()
{
    chooseled();
    cout<<"Selected led is:  "<<ledchoice<<"\n";
    cout<<"*         Enter the pattern:(1 / 2 / 3)   *\n";
    cin>>userpattern;
    
    if(ledchoice==1)
    {
        choosepattern();
        return ut.functionprotocolpattern(choice,ledchoice,userpattern);
    }
    else if (ledchoice==2)
    {
        choosepattern();
        return ut.functionprotocolpattern(choice,ledchoice,userpattern);          
    }
    else if (ledchoice==3)
    {
        choosepattern();
        return ut.functionprotocolpattern(choice,ledchoice,userpattern);  
    }
    else
    {
        cout<<"Invalid!!!  Enter valid choice\n\n";
        cout<<"*-----------------------------------------*\n";
        takechoice();
    }
    
}

int UserInterface::chooseled()
{
    
    cout<<"*---------Enter the LED number:----------*\n";
    cout<<"1-LED 1(Green)\n2-LED 2(Blue)\n3-both LEDs\n4-Quit\n";
    cin>>ledchoice;
    if(ledchoice==1)
    {
        return ledchoice;
    }
    else if (ledchoice==2)
    {
        return ledchoice; 
    }
    else if (ledchoice==3)
    {
        return ledchoice;
    }
    else if (ledchoice==4)
    {
        exit(0);
    }
    
    else
    {
        cout<<"Invalid!!!  Enter valid choice\n\n";
        cout<<"*-----------------------------------------*\n\n";
        chooseled();
    }
    
}   

int UserInterface::choosepattern()
{
    if(userpattern==1)
        {
            cout<<"1st pattern is set.\n\n";
            cout<<"*-----------------------------------------*\n";
            return userpattern;
        }
        else if (userpattern==2)
        {
            cout<<"2nd pattern is set\n\n";
            cout<<"*-----------------------------------------*\n";
            return userpattern;
        }
        else if (userpattern==3)
        {
            cout<<"3rd Pattern is set\n\n";
            cout<<"*-----------------------------------------*\n";
            return userpattern;
        }
        else
        {
            cout<<"Invalid!!! Enter valid pattern:\n\n";
            cout<<"*-----------------------------------------*\n";
            takechoice();
        }
    return userpattern;
}