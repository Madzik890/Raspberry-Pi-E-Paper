#include "Keys.hpp"
#include <wiringPi.h>
#include <unistd.h>//usleep

/// <summary>
/// Prepares raspberry PI pins to work.
/// </summary>
void initKeys()
{
	pinMode(KEY1_PIN, INPUT); 
	pinMode(KEY2_PIN, INPUT); 
}

/// <summary>
/// Gets which key is pressed.
/// <summary>
/// <return> A pressed button </return>
int getKeyInput()
{
	if (digitalRead(KEY1_PIN) == 0 && digitalRead(KEY2_PIN) == 0)
		return 3;
	else
	if (digitalRead(KEY1_PIN) == 0)
		return 1;
	else
	if (digitalRead(KEY2_PIN) == 0)
		return 2;
	
	return -1;//if no keys are not pressed, return -1
}
