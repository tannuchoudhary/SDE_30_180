# Reverse a singly linked list.
```
Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

```

```
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?


 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
``` 
 
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head!=NULL){
            ListNode* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
            
        }
        return dummy;
    }
};
```

## Complete implementation, by creating a linked list of size 4

```cpp
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;
};

ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head!=NULL){
            ListNode* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
            
        }
        return dummy;
    }
    
void printList(ListNode* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main(){
    ListNode* head = new ListNode();
    ListNode* second = new ListNode();
    ListNode* third = new ListNode();
    ListNode* fourth = new ListNode();
    
    head->data = 10;
    head->next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = fourth;
    
    fourth->data = 40;
    fourth->next = NULL;
    
    printList(head);
    cout<<endl;
    ListNode* rev = reverseList(head);
    cout<<endl;
    printList(rev);
    cout<<endl;
    
    return 0;
}
 ```
