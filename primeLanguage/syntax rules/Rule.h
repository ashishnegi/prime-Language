#pragma once

#include <string>

class Rule
{
protected:
	bool isFollowed;
	bool hasChecked;
	std::string name;
public:
	Rule(void);
	Rule(std::string _name);
	/*
	Arguments:
	size: this size in bytes. //TODO: make this sizeInBytes const too
	*/
	virtual bool isRuleFollowed(const void *_data, int sizeInBytes)=0;
	virtual ~Rule(void);
	std::string getName();
};
