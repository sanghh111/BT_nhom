#include"Student.h"
Student::Student(string name,string id)
{
	this->name=name;
	this->id=id;
}

string Upper(string a)//viet hoa
{
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>=97&&a[i]<=122)
			a[i]=a[i]-32;	
	}
	return a;
}

string str_time(tm *ltm)
{
	int year=ltm->tm_year+1900,mon=ltm->tm_mon+1;
	std::stringstream y,mo,d,h,mi,s;
	y<<year;
	string temp=y.str();
	mo<<mon;
	temp+=mo.str();
	d<<ltm->tm_mday;
	temp+=d.str()+"-[";
	h<<ltm->tm_hour;
	temp+=h.str()+"-";
	mi<<ltm->tm_min;
	temp+=mi.str()+"-";
	s<<ltm->tm_sec;
	temp+=s.str()+"]";
    return temp;
}

void Student::do_quiz(string nameFile)//lam cau hoi thi
{
	Quiz *q;
	q=new Quiz("",0);
	q->importFile(nameFile);
//	cout<<*q;
	Question *Q=q->get_Head();
	int count=0;
	while(Q)
	{
		count++;
		Q=Q->getNext();
	}
	vector<string> myAnswer(count,"");
	vector<bool> myAnswerB(count,false);
	vector<float> myPoint(count,0.0);
	bool a= false;
	string temp=q->get_content();
	int Range=10,tep=temp.length();
	Range+=temp.length();
	int range=Range/2-temp.length();
	string check;
	int nhap;
	time_t now = time(0);
    tm *ltm	= localtime(&now); 		
	while(!a)
	{
		Q=q->get_Head();
		system("cls");
		cout<<"\t\t ";
		for(int i=0;i<Range;i++)
		cout<<"-";
		cout<<endl;
		cout<<"\t\t|";
		for(int i=0;i<range+tep/2;i++)
		cout<<" ";
		cout<<q->get_content();
		for(int i=0;i<Range/2-tep/2;i++)
		cout<<" ";
		cout<<"|"<<endl;
		cout<<"\t\t ";
		for(int i=0;i<Range;i++)
		cout<<"-";
		cout<<endl;
		cout<<"Ten: "<<name<<endl;
		cout<<"Thoi gian lam: "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<" ";
		cout<<ltm->tm_mday<<"-"<<ltm->tm_mon+1<<"-"<<ltm->tm_year+1900<<endl;
		for(int i=0;i<count;i++)
		{
			cout<<"Cau "<<i+1<<": "<<Q->getContent();
			if(myAnswerB[i]==0)
			cout<<"\t\tChua duoc tra loi";
			else cout<<"\t\tDa duoc tra loi";
			cout<<endl;
			Q=Q->getNext();//cau hoi tiep theo
		}
		cout<<endl<<endl;
		cout<<"Ban muon ket thuc(K) hay la tra loi cau hoi(T): ";
		getline(cin,check);
		Q=q->get_Head();
		check=Upper(check);
		if(check=="T")
		{
			cout<<"Nhap cau ban muon tra loi: ";
			cin>>nhap;
			while(nhap<1 && nhap>count)
			{
				cout<<"nhap lai: ";
				cin>>nhap;
			}
			system("cls");
			cout<<"\t\t ";
			for(int i=0;i<Range;i++)
			cout<<"-";
			cout<<endl;
			cout<<"\t\t|";
			for(int i=0;i<range+tep/2;i++)
			cout<<" ";
			cout<<q->get_content();
			for(int i=0;i<Range/2-tep/2;i++)
			cout<<" ";
			cout<<"|"<<endl;
			cout<<"\t\t ";
			for(int i=0;i<Range;i++)
			cout<<"-";
			cout<<endl;
			cout<<"Ten: "<<name<<endl;
			cout<<"Thoi gian lam: "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<" ";
			cout<<ltm->tm_mday<<"-"<<ltm->tm_mon+1<<"-"<<ltm->tm_year+1900<<endl;
			for(int j=1;j<nhap;j++)
			{
				Q=Q->getNext();
			}
			cout<<"Cau "<<nhap<<": ";
			cout<<*Q;
			cout<<"Nhap cau tra loi cua ban: ";
			cin.ignore();
			getline(cin,myAnswer[nhap-1]);
			if(myAnswer[nhap-1].compare("")!=0)
			{
				myAnswerB[nhap-1]=true;
			}
		}
		else if(check=="K")
			a=true;
	}
	float point=10.0/count;
	Q=q->get_Head();
	for(int i=0;i<count;i++)
	{
		if(myAnswerB[i])
		{
			if (Q->getType()==0)
			{
				if(myAnswer[i].length()==1)
				{
					char tmp1=65;
					int tmp=myAnswer[0][0]-tmp1;
					cout<<tmp;
					if(Q->checkChoice(tmp))
					{
						myPoint[i]=point;
					}	
				}
			}
			else 
			{
				int len_ans=myAnswer[i].length();
				for(int j=0;j<len_ans;j++)
					{
						char tmp1=65;
						int tmp=myAnswer[i][j]-tmp1;
						cout<<tmp;
						if(Q->checkChoice(tmp))
							{
							myPoint[i]+=Q->getPointe(point);
							}
						else
							{
							myPoint[i]=0;
							}
					}
			}
		}		
		cout<<myPoint[i];// diem tung cau hoi
		Q=Q->getNext();// cau tiep theo
	}
	cout<<"Tong so cau hoi :"<<count<<endl;
	cout<<"So cau lau duoc: ";
	tep=0;
	for(int i=0;i<count;i++)
	 	if(myPoint[i]==point)
	 		tep++;
	cout<<tep<<"/"<<count<<endl;
	tep=0;
	for(int i=0;i<count;i++)
	 		tep+=myPoint[i];
	cout<<"Tong so diem dat duoc: "<<tep<<"/10"<<endl;
	string tmp;
	cout<<"Nhap <S> de luu lai dap an: ";
	getline(cin,tmp);
	Upper(tmp);
	if(tmp.compare("S")==0)
	{
		temp=str_time(ltm);
		temp=name+"-"+temp;
		temp="student/"+temp+".txt";
//		cout<<temp;
		char A=65;
		ofstream out;
		out.open(temp.c_str());
		out<<"Id: "<<id<<endl;
		out<<"name: "<<name<<endl;
		out<<"\t\t\t"<<q->get_content()<<endl;
		Q=q->get_Head();
		for(int i=0;i<count;i++)
		{
			out<<"Cau"<<i+1<<": "<<Q->getContent()<<endl;
			Choice *C=Q->getHead();
			tep=0;
			while(C)
			{
				out<<A+tep<<". "<<C->get_content()<<endl;
				tep++;
				C=C->get_next();
			}
			out<<"Dap an:"<<myAnswer[i]<<"\t\t";
			if(myPoint[i]==point)
				out<<"True";
			else out<<"False"; 
			out<<endl;
		}
		out.close();
	}
}
