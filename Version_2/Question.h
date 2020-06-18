#include"Choice.h"
class Question{
	bool type;//type=0 once choice, type=1 muti
	string content;//noi dung question
	int count_answer;//dem so cau dunmg
	Choice *head,*tail;//con tro dau và con tro? cuo^'i va' con tro? cuo^'i
	Question *next;//co tro next danh cho Quiz
	float point;//diem cua cau hoi
	public:
		Question(string,bool);
		Choice* fineTrueChoice();
		void makeTrueChoice(int);
		void addChoice(Choice*);
		void updateChoice(int,Choice*);
		void removeChoice(int);
		bool checkChoice(int);
		friend ostream& operator<<(ostream&,Question&);
		friend istream& operator>>(istream&,Question&);
		Question& operator+(Choice *);
		Question& operator-(int );
		void display();
		float getPointe(float);
		int get_count_answer();
//      Question& operator=(Question *);
		Question* getNext();
		void setNext(Question *);
//		friend class Quiz;
		string getContent();
		bool getType();
		Choice* getHead();
};
