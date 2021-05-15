//Made By Yabkoy 2018/2019/2020
#include <LedControl.h>
#include <DS3231.h>

LedControl phisicalClock = LedControl(12,11,10,1);
DS3231 clock;
RTCDateTime now;

float editTimer = 0;

bool editMode = false;

unsigned int mainClock;

void displayOnScreen(String hereText);
void checkSecant(int hour1, int hour2, int minute1, int minute2, int wyznacz1, int wyznacz2, int hereType, String mainLetter);

int wyznacz[3];


enum stateOfLetter
{
	PAUSE = 0, LESSON = 1
};

enum modes
{
  TIMER = 0, CLOCK = 1, DATE = 2,
};

uint8_t tempMinutes = 0;
uint8_t tempHours = 0;

uint16_t tempYear = 2021;
uint8_t tempMonth = 1;
uint8_t tempDay = 1;
//enum mainModes
//{
//	NONE = -1, LICZNIK = 0, NORMALCLOCK = 1, DATE = 2,
//};


void displayOnScreen(String message)
{
  for(int i=0; i<=7; i++)
  {
    phisicalClock.setChar(0,i,message.charAt(7-i),false);
  }
}

//Classes Button: 
class Button
{
  private:
    uint8_t pin;
  public:
    Button(const uint8_t& pin) : pin(pin)
    {
      pinMode(pin, INPUT_PULLUP); 
    }
    
    uint8_t getValue() const
    {
      return digitalRead(pin);  
    }
};

Button btn1(2);
Button btn2(3);
Button btn3(4);

void checkSecant(int hour1, int hour2, int minute1, int minute2, int wyznacz1, int wyznacz2, int hereType, stateOfLetter letterID)
{
	
	now = clock.getDateTime();
    
    int seconds = now.second;
    int minutes = now.minute;
    int hour = now.hour;
	
	String mainLetter = "";
	
	if(letterID == 0)
	{
		mainLetter = "P";
	}
	else if(letterID == 1)
	{
		mainLetter = "L";
	}
	
    
    int once = true;
     
   
  
    String strMin;
    String strSec;

    switch(hereType)
    {
      case 1:
      {
          if (hour == hour1)
          {
            //Serial.println("CASE 1");
              if (once == true)
              {
                  wyznacz[1] = 59;
                  wyznacz[2] = 59;
                  wyznacz[0] = 59;
      
                  wyznacz[1] -= minutes;
                  wyznacz[0] -= seconds;
                  once = false;
              }

              strMin = String(wyznacz[1]);
              strSec = String(wyznacz[0]);

              if (wyznacz[0] < 10)
              {
                 strSec = "0" + strSec;
              }
      
              if (wyznacz[1] < 10)
              {
                strMin = "0" + strMin;
              }

              
              displayOnScreen("-"+strMin+"--"+strSec+"-");
              delay(1000);
              
          }
        
        
        break;  
      }

      
      case 2:
      {
          if (hour == hour1 && minutes > -1 && minutes < 45)
          {
            //Serial.println("CASE 2");
                   if (once == true)
                    {
                        wyznacz[1] = 59;
                        wyznacz[2] = 59;
                        wyznacz[0] = 59;
            
            
                        wyznacz[1] -= minutes;
                        wyznacz[0] -= seconds;
                        wyznacz[1] -= wyznacz1;
                        once = false;
                    }
                    String strSec = String(wyznacz[0]);
                    String strMin = String(wyznacz[1]);
                
                        if (wyznacz[0] < 10)
                        {
                           strSec = "0" + strSec;
                        }
                
                        if (wyznacz[1] < 10)
                        {
                      strMin = "0" + strMin;
                        }
                
                    displayOnScreen(mainLetter+"- "+strMin+"-"+strSec);
                    delay(1000);
                    
        }
        break;  
        
      }
      
      case 3:
      {
        if (hour == hour1 && minutes > minute1 || hour == hour2 && minutes < minute2)
        {
          //Serial.println("CASE 3");
            if (once == true)
            {
                wyznacz[1] = 59;
                wyznacz[2] = 59;
                wyznacz[0] = 59;
        
        
                wyznacz[1] -= minutes;
                wyznacz[0] -= seconds;
            }
            if (hour == hour1)
            {
                wyznacz[1] += wyznacz1;
            }
        
        
        
            if (hour == hour2)
            {
                wyznacz[1] -= wyznacz2;
            }
        
            once = false;
            
            String strSec = String(wyznacz[0]);
            String strMin = String(wyznacz[1]);
        
                if (wyznacz[0] < 10)
                {
                   strSec = "0" + strSec;
                }
        
                if (wyznacz[1] < 10)
                {
              strMin = "0" + strMin;
                }
        
            displayOnScreen(mainLetter+"- "+strMin+"-"+strSec);
            
            delay(1000);
            
        }
        break;  
      }
      case 4:
      {
          if (hour == hour1 && minutes > minute1 )
          {
            //Serial.println("CASE 4");
              if (once == true)
              {
      
                  wyznacz[1] = 59;
                  wyznacz[2] = 59;
                  wyznacz[0] = 59;
                  //print("Lekcja")
      
                  wyznacz[1] -= minutes;
                  wyznacz[0] -= seconds;
      
      
                  once = false;
              }
              String strSec = String(wyznacz[0]);
              String strMin = String(wyznacz[1]);
          
                  if (wyznacz[0] < 10)
                  {
                     strSec = "0" + strSec;
                  }
          
                  if (wyznacz[1] < 10)
                  {
                strMin = "0" + strMin;
                  }
          
              displayOnScreen(mainLetter+"- "+strMin+"-"+strSec);
              delay(1000);
              
          }
        break;  
      }
      case 5:
      {
        if (hour == hour1 && minutes > minute1 &&  minutes < minute2)
        {
            //Serial.println("CASE 5");
            if (once == true)
            {
    
                wyznacz[1] = 59;
                wyznacz[2] = 59;
                wyznacz[0] = 59;
                //print("Lekcja")
    
                wyznacz[1] -= minutes;
                wyznacz[0] -= seconds;
                wyznacz[1] -= wyznacz1;
    
                once = false;
            }
            String strSec = String(wyznacz[0]);
            String strMin = String(wyznacz[1]);
        
                if (wyznacz[0] < 10)
                {
                   strSec = "0" + strSec;
                }
        
                if (wyznacz[1] < 10)
                {
              strMin = "0" + strMin;
                }
        
            displayOnScreen(mainLetter+"- "+strMin+"-"+strSec);
            delay(1000);
            
        }
        
        break;  
      }
      
      default:
      {
          if(hour >= hour1 || hour < hour2 || hour == hour1-1 && minutes > minute1)
          {

            displayOnScreen("--------");
            delay(1000);
            displayOnScreen("D-------");
            delay(1000);
            displayOnScreen("nD------");
            delay(1000);
            displayOnScreen("EnD-----");
            delay(1000);
            displayOnScreen("-EnD----");
            delay(1000);
            displayOnScreen("--EnD---");
            delay(1000);
            displayOnScreen("---EnD--");
            delay(1000);
            displayOnScreen("----EnD-");
            delay(1000);
            displayOnScreen("-----EnD");
            delay(1000);
            displayOnScreen("------En");
            delay(1000);
            displayOnScreen("-------E");
            delay(1000);
          }
            
        
        
        break;  
      }
      
    }
    
     //Serial.println(String(hour)+":"+String(minutes)+":"+String(seconds));  
}

void testMode(int forSwitch)
{
    switch(forSwitch)
    {
      case 1:
      {
        clock.setDateTime(2020, 9, 16, 6, 59, 58); //1
        break;
      }
      case 2:
      {
        clock.setDateTime(2020, 9, 16, 7, 59, 57); //2
        break;
      }
      case 3:
      {
        clock.setDateTime(2020, 9, 16, 8, 44, 57); //3
        break;
      }
      case 4:
      {
        clock.setDateTime(2020, 9, 16, 8, 49, 57); //4
        break;
      }
      case 5:
      {
        clock.setDateTime(2020, 9, 16, 8, 59, 57); //5
        break;
      }
      case 6:
      {
          clock.setDateTime(2020, 9, 16, 9, 34, 57); //6
          break;
      }
      case 7:
      {
        clock.setDateTime(2020, 9, 16, 9, 39, 57); //7
        break;
      }
      case 8:
      {
        clock.setDateTime(2020, 9, 16, 9, 59, 57); //8
        break;
      }
      case 9:
      {
        clock.setDateTime(2020, 9, 16, 10, 24, 57); //9
        break;
      }
      case 10:
      {
        clock.setDateTime(2020, 9, 16, 10, 44, 57); //10
        break;
      }
      case 11:
      {
        clock.setDateTime(2020, 9, 16, 10, 59, 57); //11
        break;
      }
      case 12:
      {
        clock.setDateTime(2020, 9, 16, 11, 29, 57); //12
        break;
      }
      case 13:
      {
        clock.setDateTime(2020, 9, 16, 11, 39, 57); //13
        break;
      }
      case 14:
      {
        clock.setDateTime(2020, 9, 16, 11, 59, 57); //14
        break;
      }
      case 15:
      {
        clock.setDateTime(2020, 9, 16, 12, 24, 57); //15
        break;
      }
      case 16:
      {
        clock.setDateTime(2020, 9, 16, 12, 34, 57); //16
        break;
      }
      case 17:
      {
        clock.setDateTime(2020, 9, 16, 12, 59, 57); //17
        break;
      }
      case 18:
      {
        clock.setDateTime(2020, 9, 16, 13, 19, 57); //18
        break;
      }
      case 19:
      {
        clock.setDateTime(2020, 9, 16, 13, 24, 57); //19
        break;
      }
      case 20:
      {
        clock.setDateTime(2020, 9, 16, 13, 59, 57); //20
        break;
      }
      case 21:
      {
        clock.setDateTime(2020, 9, 16, 14, 9, 57); //21
        break;
      }
      case 22:
      {
        clock.setDateTime(2020, 9, 16, 14, 14, 57); //22
        break;
      }
      case 23:
      {
        clock.setDateTime(2020, 9, 16, 14, 59, 57); //23
        break;
      }
      case 24:
      {
        clock.setDateTime(2020, 9, 16, 15, 4, 57); //24
        break;
      }
      case 25:
      {
        clock.setDateTime(2020, 9, 16, 15, 49, 57); //25
        break;
      }
    }
}

void setup() 
{
  
	Serial.begin(9600);
	
	phisicalClock.shutdown(0,false);
	
	phisicalClock.setIntensity(0,2);
	
	phisicalClock.clearDisplay(0);

	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

  
  clock.begin();  
}


modes mainModes = 2;


void loop() 
{ 

	if(mainClock%10 == 0) { now = clock.getDateTime(); }

    //phisicalClock.clearDisplay(0);
  
    // Lub recznie (YYYY, MM, DD, HH, II, SS
    //clock.setDateTime(2020, 9, 15, 10, 14, 00);
    //clock.setDateTime(2020, 9, 27, 20, 8, 0);

      //1 7 Prep
      //5 - Przerwy
      //6 END
		
	//#######BUTTONTEST###############
	// if(btn1.getValue() == 0)
	// {
		// digitalWrite(5, HIGH);  
	// }
	// else
	// {
		// digitalWrite(5, LOW); 
	// }

	// if(btn2.getValue() == 0)
	// {
		// digitalWrite(6, HIGH);  
	// }
	// else
	// {
		// digitalWrite(6, LOW); 
	// }
	// if(btn3.getValue() == 0)
	// {
		// digitalWrite(7, HIGH);  
	// }
	// else
	// {
		// digitalWrite(7, LOW); 
	// }
	//#######BUTTONTEST###############


    
	if(editMode == false)
	{
		if(btn3.getValue() == 0)
		{
		   if(mainClock%100 == 0) 
		   {
			  switch(mainModes)
			  {
				case 0:
				{
					mainModes = 1;
					break;
				}
				case 1:
				{
					mainModes = 2;
					break;
				}
				case 2:
				{
					mainModes = 0;
					break;
				}
			  }
		   }

		}
		
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
			
			Serial.println("EDIT");
			digitalWrite(7, HIGH);  
			delay(1000);
			digitalWrite(7, LOW);  
		}
	   switch(mainModes)
	   {
		  case 0:
		  {
			break;
		  }
		  case 1:
		  {
			Serial.println(String(now.hour)+"-"+String(now.minute)+"-"+String(now.second));
			//displayOnScreen(String(now.hour)+"-"+String(now.minute)+"-"+String(now.second));
			break;
		  }
		  case 2:
		  {
			Serial.println(String(now.year)+" - "+String(now.month)+" - "+String(now.day));
			//displayOnScreen(String(now.year)+String(now.month)+String(now.day));
			break;
		  } 
	   }
		
	}
	else
	{
		switch(mainModes)
		{
			case 1:
			{
				if(btn1.getValue() == 0 && mainClock%15 == 0)
				{
				  tempMinutes++;
				  if(tempMinutes > 59)
					tempMinutes = 0;
				}
				if(btn2.getValue() == 0 && mainClock% 15== 0)
				{
				  tempHours++;
				  if(tempHours > 23)
					tempHours = 0;
				}
				Serial.println(String(tempHours)+"-"+String(tempMinutes));
				
				break;
			}
			case 2:
			{
				if(btn1.getValue() == 0 && btn2.getValue() == 0 && mainClock% 15== 0)
				{
				  tempYear++;
				  if(tempYear > 2037)
					tempYear = 2021;
				}
				if(btn1.getValue() == 0 && btn2.getValue() == 1 && mainClock%15 == 0)
				{
				  tempMonth++;
				  if(tempMonth > 12)
					tempMonth = 1;
				}
				if(btn2.getValue() == 0 && btn1.getValue() == 1 && mainClock% 15== 0)
				{
				  tempDay++;
				  if(tempDay > 31)
					tempDay = 1;
				}
				
				Serial.println(String(tempYear)+" - "+String(tempMonth)+" - "+String(tempDay));
				
				break;
			}
		}
		if(btn3.getValue() == 0)
		{
		  editMode = false;  
		  clock.setDateTime(tempYear, tempMonth, tempDay, tempHours, tempMinutes, 0);
		  Serial.println("DONE");
		  digitalWrite(7, HIGH);  
		  delay(1000);
		  digitalWrite(7, LOW);  
		}

	}


  
      // checkSecant(7,0,0,0,0,0, 1, NONE);
      // checkSecant(8,0,-1,45,15,0, 2, LESSON);
      // checkSecant(8,9,49,35,35,25, 3, LESSON);
      // checkSecant(9,10,39,25,25,35, 3, LESSON);
      // checkSecant(10,11,44,30,30,30, 3, LESSON);
      // checkSecant(11,12,39,25,25,35, 3, LESSON);
      // checkSecant(12,13,34,20,20,40, 3, LESSON);
      // checkSecant(13,14,24,10,10,50, 3, LESSON);
      // checkSecant(14,0,14,0,0,0, 4, LESSON);
      
      // checkSecant(15,0,4,50,10,0, 5, LESSON); //LESSON
      
      // checkSecant(8,0,44,50,10,0, 5, PAUSE);
      // checkSecant(9,0,34,40,20,0, 5, PAUSE);
      // checkSecant(10,0,24,45,15,0, 5, PAUSE);
      // checkSecant(11,0,29,40,20,0, 5, PAUSE);
      // checkSecant(12,0,24,35,25,0, 5, PAUSE);
      // checkSecant(13,0,19,25,35,0, 5, PAUSE);
      // checkSecant(14,0,9,15,45,0, 5, PAUSE);
      // checkSecant(15,0,-1,5,55,0, 5, PAUSE);
      // checkSecant(16,7,49,5,0,0, 6, NONE);
      mainClock++;

}
