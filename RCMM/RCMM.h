/*---
RCMM Header file
 Author: Shane A. Baty
 Aug. 2015

 Note  :

---*/

#ifndef RCMM_h
#define RCMM_h
#include "Arduino.h"

class RCMM 
{
 public:
     RCMM(int pin);            // this is the constructor
   void         readIR();
   unsigned long         readBeg();   
   unsigned long         readMid();   // this is the main method
   unsigned long         readEnd();  
   unsigned long         readBit1();
   unsigned long         readBit2();
   unsigned long         readBit3();
   unsigned long         readBit4();
   unsigned long         readBit5();
   unsigned long         readBit6();
   unsigned long         readBit7();
   unsigned long         readBit8();
   unsigned long         readToggle();
   unsigned long         readBit10();
   unsigned long         readBit11();
   unsigned long         readBit12();
   unsigned long         readBit13();
   unsigned long         readBit14();
   unsigned long         readBit15();
   unsigned long         readBit16();
   
   unsigned long 		 IRin();
   

 



 private:

byte IR_PIN;
 unsigned long ButtonCode;
 unsigned long ButtonCodeEnd;
 unsigned long ButtonCodeMid;
 unsigned long ButtonCodeBeg;
 unsigned long ToggleBit;
 unsigned long LBit1; 
 unsigned long LBit2;
 unsigned long LBit3;
 unsigned long LBit4;
 unsigned long LBit5;
 unsigned long LBit6;
 unsigned long LBit7;
 unsigned long LBit8;
 unsigned long LBit9;
 unsigned long LBit10;
 unsigned long LBit11;
 unsigned long LBit12;
 unsigned long LBit13;
 unsigned long LBit14;
 unsigned long LBit15;
 unsigned long LBit16; 


unsigned long Bit;//Temp bit place holder used to convert the pulses into a 0-4 value.

unsigned long Bit1;
unsigned long Bit2;
unsigned long Bit3;
unsigned long Bit4;
unsigned long Bit5;
unsigned long Bit6;
unsigned long Bit7;
unsigned long Bit8;

unsigned long TBit; // this is the toggle bit                     |
unsigned long Bit10;//---------------------------------------------

unsigned long Bit11;//-----------------------------------------------
unsigned long Bit12;//                                               |
unsigned long Bit13;// these bits determine the button being pressed |
unsigned long Bit14;//         bits 11 - 16                          |
unsigned long Bit15;//                                               |
unsigned long Bit16;//-----------------------------------------------

unsigned long Bit17;  //stop pulse. this pulse is the one used to see the end of the IR command


//-----Bit Timings------------    
//                            This section is where you set the pulses max and min values.
//------ZERO-------------
//-------00--------------
int ZEROmin = 120;
int ZEROmax = 310;

//------ONE--------------
//-------01-------------
int ONEmin = 320;
int ONEmax = 465; 

//------TWO-------------
//------10-------------
int TWOmin = 470; 
int TWOmax = 635; 

//-----THREE------------
//-------11------------
int THREEmin = 650;
int THREEmax = 800;

//-----FOUR---------------
// This one is not represented by a value. it is just here to detect the end of the code transmission.
//  the length of this pulse is determined by the total length of the transmission. You will see me call this the "end pulse".
long FOURmin = 84000;
long FOURmax = 88000;




};

#endif