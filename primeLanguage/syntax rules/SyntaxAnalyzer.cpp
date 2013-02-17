#include "SyntaxAnalyzer.h"

SyntaxAnalyzer::SyntaxAnalyzer(Rule **_rules, int sizeOfArray)
	:errorRuleIndex(-1)
{
	for(int i=0;i<sizeOfArray; ++i)
	{
		this->rules.push_back(_rules[i]);
	}
}

SyntaxAnalyzer::~SyntaxAnalyzer(void)
{
	this->rules.clear();
}

bool SyntaxAnalyzer::compileSyntax(const void *program, int sizeInBytes)
{
	for(int vit = 0, 
		vitEnd = this->rules.size(); vit < vitEnd; ++vit)
	{
		if(!this->rules[vit]->isRuleFollowed(program, sizeInBytes))
		{
			this->errorRuleIndex = vit; 
			return false;
		}
	}
	return true;
}

Rule *SyntaxAnalyzer::getErrorRule()
{
	int size = this->rules.size();
	if(this->errorRuleIndex < 0 || this->errorRuleIndex >= size)
	{
		NoErrorException exp;
		throw exp;
	}
	return this->rules[errorRuleIndex];
}