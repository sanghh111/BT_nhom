#pragma once
#include<iostream>
#include<string.h>
using namespace std;
#include"Choice.h"
class Question{
	bool type;
	string content;
	int count_answer;
	Choice* head,*tail;
	public:
		Question(string,bool);
		void makeQuestion(int);
		void addQuestion(Choice*);
		void updateQuestion(int,Choice *);
		void removeQuestion(int);
		friend ostream& operator<<(ostream,Question);
		friend ostream& operator>>(ostream,Question);
};
