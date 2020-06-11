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
	int i=0;
	while(temp)
	{
		i++;
		temp=temp->getNext();
	}
	out<<i<<endl;
	temp=head;
	Choice* tempChoice;
	while(temp)
	{
		out<<temp->getContent()<<","<<temp->getType()<<endl;
		tempChoice=temp->getHead();
		i=0;
		while(tempChoice)
		{
			i++;
			tempChoice=tempChoice->get_next();
		}
		out<<i<<endl;
		tempChoice=temp->getHead();
		while(tempChoice)
		{
			out<<tempChoice->get_content()<<",";
			tempChoice=tempChoice->get_next();
		}
		out<<endl;
		tempChoice=temp->getHead();
		while(tempChoice)
		{
			out<<tempChoice->get_answer()<<",";
			tempChoice=tempChoice->get_next();
		}
		tempChoice=temp->getHead();
		out<<endl;
		temp=temp->getNext();
	}
	out.close();
}

void Quiz::importFile(string nameFile)
{
	nameFile="quiz/"+nameFile;
	ifstream in(nameFile.c_str());
	string temp_str;
	int temp_int;
	bool temp_bool;
	getline(in,temp_str,',');
	in>>temp_int;
	content=temp_str;
	duration=temp_int;
	getline(in,temp_str);
	Question* tempQ;
	Choice * tempC;
	int temp_cq,i,j;
	in>>temp_cq;
//	cout<<temp_cq;
	getline(in,temp_str);
	for(i=0;i<temp_cq;i++)
	{
		getline(in,temp_str,',');
		in>>temp_bool;
//		cout<<temp_bool;
		tempQ= new Question(temp_str,temp_bool);
		addQuestion(tempQ);
		in>>temp_int;
		getline(in,temp_str);
		for(int j=0;j<temp_int;j++)
		{
			getline(in,temp_str,',');
			tempC=new Choice(temp_str,0);
			tempQ->addChoice(tempC);
		}
		getline(in,temp_str);
		for(int j=0;j<temp_int;j++)
		{
			in>>temp_bool;
			if(temp_bool)
			tempQ->makeTrueChoice(j+1);
			getline(in,temp_str,',');
		}
		getline(in,temp_str);
	}
	in.close();
}
