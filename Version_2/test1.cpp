#include<iostream>
#include<time.h>
using namespace std;

main()
{
    time_t now = time(0);
    tm *ltm	= localtime(&now);
    string temp= to_string(ltm->tm_year+1900)+"/";
    temp+=to_string(ltm->tm_mon+1)+"/";
    temp+=to_string(ltm->tm_mday);
    temp+="-";
    temp+=to_string(ltm->tm_hour)+":";
    temp+=to_string(ltm->tm_min)+":";
    temp+=to_string(ltm->tm_sec);
    cout<<temp;
}