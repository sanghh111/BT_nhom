#include"Question.h"
using namespace std;

int main()
{
	Question *Q;
	Q= new Question("2+2",1);
	Choice *C;
	C=new Choice("2",1);
	Q->addChoice(C);
	C=new Choice("3",1);
	*Q+C;
	C=new Choice("4",0);
	Q->addChoice(C);
	C=new Choice("4",0);
	Q->updateChoice(2,C);
	C=new Choice("3",1);
	*Q+C;
	cout<<*Q;
	return 0;
}
