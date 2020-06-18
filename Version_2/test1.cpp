#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

main()
{
   vector<int> i = {2,3,5,7};
    int a;
    // i.push_back(a);
    i.pop_back();
    cout<<i.back();
    cout<<i.size();
}