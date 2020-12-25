/*
Given an array of integers, find the length of the longest sub-array with sum equals to 0.
Examples : 
 

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
Explanation: The longest sub-array with 
elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation:There is no subarray with 0 sum

Input:  arr[] = {1, 0, 3}
Output:  1
Explanation: The longest sub-array with 
elements summing up-to 0 is {0}
*/
#include<bits/stdc++.h>
using namespace std;

int maxlen(int a[], int n){
    unordered_map<int, int> mp;
    int sum = 0;
    int max_len = 0;
    
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == 0){
            max_len += 1;
        }
        else{
           if(mp.find(sum)!=mp.end()){
               max_len = max(max_len, i-mp[sum]);
           }
           else
           mp[sum] = i;
        }
    }
    return max_len;
}
