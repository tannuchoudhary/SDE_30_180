# Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

 
```
Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: l1 = [], l2 = []
Output: []

Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

``` 

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both l1 and l2 are sorted in non-decreasing order.
    
## Brute

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        
        ListNode* dd = new ListNode();
        ListNode* dummy = dd;
        
        while(h1!=NULL && h2!=NULL){
            if(h1->val > h2->val){
                ListNode* newNode = new ListNode();
                dd->next = newNode;
                newNode->val = h2->val;
                dd = dd->next;
                // if(h2->next == NULL)
                //     break;
                h2 = h2->next;
                
            }
            else{
                ListNode* newNode = new ListNode();
                dd->next = newNode;
                newNode->val = h1->val;
                dd = dd->next;
                // if(h1->next == NULL)
                //     break;
                h1 = h1->next;
            }
        }
        if(h1 != NULL){
            while(h1 != NULL){
                ListNode* newNode = new ListNode();
                dd->next = newNode;
                newNode->val = h1->val;
                dd = dd->next;
                if(h1->next == NULL)
                    break;
                h1 = h1->next;
            }
        }
        
        if(h2 != NULL){
            while(h2!=NULL){
                ListNode* newNode = new ListNode();
                dd->next = newNode;
                newNode->val = h2->val;
                dd = dd->next;
                if(h2->next == NULL)
                    break;
                h2 = h2->next;
            }
        }
        return dummy->next;
    }
};
```
    
## Optimized

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val > l2->val)
            swap(l1, l2);
        ListNode* res = l1;
        while(l1!=NULL && l2!= NULL){
            ListNode* tmp = NULL;
            while(l1!=NULL && l1->val <= l2->val){
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next = l2;
            swap(l1, l2);
        }
        return res;
    }
};
```
