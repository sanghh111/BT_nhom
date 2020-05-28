#include<iostream>
#include<string.h>
#include"Question.h"
using namespace std;

/* 
    ````````Contrustor Class Question```````````
*/
Question::Question(string content="",int type=0)
{
    if(type==1 && type ==0)
        this->type=type;
    else this->type=0;
    this->content=content;
    head=tail=NULL;
    this->next=NULL;
}

/* 
    ````````set_content Class Question```````````
*/
void Question::set_content(string content)
{
    this->content=content;
}

/* 
    ````````set_type Class Question```````````
*/
void Question::set_type(int type)
{
    if(type==1 && type==0)
        this->type=type;
    else this->type=0;
}

/* 
    ````````get_type Class Question```````````
*/
int Question::get_type()
{
    return type;
}

/* 
    ````````get_content Class Question```````````
*/
string Question::get_content()
{
    return content;
}

Question& Question::operator=(Question *temp)
{
    this->content=temp->content;
    this->type=temp->type;
    return *this;
}

int Question::count_Choice()
{
    Choice *a=head;
    int dem=0;
    while(a!=NULL)
    {
        dem++;
        a=a->next;
    }
    return dem;
}
/* 
    ````````Contrustor Class Choice```````````
*/
Choice::Choice(string content="",float score=0)
{
    this->content=content;
    this->score=score;
    this->order=order;
    next=NULL;
}

/* 
    ````````set_content Class Choice```````````
*/
void Choice::set_content(string content)
{
    this->content=content;
}

/* 
    ````````set_score Class Choice```````````
*/
void Choice::set_score(float score)
{
    this->score=score;
}

/* 
    ```````````set_order Class Choice```````````
*/
void Choice::set_order(int order)
{
    this->order=order;
}

/*
    ``````````````get_content Class Choice``````````````
*/
string Choice::get_content(){
    return content;
}
/*
  ``````````````get_score Class Choice``````````````
*/
float Choice::get_score(){
    return score;
}
/*
  ``````````````get_order Class Choice``````````````
*/
int Choice::get_order()
{
    return order;
}

/*
--------------addChoice-------------
*/
void Question::addChoice(Choice *c)
{
    if(head==NULL)
        head=tail=c;
    else
        {
            tail->next=c;
            tail=c;
        }
}

/*
--------------removeChoice-------------
*/
void Question::removeChoice(int Pos){
    Choice *a=head;
    if(Pos==1)
    {
        if(head==tail)
        {
            head=tail=NULL;
            delete a;
            return ;
        }
        else
        {
            head=a->next;
            a->next=NULL;
            delete a;
            return ;
        }
    }
    else
    {
        Choice *b=a;
        a=a->next;
        int i=2;
        while(a!=NULL)
        {
            if(i==Pos)
            {
                if(a==tail)
                    {
                        tail=b;
                        tail->next=NULL;
                        delete a;
                        return ;
                    }
                    else
                    {
                        b->next=a->next;
                        a->next=NULL;
                        delete a;
                        return ;
                    }                
            }
            b=a;
            a=a->next;
        }
    cout<<"~~Khong tim thay vi tri can tim~~"<<endl;
    }
}

/*
--------------updateChoice-------------
*/
void Question::update(int Pos,Choice* c)
{
     Choice *a=head;
    if(Pos==1)
    {
        if(head==tail)
        {
            head=tail=c;
            delete a;
            return ;
        }
        else
        {
            head=a->next;
            c->next=head;
            head=c;
            a->next=NULL;
            delete a;
            return ;
        }
    }
    else
    {
        if(a==NULL)
            return;
        Choice *b=a;
        a=a->next;
        int i=2;
        while(a!=NULL)
        {
            if(i==Pos)
            {
                if(a==tail)
                    {
                        tail=b;
                        tail->next=c;
                        tail=tail->next;
                        delete a;
                        return ;
                    }
                    else
                    {
                        c->next=a->next;
                        a->next=NULL;
                        b->next=c;
                        delete a;
                        return ;
                    }                
            }
            b=a;
            a=a->next;
        }
    cout<<"~~Khong tim thay vi tri can tim~~"<<endl;
    }
}
/*
-------------Operator+----------
*/
Question& Question::operator+(Choice* a)
{
    if(head==NULL)
        {
            head=tail=a;
            return *this;
        }
    else
    {
        tail->next=a;
        tail=tail->next;
        return *this;
    }
}
/*
-------------.Operator-.----------
*/
Question& Question::operator-(int Pos){
    Choice *a=head;
    if(Pos==1)
    {
        if(head==tail)
        {
            head=tail=NULL;
            delete a;
            return *this;
        }
        else
        {
            head=a->next;
            a->next=NULL;
            delete a;
            return *this;
        }
    }
    else
    {
        if(a==NULL)
            return *this;
        Choice *b=a;
        a=a->next;
        int i=2;
        while(a!=NULL)
        {
            if(i==Pos)
            {
                if(a==tail)
                    {
                        tail=b;
                        tail->next=NULL;
                        delete a;
                        return *this;
                    }
                    else
                    {
                        b->next=a->next;
                        a->next=NULL;
                        delete a;
                        return *this;
                    }                
            }
            b=a;
            a=a->next;
        }
    cout<<"~~Khong tim thay vi tri can tim~~"<<endl;
    }
    return *this;
}
/*
-----------oprator<<------------
*/
ostream& operator<<(ostream& out,const Question& q)
{
    out<<q.content<<endl;
    Choice *a= q.head;
    int i=1;
    while(a!=NULL)
    {
        out<<i<<"."<<a->content<<endl;
        a=a->next;
        i++;
    }
    return out;
}
/*
-----------oprator>>------------
*/
istream& operator>>(istream &in,Question &q)
{
    int n;
    q.head=q.tail=NULL;
    cout<<"Nhap noi dung cau hoi: ";getline(in,q.content);
    cout<<"Nhap Kieu: ";in>>q.type;
    cout<<"ban muon them bao nhieu lua chon: ";in>>n;
    cout<<"---------------------------\n";
    for(int i=0;i<n;i++)
    {
    	in.ignore();
        cout<<"lua chon thu "<<i+1<<endl;
        string temp_content;
        float temp_score;
        cout<<"Nhap noi dung lua chon: ";
		getline(in,temp_content);
        cout<<"Nhap Diem: ";in>>temp_score;
        Choice *a= new Choice(temp_content,temp_score);
        q+a;
    }
    return in;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~Class Quiz~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
Quiz::Quiz(string name="",int duration=0)
{
    this->name=name;
    this->duration=duration;
    head=tail=NULL;
}


void Quiz::addQuestion(Question *temp)
{
    if(head==NULL)
    {
        head=tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void Quiz::removeQuestion(int pos)
{
    Question *temp=head;
    if(pos==1)
    {
        if(head==tail)
        {
            head=tail=NULL;
        }
        else
        {
            head=head->next;
            temp->next=NULL;
        }
    }
    else
    {
        int dem=2;
        Question *temp1=head;
        temp=temp->next;
        // When i fine dem i have the previus temp and temp 
        while(dem != pos and temp != tail)
        {
            temp1=temp1->next;
            temp=temp->next;
            dem++;
        }
        //Check fine pos 
        if(dem==pos)
        {
            if(temp==tail)
            {
                tail=temp1;
                tail->next=NULL;
            }
            else
            {
                temp1->next=temp->next;
                temp->next=NULL;
            }
        }
    }
}

void Quiz::updateQuestion(int pos,Question *temp)
{
    Question *a=head;
    if(pos==0)
    {
        a=temp;
    }
    else
    {
        a=a->next;
        int dem=1;
        while(dem!=pos && a->next!=NULL)
        {
            dem++;
            a=a->next;
        }
        if(dem==pos)
            a=temp;
    }
}

ostream& operator<<(ostream &out,Quiz c)
{
	out<<"-------------------------------------"<<endl;
	out<<"          Quiz: "<<c.name<<endl;
	out<<"-------------------------------------"<<endl;
	Question *temp=c.head;
    int dem=1;
    while(temp!=NULL)
	{
        out<<"Cau "<<dem<<": "<<*temp;
        temp=temp->next;
        dem++;
        cout<<endl;
    }
	return out;
}

void Quiz::importFromFile(char *)