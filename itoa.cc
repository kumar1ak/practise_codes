/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void reverse(char str[], int length)
{
    int start=0;
    int end = length-1;
    while(start<end)
    {
        swap( *(str+start), *(str+end) );
        start++;
        end--;
    }
}

char* itoaa(int num, char *str, int base)
{
    int i=0;
    bool isnegative = false;
    
    if(num ==0)
    {
      str[i++]='\0';
      str[i] = '\0';
      return str;
    }
    
    if(num <0 && base == 10)
    {
        num = -num;
        isnegative = true;
    }
    while(num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? ((rem - 10) + 'a') : (rem + '0');
        num = num/base;
    }
    if(isnegative)
    {
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str, i);
    return str;
}

int main()
{
    cout<<"Hello World";
    char str[100];
    cout << "Base:10 " << itoaa(1567, str, 10) << endl;
    cout << "Base:10 " << itoaa(-1567, str, 10) << endl;
    cout << "Base:2 " << itoaa(1567, str, 2) << endl;
    cout << "Base:8 " << itoaa(1567, str, 8) << endl;
    cout << "Base:16 " << itoaa(1567, str, 16) << endl;
    return 0;
}
