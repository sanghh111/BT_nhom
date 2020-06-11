#include"Quiz.h"
main()
{
	Quiz *q;
	q = new Quiz("test",4);
	Question* Q;
	Q=new Question("2+2=?",0);
	q->addQuestion(Q);
//	cout<<*q;
	Choice *C;
	C=new Choice("4",1);
	Q->addChoice(C);
	C=new Choice("5",1);
	Q->addChoice(C);
//	cout<<*q;
	Q=new Question("sang",1);
	q->addQuestion(Q);
	Q=new Question("Duyen",0);
	q->addQuestion(Q);
	cout<<*q;
//	q->removeQuestion(2);
//	q->removeQuestion(1);
	cout<<*q;
	q->exportFile("testnhanh.quiz");
	q=new Quiz("",0);
	q->importFile("testnhanh.quiz");
	cout<<*q;
}
