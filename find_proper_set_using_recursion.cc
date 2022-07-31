/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
                                  // 0,  1,  2
void solve(string ip, string op)// = a , b , c
{
    //std::cout<<"Entering, IP="<<ip<<", op="<<op<<"\n";
    if (ip.length() ==0)
    {
        //cout<<"len =0, op ="<<op<<"\n";
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);//cout<<"OP2 after push="<<op2<<"\n";
    ip.erase(ip.begin()+0);//cout<<"IP after ERASE IP="<<ip<<", op1="<<op1<<"\n";
    solve(ip,op1);
    //std::cout<<"Now second recursion, in ="<<ip<<", op2="<<op2<<"\n";
    solve(ip,op2);
    return;
}

int main()
{
    string str ="abc";
    string op = "";
    solve(str, op);
    return 0;
}
