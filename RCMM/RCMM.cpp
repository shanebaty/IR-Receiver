/*---
RCMM CPP File
 Author: Shane A. Baty
 Aug. 2015

 Note  :
---*/

#include "Arduino.h"
#include "RCMM.h"




RCMM::RCMM(int pin)
{
 
 byte IR_PIN = pin;
 pinMode(IR_PIN, INPUT);

}
//==================================================================
void RCMM::readIR()
{
  

ButtonCode = 0;
ButtonCodeBeg = 0;
ButtonCodeMid = 0;
ButtonCodeEnd = 0;

IRin(); 
    
   
            //-------------------------------------------------------------------------------------
       // Read IR input
  
  if (Bit17 == 4) // once it sees 4 it does the last few things to print out the data
  {

  //---------------- IRcompress--------------
  ButtonCodeBeg = (Bit1 * 1000) + (Bit2 * 100) + (Bit3 * 10) + Bit4; 
  ButtonCodeMid = (Bit5 * 100000) + (Bit6 * 10000) + (Bit7 * 1000) + (Bit8 * 100) + (TBit * 10) + Bit10;
  ButtonCodeEnd = ((Bit11 * 100000) + (Bit12 * 10000) + (Bit13 * 1000) + (Bit14 * 100) + (Bit15 * 10) + Bit16);
  LBit1 = Bit1;
  LBit2 = Bit2;
  LBit3 = Bit3;
  LBit4 = Bit4;
  LBit5 = Bit5;
  LBit6 = Bit6;
  LBit7 = Bit7;
  LBit8 = Bit8;
  ToggleBit = TBit;
  LBit10 = Bit10;
  LBit11 = Bit11;
  LBit12 = Bit12;
  LBit13 = Bit13;
  LBit14 = Bit14;
  LBit15 = Bit15;
  LBit16 = Bit16;
  
  }

  }
  
 

    unsigned long RCMM::readBeg()
 {

ButtonCode = ButtonCodeBeg; 
  return (ButtonCode);

  } 
  
  unsigned long RCMM::readMid()
 {

ButtonCode = ButtonCodeMid; 
  return (ButtonCode);

  }
  
    unsigned long RCMM::readEnd()
 {

ButtonCode = ButtonCodeEnd; 
  return (ButtonCode);

  }
     unsigned long RCMM::readToggle()
 {

ButtonCode = ToggleBit; 
  return (ButtonCode);

  }
       unsigned long RCMM::readBit1()
 {

ButtonCode = LBit1; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit2()
 {

ButtonCode = LBit2; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit3()
 {

ButtonCode = LBit3; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit4()
 {

ButtonCode = LBit4; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit5()
 {

ButtonCode = LBit5; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit6()
 {

ButtonCode = LBit6; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit7()
 {

ButtonCode = LBit7; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit8()
 {

ButtonCode = LBit8; 
  return (ButtonCode);

  }

         unsigned long RCMM::readBit10()
 {

ButtonCode = LBit10; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit11()
 {

ButtonCode = LBit11; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit12()
 {

ButtonCode = LBit12; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit13()
 {

ButtonCode = LBit13; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit14()
 {

ButtonCode = LBit14; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit15()
 {

ButtonCode = LBit15; 
  return (ButtonCode);

  }
         unsigned long RCMM::readBit16()
 {

ButtonCode = LBit16; 
  return (ButtonCode);

  }
  
  
//==============================================================
  
//==============================================================  
unsigned long RCMM::IRin()
  {
	    
	 Bit = pulseIn(IR_PIN, HIGH,150000); // This is the line that watches for the incoming pulses. Since I don't have it set up as a interupt, i have a time out of 100000 micro seconds (100ms) so the program doesn't get hung up very long
                                   // on waiting for a pulse. It cant be set much lower than that because the longest pulse (the stop pulse) can be up to almost 90ms. If the time out is set lower than that then it will never see the Stop pulse.   
    
//-------------------Conversion----------------
if((Bit>ZEROmin)&&(Bit<ZEROmax))
{
  Bit = 0;
}
if((Bit>ONEmin)&&(Bit<ONEmax))
{
  Bit = 1;
}

if((Bit>TWOmin)&&(Bit<TWOmax))
{
  Bit = 2;
}

if((Bit>THREEmin)&&(Bit<THREEmax))
{
  Bit = 3;
}

if((Bit>FOURmin)&&(Bit<FOURmax))
{
  Bit = 4;
}
//------------------------   
    Bit17 = Bit;
  
   if (Bit17 != 4)//----------------------------------------------------------------------------------
   
  { 
    Bit1 = Bit2;
    Bit2 = Bit3;
    Bit3 = Bit4;
    Bit4 = Bit5;
    Bit5 = Bit6;
    Bit6 = Bit7;
    Bit7 = Bit8;
    Bit8 = TBit;
    TBit = Bit10;
    Bit10 = Bit11;
    Bit11 = Bit12;     
    Bit12 = Bit13;
    Bit13 = Bit14;
    Bit14 = Bit15;
    Bit15 = Bit16;
    Bit16 = Bit17;
  } 
	  
  }



