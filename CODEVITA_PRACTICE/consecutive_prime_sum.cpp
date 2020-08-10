#include<bits/stdc++.h>
using namespace std;

int main(){
   long long n;
   cin>>n;
   
   
  
  bool *ar = new bool[n+1];
  int count =  0;
  
  for(long long i=0; i<=n; i++){
      ar[i] = true;
  }
  
  ar[0] = false;
   ar[1] = false;
  
  for(long long i=2; i*i<=n; i++){
      for(long long j= (i*i); j<=n; j+=i){
          ar[j] = false;
      }
  }
  
  long long sum =0;
  for(long long i=0; i<=n; i++){
      if(sum>n)
      break;
      if(ar[i] == true){
          //cout<<i<<endl;
          sum += i;
              if(ar[sum] == true && sum<n && sum>4){
                 // cout<<sum<<endl;
                  count++;
              }
      }
  }
  cout<<count<<endl;
    return 0;
}
