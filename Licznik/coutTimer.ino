

timeUnit timerArray[19] = 
{
	{7, 0, 0}, {8, 0, 0},
	{8, 45, 0}, {8, 50, 0}, 
	{9, 35, 0}, {9, 40, 0},  
	{10, 25, 0}, {10, 45, 0},
	{11, 30, 0},  {11, 40, 0}, 
	{12, 25, 0}, {12, 35, 0}, 
	{13, 20, 0}, {13, 25, 0}, 
	{14, 10, 0}, {14, 15, 0}, 
	{15, 0, 0}, {15, 5, 0}, 
	{15, 50, 0}, 
};

void lessonTime()
{
  for(int i=0; i<(sizeof(timerArray)/timer); i++)
  {
    if(timerArray[i] < nowTime && timerArray[i+1] > nowTime)
    {
      Serial.println(String( getCooldown(, nowTime timerArray[i+1]) ));
    }
  }
}


timeUnit getCooldown(timeUnit beginTimer, timeUnit endTimer)
{
	int totalTime[2];
	int resultSec = 0;

	beginTimer.hour *= 3600;
	beginTimer.minute *= 60;

	endTimer.hour *= 3600;
	endTimer.minute *= 60;

	totalTime[0] = beginTimer.hour + beginTimer.minute + beginTimer.sec;
	totalTime[1] = endTimer.hour + endTimer.minute + endTimer.sec;
	resultSec = totalTime[1] - totalTime[0];

	int resHour = int(resultSec/3600);
	int resMinute = intresultSec - resHour * 3600)) / 60);
	int resSec = resultSec - ((resHour  * 3600)+(resMinute*60));

	timeUnit result = {resHour, resMinute, resSec};
	return result;
}
