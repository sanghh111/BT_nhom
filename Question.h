#include<iostream>
#include<string>

#pragma once 
class Question;
class Choice;

class Question{
    private:
        int type;
        std::string content;
        Choice *head,*tail;
    public:
        Question(std::string,int);
        void set_content(std::string);
        void set_type(int);
        std::string get_content();
        int get_type();
        void addChoice(Choice *);
        void removeChoice(int);
        void update(int,Choice*);
        Question& operator+(Choice* );
        Question& operator-(int );
        // void display();
        friend std::ostream& operator<<(std::ostream&,const Question&); 
        friend std::istream& operator>>(std::istream&,Question&);
};

class Choice{
    private:
        std::string content;
        float score;
        int order;
        Choice *next;
    public:
        Choice(std::string,float);
        void set_content(std::string);
        void set_score(float);
        void set_order(int);
        std::string get_content();
        float get_score();
        int get_order();
        friend class Question;
        friend std::ostream& operator<<(std::ostream&,const Question&);
        friend std::istream& operator>>(std::istream&,Question&);
};
