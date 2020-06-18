#include"Quiz.h"
#include<vector>
#include<ctime>
#include <dirent.h>
class Student
{
	string name,id;
	public:
		Student(string,string);
		string choose_quiz(string);
		void do_quiz(string);
};
