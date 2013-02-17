#pragma once
#include <vector>
#include "Rule.h"
// #include <boost/shared_ptr.hpp>

class SyntaxAnalyzer
{
	//std::vector<boost::shared_ptr<Rule> > rules;
	std::vector<Rule *> rules;
	int errorRuleIndex;
public:
	class NoErrorException{};
	SyntaxAnalyzer(Rule **_rules, int sizeOfArray);
	virtual bool compileSyntax(const void *program, int sizeInBytes);
	Rule *getErrorRule();
	~SyntaxAnalyzer(void);
};
