#include"Choice.h"
class Question{
	bool type;//type=0 once choice, type=1 muti
	string content;
	int count_answer;
	Choice *head,*tail;
	Question *next;
	float point;
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
