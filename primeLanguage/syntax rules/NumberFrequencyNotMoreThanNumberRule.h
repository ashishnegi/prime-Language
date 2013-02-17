#pragma once
#include "rule.h"

class NumberFrequencyNotMoreThanNumberRule :
	public Rule
{
public:
	NumberFrequencyNotMoreThanNumberRule(void);
	virtual bool isRuleFollowed(const void *_data, int sizeInBytes);
	virtual ~NumberFrequencyNotMoreThanNumberRule(void);
};
