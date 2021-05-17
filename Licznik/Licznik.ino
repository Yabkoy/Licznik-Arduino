//Made By Yabkoy 2018/2019/2020/2021
#include "libs.h"

//Library Varable Declaration: 
LedControl phisicalClock = LedControl(12,11,10,1);
DS3231 clock;
RTCDateTime now;

//Main Modes Enum for clock:
enum modes
{
  TIMER = 0, CLOCK = 1, DATE = 2,
};
//myClock Vable Declaration:
uint8_t mainClock;

//Edit menagement Varable Declaration:
uint8_t editTimer = 0;
bool editMode = false;

//Edit Time Varable Declaration:
uint8_t tempMinutes = 0;
uint8_t tempHours = 0;

uint16_t tempYear = 2021;
uint8_t tempMonth = 1;
uint8_t tempDay = 1;

//Display string on display
void displayOnScreen(String message)
{
  for(int i=0; i<8; i++)
  {
    bool dpValue;
    if(message[i+1] == '.')
    {
      dpValue = true;
      message.remove(i+1, 1);
    }
    else
    {
      dpValue = false;
    }
    
    phisicalClock.setChar(0,7-i,message[i],dpValue);
  }
}

//Mode selecting function
void actionOnSelectButtonClick(String message)
{
  displayOnScreen(message);
  digitalWrite(7, HIGH);  
  delay(1000);
  digitalWrite(7, LOW);  
}

//Zero inserting in number below 10
String insertZero(uint8_t number)
{
	return (number < 10)? "0"+String(number) : String(number);
}

//Button Declaration
Button btn1(2);
Button btn2(3);
Button btn3(4);

//Main Enum Mode declaration
modes mainModes = 0;

//Setup
void setup() 
{
	
	phisicalClock.shutdown(0,false);
	
	phisicalClock.setIntensity(0,2);
	
	phisicalClock.clearDisplay(0);

	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

  
	clock.begin();  
}

//Main Loop
void loop() 
{ 
  //Clock variable updating;
	if(mainClock%10 == 0) 
	{ 
		now = clock.getDateTime(); 
		nowTime = {now.hour, now.minute, now.second};
	}
  //In non-edit mode:
	if(editMode == false)
	{
    //Mode Selecting:
		if(btn3.getValue() == 0)
		{

		  switch(mainModes)
		  {
			case 0:
			{
				mainModes = 1;
				actionOnSelectButtonClick("--CZAS--");
				break;
			}
			case 1:
			{
				mainModes = 2;
				actionOnSelectButtonClick("--DATA--");
				break;
			}
			case 2:
			{
				mainModes = 0;
				actionOnSelectButtonClick("-COUNT--");
				break;
			}
		  }
		   

		}
   
		//Entering Edit Mode
		if(btn1.getValue() == 0 && btn2.getValue() == 0 && btn3.getValue() == 1 && mainModes)
		{
			editTimer += 1;
		}
		else
		{
			editTimer = 0;
		}
		
		//Enter Edit Mode
		if(editTimer > 100)
		{
			editMode = true;
			editTimer = 0;
			
			tempYear = now.year;
			tempMonth = now.month;
			tempDay = now.day;
			
			tempMinutes = now.minute;
			tempHours = now.hour;
			
      actionOnSelectButtonClick("--EDIT--");
		}
    //Display for Modes
	   switch(mainModes)
	   {
		  case 0:
		  {
			static bool hasBeen = false;
			for(int i=0; i<18; i++)
			{
				if(convertTimeToSec(timerArray[i]) < convertTimeToSec(nowTime) && convertTimeToSec(timerArray[i+1]) > convertTimeToSec(nowTime))
				{
					timeUnit result = getCooldown(nowTime, timerArray[i+1]);

					// String strHour = (result.hour < 10)? "0"+String(result.hour) : String(result.hour);
					// String strMinute = (result.minute < 10)? "0"+String(result.minute) : String(result.minute);
					// String strSec = (result.sec < 10)? "0"+String(result.sec) : String(result.sec);
					
					//SERIALSerial.println(strHour + ":" + strMinute + ":" + strSec);
					displayOnScreen("--" + insertZero(result.minute) + "." + insertZero(result.sec)+ "--");
					hasBeen = true;
				}
			}
			if(!hasBeen)
			{
				displayOnScreen("NO.LESSON");
			}
			if(hasBeen == true)
      {
        hasBeen = false;
      }
			
			
			break;
		  }
		  case 1:
		  {
			displayOnScreen(insertZero(nowTime.hour)+"-"+insertZero(nowTime.minute)+"-"+insertZero(nowTime.sec));
			break;
		  }
		  case 2:
		  {
			displayOnScreen(String(now.year)+"."+insertZero(now.month)+"."+insertZero(now.day));
  			break;
		  } 
	   }
		
	}
	else //EDIT MODE:
	{
    //Setting Vars:
		switch(mainModes)
		{
			case 1:
			{
				if(btn1.getValue() == 0 && mainClock%35 == 0)
				{
				  tempMinutes++;
				  if(tempMinutes > 59)
					tempMinutes = 0;
				}
				if(btn2.getValue() == 0 && mainClock%50== 0)
				{
				  tempHours++;
				  if(tempHours > 23)
					tempHours = 0;
				}
				//SERIAL(Serial.println(String(tempHours)+"-"+String(tempMinutes)));
				displayOnScreen("--"+insertZero(tempHours)+"."+insertZero(tempMinutes)+"--");
				
				break;
			}
			case 2:
			{
				if(btn1.getValue() == 0 && btn2.getValue() == 0 && mainClock% 35== 0)
				{
				  tempYear++;
				  if(tempYear > 2037)
					tempYear = 2021;
				}
				if(btn1.getValue() == 1 && btn2.getValue() == 0 && mainClock%35 == 0)
				{
				  tempMonth++;
				  if(tempMonth > 12)
					tempMonth = 1;
				}
				if(btn1.getValue() == 0 && btn2.getValue() == 1 && mainClock% 35== 0)
				{
				  tempDay++;
				  if(tempDay > 31)
					tempDay = 1;
				}
				
				//SERIAL(Serial.println(String(tempYear)+" - "+String(tempMonth)+" - "+String(tempDay)));
				displayOnScreen(String(tempYear)+"."+insertZero(tempMonth)+"."+insertZero(tempDay));
				
				break;
			}
		}

   //Comfirm Func:
		if(btn3.getValue() == 0)
		{
		  editMode = false;  
		  clock.setDateTime(tempYear, tempMonth, tempDay, tempHours, tempMinutes, 0);
		  actionOnSelectButtonClick("--DONE--");
		}

	}
      mainClock++;

}
