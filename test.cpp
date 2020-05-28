#include<iostream>
#include<fstream>
main()
{
    std::fstream in;int b;
    in.open("test1.txt",std::ios::in);
    std::cout<<in.tellg()<<"     ";
    in>>b;
    std::cout<<b<<"  ";
    std::cout<<in.tellg()<<"\n";
    std::cout<<in.tellg()<<"     ";
    in>>b;
    std::cout<<b<<"  ";
    std::cout<<in.tellg()<<"\n";
    std::cout<<in.tellg()<<"     ";
    in>>b;
    std::cout<<b<<"  ";
    std::cout<<in.tellg()<<"\n";
    std::cout<<in.tellg()<<"     ";
    in>>b;
    std::cout<<b<<"  ";
    std::cout<<in.tellg()<<"\n";
    std::cout<<in.tellg()<<"     ";
    in>>b;
    std::cout<<b<<"  ";
    std::cout<<in.tellg()<<"\n";
    std::cout<<in.tellg()<<"     ";
    in>>b;
    std::cout<<b<<"  ";
    std::cout<<in.tellg()<<"\n";
    in>>b;
    std::cout<<b<<"  ";
    std::cout<<in.tellg()<<"\n";
}
