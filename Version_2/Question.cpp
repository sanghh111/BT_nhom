#include"Question.h"
Question::Question(string content="",bool type=0)
{
	count_answer=0;
	this->content=content;
	this->type;
	head=this->tail=NULL;
}

void Question::addQuestion(Choice*temp)
{
	if(head=NULL)
	{
		head=tail=temp;
	}
	else{
		tail->next=temp;
		tail=temp;
	}
}

void Question::updateQuestion(int pos,Choice * temp)
{
	Choice *temp_f=head;
	if(pos==0)
	{
		if(head!=NULL)
		{
			head=temp;
			temp->next=head->next;
			delete temp_f;
		}
	}
}
