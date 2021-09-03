
# Given the head of a linked list, remove the nth node from the end of the list and return its head.

```
Follow up: Could you do this in one pass?

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/
```
# Brute

Thought process:
1. Try to find the size of the linked list
2. For that you have to traverse the LL, take a counter variable called c and find the size

![Screenshot from 2021-09-03 03-19-38](https://user-images.githubusercontent.com/42698268/131920932-af3a48a5-5517-4f78-aa8a-bced0409fae3.png)


4. once you get the size, subtract the node from last with that size, you'll have the index from start

![Screenshot from 2021-09-03 03-21-00](https://user-images.githubusercontent.com/42698268/131920982-e078e8b7-b454-47f5-b10e-d6c704fe48a1.png)


6. Assume you want to find the 3rd node from last, size is 8, that does mean you need to find 8-3 i.e 5th element from start
7. Iterate your second pointer, let us name  it t
8. when you'll find that t->next is target then stop and assign t->next = t->next->next
9. This will remove the link of target element

![Screenshot from 2021-09-03 03-24-20](https://user-images.githubusercontent.com/42698268/131921422-55b6386f-698d-42f7-8eda-8a21a69de843.png)


11. Link is removed but node is still there, so we'll delete that node
12. There is an edge case also, let us say that size of LL is 6 and you are asked to remove the 6th node from last, i.e the 1st node from first, then just assign head = head->next and delete the node.

# Time and space complexity 
* ```O(2n)``` as O(n) to find the size and other O(n) to delete the target
* Space complexity would be ```O(1) ```

But this is not optimized solution, so let us optimize it

# Optimized
``` Thought Process: use fast and slow pointer ```


```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* node = slow->next;
        slow->next = slow->next->next;
        delete(node);
        return start->next;
    }
};
```
