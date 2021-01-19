/*
The atoi() function in C takes a string (which represents an integer) as an argument and returns its value of type 
int. So basically the function is used to convert a string argument to an integer.

Syntax:  
int atoi(const char strn)

Parameters: The function accepts one parameter strn which refers to the string argument that is needed to be converted
into its integer equivalent.
Return Value: If strn is a valid input, then the function returns the equivalent integer number for the passed
string number. If no valid conversion takes place, then the function returns zero.
*/


#include<bits/stdc++.h>
using namespace std;

int find_atoi(char* s){
    if(*s=='\0')
    return 0;
    
    int i=0;
    int res = 0;
    int sign = 1;
    
    //check whitespaces
    while(s[i] == ' ')
    i++;
    
    //check sign
    if(s[i] == '-' || s[i] == '+'){
        sign = 1-2*(s[i++] == '-' ? 1 : 0);
    }
    
    //check if char is valid or not
    while(s[i]>='0' && s[i]<='9'){
        if(res>=INT_MAX/10 && (s[i]-'0'>7)){
            if(sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        res = res*10 + (s[i++]-'0');
    }
    return res*sign;
}
int main(){
    string str;
    cin>>str;
    int sz = str.length();
    char s[sz];
    for(int i=0; i<sz; i++)
    s[i] = str[i];
    int val = find_atoi(s);
    cout<<val<<endl;
    return 0;
}
