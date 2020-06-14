#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Choice{
	Choice*next;
	string content;
	bool answer;
	public:
		Choice(string content,bool answer);
		Choice* get_next();
		void set_next(Choice *);
		string get_content();
		void set_content();
		bool get_answer();
		void set_answer(bool);
//		void set_makeChoose(bool);
//		bool get_makeChoose();
		friend class Question;
};
