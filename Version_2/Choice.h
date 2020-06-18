#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Choice{
	Choice*next;//vi tri tiep theo cua Choice
	string content;//Noi dung cau Choice
	bool answer;//0 là cau sai con la  cau dung
	public:
		Choice(string content,bool answer);
		Choice* get_next();
		void set_next(Choice *);
		string get_content();
		void set_content();
		bool get_answer();
		void set_answer(bool);
		friend class Question;
};
