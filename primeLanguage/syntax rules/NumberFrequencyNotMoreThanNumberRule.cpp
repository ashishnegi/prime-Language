#include "NumberFrequencyNotMoreThanNumberRule.h"
#include <map>

NumberFrequencyNotMoreThanNumberRule::
NumberFrequencyNotMoreThanNumberRule(void):Rule("NumberFrequencyNotMoreThanNumberRule")
{
	//
}

NumberFrequencyNotMoreThanNumberRule::
	~NumberFrequencyNotMoreThanNumberRule(void)
{
	//
}

bool NumberFrequencyNotMoreThanNumberRule::isRuleFollowed(const void *_data, int sizeInBytes)
{
	if(this->hasChecked)
		return this->isFollowed;

	int *data = (int *)_data;
	int size = sizeInBytes/sizeof(int);
	std::map<int,int> countInt;
	
	for(int i=0;i<size;++i)
	{
		++countInt[data[i]];
	}
	
	this->isFollowed = true;
	
	for(std::map<int,int>::iterator mit = countInt.begin(); mit != countInt.end(); ++mit)
	{
		if(mit->first < mit->second)
		{
			this->isFollowed = false;
			break;
		}
	}
	
	this->hasChecked = true;
	return isFollowed;
}