/*
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 
 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 2 are {5}
              and {5, 6, 7, 8, 9}


*/

#include<bits/stdc+++.h>
using namespace std;

int solution::solve(vector<int> &A, int B){
    map<int, int> freq;
    int cnt = 0;
    int xorr = 0;
    for(auto it : A){
        xorr = xorr^it;
        if(it == B)
        cnt++;
        if(freq.find(xorr^B)!=freq.end())
        cnt += freq^B;
        freq{xorr] += 1;
    }
    return cnt;
}
