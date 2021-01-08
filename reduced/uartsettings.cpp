#include "uartsettings.h" 
#include "mystruct.h"
#include"Jsample.h"
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<unistd.h>
#include"json.hpp"
#include"ui.h"
#include<unistd.h>
using json = nlohmann::json;

int fd;
int brt,stb;
std::string pr,pt;
int itn1,itn2,ln1,ln2,ln3;
int userinten,userpattern,choice,ledchoice,c;

UserInterface userin;

int Uart::functionprotocolinten(int choice,int ledchoice,int userinten)
{
	defset();
	struct myProtocol s1;
    struct myProtocol *buffer=(struct myProtocol *)malloc(sizeof(struct myProtocol));  //initializing buffer and allocating memory to it
    if(buffer==NULL){
        std::cout<<"Memory allocation failed\n";
    }
    s1.preamble_start=89;
    s1.preamble_end=83;
    s1.command=choice;
    s1.led_no=ledchoice;
    s1.action=userinten;
	memcpy(buffer,&s1,sizeof(struct myProtocol));    //using memcpy to copy the srtuct data to buffer
    int written_data = write(fd,&s1,sizeof(myProtocol));
    // std::cout<<"\n\n  Data writting to serial port... ";
	// if(fd!=0){
	// printData(&s1);		
	// }
	std::cout<<"  Press 1 to go back to Menu\n Press any other key to Exit\n";
	std::cin>>c;
	//buttonread();

	if(c==1)
	{
		userin.takechoice();
	}
	//else if(c==0)
	// {
	// 	exit(0);
	// 	// std::cout<<"Reading Button Configurations";
     	//buttonread();
	// }
	else
	{
		exit(0);
		close(fd);
		// std::cout<<"Invalid Input! Enter a valid input.";
		// userin.takechoice();
	}
	
}

int Uart::functionprotocolpattern(int choice,int ledchoice,int pattern)
{
	defset();
	struct myProtocol s1;
    struct myProtocol *buffer=(struct myProtocol *)malloc(sizeof(struct myProtocol));  //initializing buffer and allocating memory to it
    if(buffer==NULL){
        std::cout<<"Memory allocation failed\n";
    }
    s1.preamble_start=89;
    s1.preamble_end=83;
    s1.command=choice;
    s1.led_no=ledchoice;
    s1.action=userpattern;
	memcpy(buffer,&s1,sizeof(struct myProtocol));    //using memcpy to copy the srtuct data to buffer
    int written_data = write(fd,&s1,sizeof(myProtocol));
    // std::cout<<"\n\n  Data writting to serial port... ";
	// if(fd!=0){
	// printData(&s1);		
	// }
	std::cout<<"   Press 1 to go back to Menu\n   Press any other key to Exit\n";
	std::cin>>c;
	//buttonread();

	if(c==1)
	{
		userin.takechoice();
	}
	// else if(c==0)
	// {
	// 	exit(0);
	// 	// std::cout<<"Reading Button Configurations";
    // 	// buttonread();
	// }
	else
	{
		exit(0);
		close(fd);
		// std::cout<<"Invalid Input! Enter a valid input.";
		// userin.takechoice();
	}
	
}

int Uart::defaultsettings(){
	std::cout<<"\n\n";
    std::cout<<"**************************************************************\n";
    std::cout<<"*          linux Application based Hardware control          *\n";
    std::cout<<"**************************************************************\n";
    //std::cout<<"\n";
	
	defset();
	printf("  Serial port Opened Successfully \n\n");
	std::cout<<"  Configurations set to serial port:\n  BaudRate = "<<brt<<"\n"<< "  StopBits = "<<stb<<"\n"<<"  Parity   = "<<pr<<"\n"<<"  Path     = "<<pt<<"\n"<<"  Default Intensity for LED1  = "<<itn1<<"\n  Default Intensity for LED2  = "<<itn2<<"\n";
	struct myProtocol s1;
	struct myProtocol *buffer=(struct myProtocol *)malloc(sizeof(struct myProtocol));  //initializing buffer and allocating memory to it
    if(buffer==NULL){
        std::cout<<"Memory allocation failed\n";
    }
    s1.preamble_start=89;
    s1.preamble_end=83;
    s1.command=1;
    s1.led_no=ln3;
    s1.action=itn1;
	struct myProtocol s2;
    s2.preamble_start=89;
    s2.preamble_end=83;
    s2.command=1;
    s2.led_no=ln2;
    s2.action=itn2;

	memcpy(buffer,&s1,sizeof(struct myProtocol));    //using memcpy to copy the srtuct data to buffer
    int written_data = write(fd,&s1,sizeof(myProtocol));
    //std::cout<<"\n\n  Data writting to serial port... \n\n\n";
	// if(fd!=0){
	// printData(&s1);		
	// }
	// unsigned int microsecond = 1000000;
	// usleep(3 * microsecond);
	memcpy(buffer,&s2,sizeof(struct myProtocol));    //using memcpy to copy the srtuct data to buffer
    written_data = write(fd,&s2,sizeof(myProtocol));
    //std::cout<<"  Data writting to serial port... ";
	// if(fd!=0){
	// printData(&s2);		
	// }
    close(fd);
    //std::cout<<"\n  Serial Port closed Successfully  \n\n";
	std::cout<<"*-----------------------------------------*\n\n";
}

int Uart::defset()
{
	
	if(pt=="/dev/ttyUSB0"){
  	fd = open("/dev/ttyUSB0",O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
	}
	else if(pt=="/dev/ttyUSB1"){
  	fd = open("/dev/ttyUSB1",O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
	}
	else if(pt=="/dev/ttyUSB2"){
  	fd = open("/dev/ttyUSB2",O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
	}								
 	if(fd == -1){						
   	   printf("\n  Error! in Opening Serial port  ");
	   return 0;
	}
   	else
	std::cout<<"\n\n";
	struct termios SerialPortSettings;	                     
	if(tcgetattr(fd, &SerialPortSettings)!=0){                                           //to get existing settings and handle any error
		std::cout<<"Error "<<errno<<" from tcgetattr: "<<strerror(errno)<<" \n";
		return 0;
	}	
	switch(brt) {
		case 9600:
		if(brt==9600)
			cfsetispeed(&SerialPortSettings, B9600);     //Set Read  Speed as 9600
			cfsetospeed(&SerialPortSettings, B9600);	 //Set Write Speed as 9600
			break;
       }
	if(pr=="none")
	{
		SerialPortSettings.c_cflag &= ~PARENB;   //Disables the Parity 
		SerialPortSettings.c_cflag &= ~CSTOPB;   //CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
		SerialPortSettings.c_cflag &= ~CSIZE;	 //Clears all the size bits
		SerialPortSettings.c_cflag |=  CS8;      //Set the data size bits = 8 per byte
	}
	else if (pr=="even")
	{
		SerialPortSettings.c_cflag |= PARENB;    //to set Even parity
		SerialPortSettings.c_cflag &= ~PARODD;   //to disable odd parity
		SerialPortSettings.c_cflag &= ~CSTOPB;   //CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
		SerialPortSettings.c_cflag &= ~CSIZE;	 //Clears all the size bits
		SerialPortSettings.c_cflag |=  CS8;      //Set the data size bits = 8 per byte
	}
	else if (pr=="odd")
	{
		SerialPortSettings.c_cflag |= PARENB;    //to set Odd parity
		SerialPortSettings.c_cflag |= PARENB;    
		SerialPortSettings.c_cflag &= ~CSTOPB;   //CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
		SerialPortSettings.c_cflag &= ~CSIZE;	 //Clears all the size bits
		SerialPortSettings.c_cflag |=  CS8;      //Set the data size bits = 8 per byte
	}
	else
	{
        return functionprotocolinten(choice,ledchoice,userinten);
		std::cout<<"  Enter valid parity\n";
		return 0;
	}
	SerialPortSettings.c_cc[VMIN]=5;                        //to specifically read 5 bytes from serial port
	SerialPortSettings.c_cflag &= ~CRTSCTS;                 //No Hardware flow Control
	SerialPortSettings.c_cflag |= CREAD | CLOCAL;           //Enable receiver to read frm serial port,Ignore Modem Control lines/ allows to read data
	SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);  //Disable software besed flow control both i/p and o/p
	SerialPortSettings.c_lflag &= ~ICANON;                  //to disable canonical mode
	SerialPortSettings.c_lflag &= ~ECHO;                    //to disable echo back the sent bits
	SerialPortSettings.c_lflag &= ~ISIG;                    //to disable interpretation of INTR, QUIT and SUSP
	SerialPortSettings.c_lflag &= ~ECHONL;                  //to disable new line echo
	SerialPortSettings.c_lflag &= ~IEXTEN;
	SerialPortSettings.c_oflag &= ~OPOST;

	if(tcsetattr(fd,TCSANOW,&SerialPortSettings)!=0){                                   //save settings, also check for error
		std::cout<<"Error "<<errno<<" from tcsetattr: "<<strerror(errno)<<" \n";
		return 1;
		}
	else
	std::cout<<"\n";
}

// int Uart::buttonread()
// {
// 	tcflush(fd, TCIFLUSH);  
// 	fcntl(fd, F_SETFL);
// 	while(1){
// 	char read_buf[5];    // Buffer to store the data received
//     memset(read_buf,0,sizeof(read_buf));
// 	int num_bytes;
// 	//do{
// 	num_bytes=read(fd,read_buf,sizeof(read_buf));   //reading the data on serial port
// 	std::cout<<"\n\n  Data reading from serial port... \n";
// 	if(sizeof(read_buf)!=0){
// 		goto NEXT;
// 	}
// 	//}while(1);
//     NEXT:
// 	if(num_bytes<0){
//         std::cout<<"\n  Error in reading serial port - "<<strerror(errno)<<"\n\n";
//     }
// 	std::cout<<"\n  Read "<<num_bytes<<" bytes"<<".\n";
// 		if(read_buf[0]=='Y' && read_buf[1]=='S'){
// 			if(read_buf[2]==3 && read_buf[3]==1){
// 				std::cout<<"\n  Status returning for button 1";
// 				if(read_buf[4]==1){
// 					std::cout<<"\n  Button is pressed. \n";
// 				}
// 				else if (read_buf[4]==2)
// 				{
// 					std::cout<<"\n  Button is released.  \n";
// 				}
// 				else
// 				{
// 					std::cout<<"\n  Button is on hold. \n";
// 				}
// 			}	
//     	}
// 		// int stop;
// 		// std::cin>>stop;
// 		// if(stop==0)
// 		// break;	
//  	}
// 	close(fd);
// 	std::cout<<"\n\n  Serial Port Closed\n";
// }