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
![Screenshot from 2021-09-03 01-30-01](https://user-images.githubusercontent.com/42698268/131908360-c8ed7267-99cd-404a-8142-647d75fdc54d.png)



Thought process:

1. Take a dummy node and assign null into it
2. name first node as head and second node as next
3. In the first iteration, assign the address of the dummy node into head( this will break the bond b/w head and next)

![Screenshot from 2021-09-03 01-29-47](https://user-images.githubusercontent.com/42698268/131908391-4a77a50a-a083-4161-a021-00131808cfa8.png)

4. Now assign dummy to the head and head to the next like this:

![Screenshot from 2021-09-03 01-32-25](https://user-images.githubusercontent.com/42698268/131908614-e2cfb472-16e0-4a0d-ac74-34409e34ab5c.png)

5. Now for the second iteration, take the next and point it to the next of head
6. And point 2's next to 1, now your second iteration is complete
7. Again place your dummy node to head, and head to the next

![Screenshot from 2021-09-03 01-33-55](https://user-images.githubusercontent.com/42698268/131908963-edced3d8-0eb4-497b-8ce7-781ab8690437.png)

8. Now start your next iteration, and continue until your head will not reach null


# Code

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head!=NULL){
            // create next here and not in the last of code because for the last node next will try to point to something which is not present and it will give you an error
            ListNode* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
            
        }
        return dummy;
    }
};
```
# Time complexity and space complexity
* Time complexity would be ``` O(N) ``` as each element would be traversed and its pointer is reversed.
* Space complexity would be ``` O(1) ``` because we did it in inplace, and we didn't needed any space.

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
