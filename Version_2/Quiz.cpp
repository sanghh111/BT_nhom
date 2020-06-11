#include"Quiz.h"
Quiz::Quiz(string content = "",int duration = 0)
{
	this->content=content;
	this->duration=duration;
	head=tail=NULL;
}

void Quiz::addQuestion(Question* temp)
{
	if(head==NULL)
	{
		head=tail=temp;
	}
	else
	{
		tail->setNext(temp);
		tail=temp;
	}
}

ostream& operator<<(ostream& out,Quiz& temp)
{
	out<<"-----------------------------"<<endl;
	out<<temp.content<<"\t"<<temp.duration<<endl;
	out<<"-----------------------------"<<endl;
	Question *t=temp.head;
	int i=1;
	while(t!=NULL)
	{
		cout<<"cau"<<i<<":	";
		cout<<*t;
		t=t->getNext();
		i++;
	}
	return out;
}

void Quiz::removeQuestion(int pos)
{
	Question* temp=head;
	if(pos==1)
	{
		if(head==tail)
		{
			head=tail=NULL;
		}
		else
		{
			head=head->getNext();
		}
	}
	else
	{
		Question* temp1;
		int count=2;
		temp=temp->getNext();
		temp1=head;
		while(count!=pos && temp)
		{
			temp1=temp;
			temp=temp->getNext();
			count++;
		}
		if(temp==tail)
		{
			tail=temp1;
			tail->setNext(NULL);
		}
		else if(temp)
		{
			temp1->setNext(temp->getNext());
			temp->setNext(NULL);
		}
	}
}

void Quiz::exportFile(string nameFile)
{
	nameFile="quiz/"+nameFile;
	ofstream out(nameFile.c_str());
	out<<content<<","<<duration<<endl;
	Question *temp=head;
//	int i=0;s
//	while(temp)
//	{
//		i++;
//		temp=temp->getNext();
//	}
//	out<<i;
//	temp=head;
	while(temp)
	{
		out<<temp->getContent()<<","<<temp->getType()<<endl;
		temp=temp->getNext();
	}
	out.close();
}

Quiz* Quiz::importFile(string nameFile)
{
	nameFile="quiz/"+nameFile;
	ifstream in(nameFile.c_str());
	string temp_str;
	int temp_int;
	bool temp_bool;
	getline(in,temp_str,',');
	in>>temp_int;
	
	in.close();
}
