#include<bits/stdc++.h>
using namespace std;
int find_duplicate(vector<int> &v){
  //make one slow pointer and one fast pointer and initialize both of them from initial position
  int slow = v[0];
  int fast = v[0];

  //now move slow by one step and fast by two steps using tortoise method
  //this would be our first collision
  do{
    slow = v[slow];
    fast = v[v[fast]];
  }while(slow != fast);

  //for second collision put fast pointer again at initial position and slow pointer will remain in its
  //last position
  fast = v[0];
  //again move your slow and fast pointer by 1 points resp. for second collision
  while(slow!=fast){
    slow = v[slow];
    fast = v[fast];
  }
  return slow;
}
int main(){
  int t;
  cin>>t;
  while(t--){
  int n;
  cin>>n;
  vector<int> v;
  for(int i=0; i<n; i++){
    int num;
    cin>>num;
    v.push_back(num);
  }
  int ans = find_duplicate(v);
  cout<<ans<<endl;
 }
 return 0;
}

