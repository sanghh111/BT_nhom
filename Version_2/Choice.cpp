#include"Choice.h"
Choice::Choice(string content="",bool answer=0)
{
	this->content=content;
	this->answer=answer;
	next=NULL;
}
