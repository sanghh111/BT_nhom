#pragma once
#include"Question.h"
#include<fstream>
#include <cstdlib>
#include<sstream>
class Quiz
{
	int duration;// thoi gian
	Question* head,*tail;//head :dau ;tail :cuoi
	string content;//noi dung
	public:
		Quiz(string,int);
		void addQuestion(Question*);//them cau hoi
		void removeQuestion(int);//xoa file
		void exportFile(string);//xuat file
		void importFile(string);//nhap file
		string get_content();//
		Question* get_Head();
		friend ostream& operator<<(ostream&,Quiz&);// xuat tra loi ra man hinh 
};
