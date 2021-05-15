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
