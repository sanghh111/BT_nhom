#include"Choice.h"
Choice::Choice(string content="",bool answer=false)
{
	this->content=content;
	this->answer=answer;
	next=NULL;
}

Choice* Choice::get_next()
{
	return next;
}

string Choice::get_content()
{
	return content;
}

bool Choice::get_answer()
{
	return answer;
}

void Choice::set_answer(bool answer)
{
	this->answer=answer;
}
