#include "StartAndEndRule.h"
#include <iostream>
StartAndEndRule::StartAndEndRule(void):Rule("StartAndEndRule")
{
}

StartAndEndRule::~StartAndEndRule(void)
{
}

bool StartAndEndRule::isRuleFollowed(const void *_data, int sizeInBytes)
{
	if(this->hasChecked)
		return isFollowed;
	int *data = (int *)_data;
	int size = sizeInBytes/sizeof(int);
	//std::cout << data[0] << data[size-1] << std::endl;
	
	if(data[0] == 2 && data[size-1] == 2)
		isFollowed = true;
	else
		isFollowed = false;
	hasChecked = true;
	return isFollowed;
}