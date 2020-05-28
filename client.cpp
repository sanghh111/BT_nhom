#include"Question.h"
void menu(){
    int choose=0;
    int element_Question=0;
    Question *q = new Question;
    while(choose!=6)
    {
    	system("cls");
    	cout<<"******************************"<<endl;
    	cout<<"1.Khoi tao cau hoi."<<endl;
    	cout<<"2.Them 1 lua chon."<<endl;
    	cout<<"3.xoa 1 lua chon."<<endl;
    	cout<<"4.update 1 lua chon."<<endl;
    	cout<<"5.In ra cau hoi va lua chon"<<endl;
    	cout<<"6 Ket thuc."<<endl;
    	cout<<"******************************"<<endl;
    	cout<<"Nhap chon: ";cin>>choose;
    	switch(choose)
    		{
    			case 1:{
    				cout<<"ban muon nhap bao nhieu cau hoi: ";
    				cin>>element_Question;
    				q=new Question[element_Question];
    				
    				for(int i=0;i<element_Question;i++)
    				{
    					system("cls");
    					cin.ignore();
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<"Cau hoi thu "<<i+1<<endl;
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cin>>*(q+i);
					}
					break;
				}
				case 2:{
					cout<<"--------------------------------"<<endl;
					cout<<"Tat ca cau hoi"<<endl;
					cout<<"--------------------------------"<<endl;
					for(int i=0;i<element_Question;i++)
    				{
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<"Cau hoi thu "<<i+1<<endl;
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<*(q+i);
					}
					cout<<"--------------------------------"<<endl;
					cout<<"Ban muon them 1 lua chon vao cau may: "<<endl;
					cout<<"--------------------------------"<<endl;
					int i;cin>>i;i=i-1;
					system("cls");
					cin.ignore();
					string temp_content;
        			float temp_score;
        			cout<<"Nhap noi dung lua chon: ";
					getline(cin,temp_content);
        			cout<<"Nhap Diem: ";cin>>temp_score;
					Choice *a= new Choice(temp_content,temp_score);
					*(q+i)+a;
					system("cls");
					cout<<"---CAU HOI SAU KHI THEM---"<<endl;
					cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<"Cau hoi thu "<<i+1<<endl;
    				cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<*(q+i);
    				system("pause");
					break;
				}
				case 3:{
					cout<<"--------------------------------"<<endl;
					cout<<"Tat ca cau hoi"<<endl;
					cout<<"--------------------------------"<<endl;
					for(int i=0;i<element_Question;i++)
    				{
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<"Cau hoi thu "<<i+1<<endl;
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<*(q+i);
					}
					cout<<"--------------------------------"<<endl;
					cout<<"Ban muon xoa 1 lua chon vao cau may: "<<endl;
					cout<<"--------------------------------"<<endl;
					int i;cin>>i;i=i-1;
					system("cls");
					cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<"Cau hoi thu "<<i+1<<endl;
    				cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<*(q+i);
					cout<<"--------------------------------"<<endl;
					cout<<"Vi tri ban muon xoa: "<<endl;
					cout<<"--------------------------------"<<endl;
					system("cls");
					cout<<"---CAU HOI SAU KHI XOA---"<<endl;
					cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<"Cau hoi thu "<<i+1<<endl;
    				cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<*(q+i);
					int n;cin>>n;n=n-1;
					*(q+i)-n;
					system("pause");
					break;
				}
				case 4:{
					cout<<"--------------------------------"<<endl;
					cout<<"Tat ca cau hoi"<<endl;
					cout<<"--------------------------------"<<endl;
					for(int i=0;i<element_Question;i++)
    				{
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<"Cau hoi thu "<<i+1<<endl;
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<*(q+i);
					}
					cout<<"--------------------------------"<<endl;
					cout<<"Ban muon update 1 lua chon vao cau may: "<<endl;
					cout<<"--------------------------------"<<endl;
					int i;cin>>i;i=i-1;
					system("cls");
					cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<"Cau hoi thu "<<i+1<<endl;
    				cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<*(q+i);
					cout<<"--------------------------------"<<endl;
					cout<<"Vi tri ban muon update: "<<endl;
					cout<<"--------------------------------"<<endl;
					int n;cin>>n;n--;
					cin.ignore();
					string temp_content;
        			float temp_score;
        			cout<<"Nhap noi dung lua chon: ";
					getline(cin,temp_content);
        			cout<<"Nhap Diem: ";cin>>temp_score;
					Choice *a= new Choice(temp_content,temp_score);
					(q+i)->update(n,a);
					system("cls");
					cout<<"---CAU HOI SAU KHI XOA---"<<endl;
					cout<<"++++++++++++++++++++++++++++"<<endl;
    				cout<<"Cau hoi thu "<<i+1<<endl;
    				cout<<"++++++++++++++++++++++++++++"<<endl;
    				system("pause");
					break;
				}
				case 5:{
					cout<<"--------------------------------"<<endl;
					cout<<"Tat ca cau hoi"<<endl;
					cout<<"--------------------------------"<<endl;
					for(int i=0;i<element_Question;i++)
    				{
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<"Cau hoi thu "<<i+1<<endl;
    					cout<<"++++++++++++++++++++++++++++"<<endl;
    					cout<<*(q+i);
					}
					system("pause");
					break;
				}
			}
	}
}
main()
{
	menu();
}
