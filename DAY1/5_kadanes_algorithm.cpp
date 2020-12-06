
/* MAXIMUM SUBARRAY SUM */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n];
    
    for(int i=0; i<n; i++){
     cin>>ar[i];   
    }
    
    int current_sum=0;
    int best_sum=0;
    
    for(int i=0; i<n; i++){
        current_sum += ar[i];
        if(current_sum>best_sum){
            best_sum = current_sum;
        }
        if(current_sum<0)
        current_sum = 0;
    }
    cout<<best_sum<<endl;
}
