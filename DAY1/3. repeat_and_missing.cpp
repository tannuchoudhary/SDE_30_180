/*
Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Examples: 

 Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 
2 is missing and 3 occurs twice 

Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1


*/

#include<bits/stdc++.h>
using namespace std;

void missing_repeating(int ar[], int n, int& x, int& y){
    int xor1 = ar[0];
    for(int i=1; i<n; i++){
        xor1 = xor1 ^ ar[i];
    }
    
    for(int i=1; i<=n; i++){
        xor1 = xor1 ^ i;
    }
    
    int set_bit = (xor1 & ~(xor1 -1));
    
    for(int i=0; i<n; i++){
        if(ar[i] & set_bit)
            x = x ^ ar[i];
        else
            y = y ^ ar[i];
    }
    
    for(int i=1; i<=n; i++){
        if(ar[i] & set_bit)
            x = x ^ i;
        else
            y = y ^ i;
    }

}
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }

    int x = 0, y = 0;
    missing_repeating(ar, n, x, y);
    cout<<"Repeating and missing numbers are "<<x+1<<" and "<<y+1<<endl;
    return 0;
}


