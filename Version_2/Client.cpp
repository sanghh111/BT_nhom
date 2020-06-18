#include"Quiz.h"
#include"Student.h"
int menu()
{

	int n=0,temp_n;
	Quiz* q=new Quiz("",0);
	Question *Q=new Question("",0);
	Choice* C;
	string temp,temp1,temp2;
	bool temp_b;
	while (n!=9)
	{
		system("cls");
		cout<<"1.Khoi tao de thi."<<endl;
		cout<<"2 Them cau hoi vao de thi."<<endl;
		cout<<"3 Them lua chon vao cau hoi thu n"<<endl;
		cout<<"4 Xoa cau hoi thu n"<<endl;
		cout<<"5 Xoa lua chon thu n cua cau thu k"<<endl;
		cout<<"6 Xuat de thi"<<endl;
		cout<<"7 Luu de thi vao trong file"<<endl;
		cout<<"8 Lam bai thi"<<endl;
		cout<<"9 Ket thuc"<<endl;
		cout<<"Nhap tu 1-9: ";
		cin>>n;
		cin.ignore();
		switch (n)
			{
			case 1:
				{
					cout<<"Nhap ten bai thi: "; getline(cin,temp);
					cout<<"Nhap thoi gian lam bai thi: ";cin>>temp_n;
					q=new Quiz(temp,temp_n);
					break;
				}
			case 2:
				{
					Q=new Question("",0);
					cin>>*Q;
					q->addQuestion(Q);
					break;
				}
			case 3:
				{
					Q=q->get_Head();
					cout<<"Ban muon them lua chon vao cau so may: ";
					cin>>temp_n;
					for(int i=1;i<temp_n && Q;i++)
					{
						Q=Q->getNext();
					}
					if(Q)
					{
						cout<<*Q;
						cin.ignore();
						cout<<"Nhap noi dung lua chon: ";getline(cin,temp);
						cout<<"true or false: ";cin>>temp_b;
						C=new Choice(temp,temp_b);
						Q->addChoice(C);
					}
					break;
				}
			case 4:
				{
					cout<<*q;
					cout<<"Ban muon xoa lua chon vao cau so may: ";
					cin>>temp_n;
					q->removeQuestion(temp_n);
					break;
				}
			case 5:
				{
					Q=q->get_Head();
					cout<<"Ban muon xoa lua chon vao cau so may: ";
					cin>>temp_n;
					for(int i=1;i<temp_n && Q;i++)
					{
						Q=Q->getNext();
					}
					if(Q)
					{
						cout<<*Q;
						cout<<"ban muon xoa lua chon so may: ";
						cin>>temp_n;
						Q->removeChoice(temp_n);
					}
					break;
				}
			case 6:
				{
					cout<<*q;
					system("pause");
					break;
				}
			case 7:
				{
					cout<<"Dat ten file ban muon luu: ";
					cin.ignore();
					getline(cin,temp);
					q->exportFile(temp);
					break;
				}
			case 8:
				{
					cin.ignore();cout<"Nhap id: ";getline(cin,temp1);
					cout<<"Nhap ten: ";getline(cin,temp2);
					Student *S=new Student(temp1,temp2);
					temp=S->choose_quiz("quiz/");
					S->do_quiz(temp);
					break;
				}
			}
	}
}
main()
{
	menu();
}
