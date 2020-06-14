// #include <stdio.h> 
#include<iostream>
#include <dirent.h>
#include<string.h> 
using namespace std; 

int main(void) 
{ 
     dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir("quiz"); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return 0; 
    } 
    string temp;
    while ((de = readdir(dr))) 
        {
            temp=de->d_name;
            if(!(temp!="." xor temp!=".."))
            cout<<temp<<endl;
        }
    closedir(dr);     
    return 0; 
} 