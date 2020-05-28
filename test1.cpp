#include"Question.cpp"
main()
{
	// Question *Q= new Question(" 3+3= ?");
	// Choice *a=new Choice("mot");
	// Choice *b=new Choice("hai");
	// Quiz *q=new Quiz("test nhanh");
	// q->addQuestion(Q);
	// Q->addChoice(a);Q->addChoice(b);
	// Q= new Question("3+3=?");
	// a=new Choice("1mot");
	// b=new Choice("hai");
	// Q->addChoice(a);Q->addChoice(b);
	// q->addQuestion(Q);
	// q->importFromFile("test1.txt");
	// q=new Quiz();
	Quiz *q=new Quiz();
	q->exportToFile("test1.txt");
	cout<<*q;
}