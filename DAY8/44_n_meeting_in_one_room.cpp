/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

Examples: 

    Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
    Output : 1 2 4 5 
    First meeting [1, 2] 
    Second meeting [3, 4] 
    Fourth meeting [5, 7] 
    Fifth meeting [8, 9]

    Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924}, 
    f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } 
    Output : 6 7 1 
*/
#include<bits/stdc++.h>
using namespace std;

class meeting{
    public:
    
    int sTime;
    int eTime;
    int index;
};

bool comp(meeting m1, meeting m2){
    if(m1.eTime<m2.eTime) return true;
    else if(m1.eTime>m2.eTime) return false;
    else if(m1.index<m2.index) return true;
    return false;
}
void maxMeetings(int st[], int et[], int n){
    meeting m[n];
    for(int i=0; i<n; i++){
        m[i].sTime = st[i];
        m[i].eTime = et[i];
        m[i].index = i+1;
    }
    
    sort(m, m+n, comp);
    
    vector<int> ans;
    ans.push_back(m[0].index);
    int limit = m[0].eTime;
    for(int i=1; i<n; i++){
        if(m[i].sTime > limit){
            limit = m[i].eTime;
            ans.push_back(m[i].index);
        }
    }
    
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}
int main(){
    int n = 6;
    int st[] = {1, 0, 3, 8, 5, 8};
    int et[] = {2, 6, 4, 9, 7, 9};
    
    maxMeetings(st, et, n);
    return 0;
}
