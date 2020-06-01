#include"Question.h"
Question::Question(string content="",bool type=false)
{
	count_answer=0;
	this->content=content;
	this->type=type;
	head=tail=NULL;
	count_answer=0;
}

void Question::addChoice(Choice* temp)
{
	if(head==NULL)
		head=tail=temp;
	else
	{
		tail->next=temp;
		tail=temp;
	}
	if(temp->get_answer()==true)
	{
		if(type==0)
		{
			if(count_answer==0)
			{
				count_answer++;
			}
			else
			{
				Choice* temp1= fineTrueChoice();
				temp1->set_answer(false);
			}
		}
		else
		{
			count_answer++;
		}
	}
}

void Question::updateChoice(int Pos,Choice* c)
{
    Choice *a=head;
    if(Pos==1)
    {
    	if(a->get_answer())
    	{
    		if(!c->get_answer())
    			count_answer--;
		}
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
            	if(a->get_answer())
    				if(!c->get_answer())
    					count_answer--;
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

void Question::removeChoice(int Pos){
    Choice *a=head;
    if(Pos==1)
    {
    	if(a->get_answer())
    		count_answer--;
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
            	if(a->get_answer())
    			count_answer--;
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

Question& Question::operator+(Choice* temp)
{
	if(temp->get_answer()==true)
	{
		if(type==0)
		{
			if(count_answer==0)
			{
				count_answer++;
			}
			else
			{
				Choice* temp1= fineTrueChoice();
				temp1->set_answer(false);
			}
		}
		else
		{
			count_answer++;
		}
	}
    if(head==NULL)
        {
            head=tail=temp;
            return *this;
        }
    else
    {
        tail->next=temp;
        tail=tail->next;
        return *this;
    }
    
}

Question& Question::operator-(int Pos){
    Choice *a=head;
    if(Pos==1)
    {
    	if(a->get_answer())
    		count_answer--;
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
						if(a->get_answer())
    					count_answer--;
                        b->next=a->next;
                        a->next=NULL;
                        delete a;
                        return *this;
                    }                
            }
            b=a;
            a=a->next;
        }
    }
    return *this;
}

ostream& operator<<(ostream& out,Question& q)
{
    out<<q.content<<endl;
    Choice *a= q.head;
    int i=1;
    while(a!=NULL)
    {
        out<<i<<"."<<a->get_content()<<"	"<<a->get_answer()<<endl;
        a=a->get_next();
        i++;
    }
    out<<q.get_count_answer()<<endl;
    return out;
}

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
        bool answer;
        cout<<"Nhap noi dung lua chon: ";
		getline(in,temp_content);
        cout<<"1/0: ";in>>answer;
        Choice *a= new Choice(temp_content,answer);
        q+a;
    }
    return in;
}

Choice* Question::fineTrueChoice()
{
	Choice *temp=head;
	while(!temp->get_answer() && temp!=NULL)
	{
		temp=temp->next;
	}
//	cout<<temp->get_content();	
	return temp;
}

void Question::makeTrueChoice(int pos)
{
	Choice *temp = head;
	int count=1;
	if()
}

int Question::get_count_answer()
{
	return count_answer;	
} 
