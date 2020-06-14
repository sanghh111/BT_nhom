#include"Quiz.h"
#include<vector>
#include<ctime>
class Student
{
	string name,id;
	public:
		Student(string,string);
		void check_quiz();
		void do_quiz(string);
};
