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

void swap(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
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
	vector<int> myRan(count,0);
	srand(time(0));
	myRan[0]=rand()%count+1;
//	cout<<myRan[0]<<"	";
	for (int i=1;i<count;i++)
	{
		myRan[i]=rand()%count+1;
		for(int j=0;j<i;j++)
			{
				if(myRan[i]==myRan[j])
					{
						myRan[i]=rand()%count+1;
						j=-1;
					}
			}
//		cout<<myRan[i]<<"	";
	}	
	cout<<endl;
	bool a= false;
	string temp=q->get_content();
	int Range=10,tep=temp.length();
	Range+=temp.length();
	int range=Range/2-temp.length();
	string check;
	int nhap;
	time_t now = time(0);
    tm *ltm	= localtime(&now); 		
	while(myRan.size()!=0)
	{
		Q=q->get_Head();
		tep=myRan.front();
		for (int i=1;i<myRan.size();i++)
			{
				int t=myRan[i-1];
				myRan[i-1]=myRan[i];
				myRan[i]=t;
			}
		myRan.pop_back();
		for(int i=1;i<tep;i++)
		{
			Q=Q->getNext();
		}
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
		cout<<"Tong so cau hoi la: "<<count<<endl;
		cout<<"Cau"<<tep<<": ";
		cout<<*Q;
		cout<<"Nhap (A) de tra loi va (S) de bo qua: ";
		getline(cin,temp);
		Upper(temp);
		while(temp.compare("A")!=0 && temp.compare("S")!=0 )
		{
			cout<<"Nhap (A) de tra loi va (S) de bo qua: ";
			getline(cin,temp);
		}
			if(temp.compare("A")==0)
				{
					cout<<"Nhap cau tra loi cua ban: ";
					getline(cin,myAnswer[tep-1]);
					Upper(myAnswer[tep-1]);
					if(myAnswer[tep-1].compare("")!=0)
						myAnswerB[tep-1]=true;
					else myAnswerB[tep-1]=false;
//					cout<<myAnswer[tep-1];
				}
			else if(temp.compare("S")==0)
			{
				myRan.push_back(tep);
			}
	}
	while(!a)
	{
		cout<<"KET THUC(K), Chinh sua(S): ";
		getline(cin,temp);
		while(temp.compare("K")!=0 && temp.compare("S")!=0 )
			{
				cout<<"Nhap (A) de tra loi va (S) de bo qua: ";
				getline(cin,temp);
			}
		if (temp.compare("S")==0)
		{
			cout<<"Tong cau hoi: "<<count<<endl;
			cout<<"Nhap so cau hoi muon sua: ";
			cin>>tep;
			if(tep<=count)
			{
				Q=q->get_Head();
				for(int i=0;i<tep;i++)
				{
					Q=Q->getNext();
				}
					for(int i=1;i<tep;i++)
		{
			Q=Q->getNext();
		}
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
			cout<<"Tong so cau hoi la: "<<count<<endl;
			cout<<"Cau"<<tep<<": ";
			cout<<*Q;	
			}
		}
		if (temp.compare("K")==0)
		{
			a=true;
		}
	}
	float point=10.0/count;
	cout<<"My Answer: ";
	for(int i=0;i<count;i++)
		cout<<myAnswer[i]<<" ";
	cout<<endl;	
	Q=q->get_Head();
	for(int i=0;i<count;i++)//cham diem
	{
		if(myAnswerB[i])
		{
			if (Q->getType()==0)
			{
				if(myAnswer[i].length()==1)
				{
					char tmp1=65;"A"
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
//						cout<<tmp;
						if(Q->checkChoice(tmp))
							{
							myPoint[i]+=Q->getPointe(point);
							}
						else
							{
							myPoint[i]=0;
							break;
							}
					}
			}
		}		
//		cout<<myPoint[i];// diem tung cau shoi
		Q=Q->getNext();// cau tiep theo
	}
	cout<<"Tong so cau hoi :"<<count<<endl;
	cout<<"So cau lau duoc: ";
	tep=0;
	for(int i=0;i<count;i++)
	 	if(myPoint[i]==point)
	 		tep++;
	cout<<tep<<"/"<<count<<endl;
	float b=0;	
	for(int i=0;i<count;i++)
	 	b=b+myPoint[i];
	cout<<"Tong so diem dat duoc: "<<b<<"/10"<<endl;
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
//		cout<<A;
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
			A=65;
			while(C)
			{
				out<<A<<". "<<C->get_content()<<endl;
				A=A+1;
				C=C->get_next();
			}
			out<<"Ban chon:"<<myAnswer[i]<<"\t\t";
			if(myPoint[i]==point)
				out<<"True";
			else out<<"False"; 
			out<<endl;
		}
		out.close();
	}
}

string Student::choose_quiz(string namefile="quiz/")
{
	dirent *de;
	DIR *dr = opendir(namefile.c_str());
	
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        cout<<"Could not open current directory"<<endl; 
        return "nothing"; 
    }
    string temp;
    vector<string>path;
    while ((de = readdir(dr))) 
        {
            temp=de->d_name;
            if(!(temp!="." xor temp!=".."))
            {
				path.push_back(temp);
			}
        }
    closedir(dr);     
	cout<<"Tat ca file kiem tra:\n";
	for(int i=0;i<path.size();i++)
	{
		cout<<i+1<<". "<<path[i]<<endl;
	}
	cout<<"ban chon file so may: ";
	int a;
	cin>>a;
	return path[a-1];
}
