#include "Rule.h"

Rule::Rule(std::string _name):name(_name),isFollowed(false),hasChecked(false)
{
}

Rule::Rule(void):name("No_Name"),isFollowed(false),hasChecked(false)
{
}

Rule::~Rule(void)
{
}

/*
bool Rule::isRuleFollowed(const void *_data, int sizeInBytes)	
{
	std::cout << "\nNoRule called :P\n";
	return false;
}
*/

std::string Rule::getName()
{
	return this->name;
}