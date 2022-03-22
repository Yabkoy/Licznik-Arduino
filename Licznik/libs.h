#ifndef LIBS_H
#define LIBS_H

#include <LedControl.h>
#include <DS3231.h>

//time Unit Declaration
struct timeUnit
{
  uint8_t hour;
  uint8_t minute;
  uint8_t sec;  
};

timeUnit nowTime;


//Button Class Definition
class Button
{
  private:
    uint8_t pin;
  public:
    Button(const uint8_t& pin);
    
    uint8_t getValue() const;
};

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

timeUnit getCooldown(timeUnit beginTimer, timeUnit endTimer);
uint32_t convertTimeToSec(timeUnit variable);

#endif
