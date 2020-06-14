#pragma once
#include"Question.h"
#include<fstream>
class Quiz
{
	int duration;
	Question* head,*tail;
	string content;
	public:
		Quiz(string,int);
		void addQuestion(Question*);
		void removeQuestion(int);
		void exportFile(string);
		void importFile(string);
		string get_content();
		Question* get_Head();
		friend ostream& operator<<(ostream&,Quiz&);
};
