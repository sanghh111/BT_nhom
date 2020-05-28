#pragma once
#include"Question.h"
class Choice{
	Choice*next;
	string content;
	bool answer;
	public:
		Choice(string,bool);
		friend class Question;
};
