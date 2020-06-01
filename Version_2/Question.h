#pragma once
#include<iostream>
#include<string.h>
using namespace std;
#include"Choice.h"
class Question{
	bool type;
	string content;
	int count_answer,count_choice;
	Choice* head,*tail;
	float point;
	public:
		Question(string,bool);
		Choice* fineTrueChoice();
		void makeTrueChoice(int);
		void addChoice(Choice*);
		void updateChoice(int,Choice*);
		void removeChoice(int);
		friend ostream& operator<<(ostream&,Question&);
		friend istream& operator>>(istream&,Question&);
		Question& operator+(Choice *);
		Question& operator-(int );
		int get_count_answer();
//        Question& operator=(Question *);
};
