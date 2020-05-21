#include"Question.cpp"
main()
{
	Question *Q=new Question("2+2=?");
	Choice *C=new Choice("4");
	Q->addChoice(C);
	Quiz *Qi=new Quiz("test nhanh",120);;
	Qi->addQuestion(Q);
	Qi->importFromFile("test1");
	 Qi=new Quiz();
	Qi->exportToFile("test1");
	cout<<*Qi;
}
