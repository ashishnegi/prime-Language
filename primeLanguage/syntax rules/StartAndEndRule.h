#pragma once
#include "rule.h"

class StartAndEndRule :
	public Rule
{
public:
	StartAndEndRule(void);
	virtual bool isRuleFollowed(const void *_data, int sizeInBytes);
	virtual ~StartAndEndRule(void);
};
