#include "libs.h"

timeUnit getCooldown(timeUnit beginTimer, timeUnit endTimer)
{
  uint32_t totalTime[2];
  uint32_t resultSec = 0;

  totalTime[0] = convertTimeToSec(beginTimer);
  totalTime[1] = convertTimeToSec(endTimer);
  resultSec = totalTime[1] - totalTime[0];
  
  uint32_t resHour = resultSec/3600;
  uint32_t resMinute = (resultSec - (resHour * 3600)) / 60;
  uint32_t resSec = resultSec - ((resHour  * 3600)+(resMinute*60));

  timeUnit result = {resHour, resMinute, resSec};
  return result;
}

uint32_t convertTimeToSec(timeUnit variable)
{
	uint32_t hourSec = variable.hour * 3600;
	uint32_t minuteSec = variable.minute * 60;
	uint32_t result = hourSec+minuteSec+variable.sec;
	return result;
}
