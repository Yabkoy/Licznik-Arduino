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
			//COPY THIS:
              strSec = String(wyznacz[0]);
              strMin = String(wyznacz[1]);

              if (wyznacz[0] < 10)
              {
                 strSec = "0" + strSec;
              }
      
              if (wyznacz[1] < 10)
              {
                strMin = "0" + strMin;
              }

              
              displayOnScreen("-"+strMin+"--"+strSec+"-"); //OTHER
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
					//COPY THIS:
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
            //COPY THIS:
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
			  //COPY THIS:
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
			//COPY THIS:
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