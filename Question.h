#include<iostream>
#include<string>
// #include<vector>
#include<fstream>
#pragma once 
class Question;
class Choice;
class Quiz;
class Question{
    private:
        int type;
        std::string content;
    public:
    	Question *next;
    	Choice *head,*tail;
        Question(std::string,int);
        void set_content(std::string);
        void set_type(int);
        std::string get_content();
        int get_type();
        int count_Choice();
        void addChoice(Choice *);
        void removeChoice(int);
        void update(int,Choice*);
        Question& operator+(Choice* );
        Question& operator-(int );
        Question& operator=(Question *);
        // void display();
        friend class Quiz;
        friend std::ostream& operator<<(std::ostream&,const Question&); 
        friend std::istream& operator>>(std::istream&,Question&);
};

class Choice{
    private:
        std::string content;
        float score;
        int order;
    public:
    	Choice *next;
        Choice(std::string,float);
        void set_content(std::string);
        void set_score(float);
        void set_order(int);
        std::string get_content();
        float get_score();
        int get_order();
        friend class Question;
        friend std::ostream& operator<<(std::ostream&,const Question&);
        friend std::istream& operator>>(std::istream&,Choice&);
};

class Quiz
{
    std::string name;
    int duration;
    Question *head,*tail;
    public:
        Quiz(std::string,int);
        void addQuestion(Question*);
        void removeQuestion(int);
        void updateQuestion(int, Question*);
        void importFromFile(std::string);
        void exportToFile(std::string);
        Quiz operator+(Question);
        Quiz operator-(Question);
        friend std::ostream& operator<<(std::ostream&,Quiz);
};
