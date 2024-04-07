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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int , vector<int> , greater<int> > min_heap ; 
        for(int i = 0  ; i < lists.size() ; i++){
            ListNode* head = lists[i] ; 
            while(head){
                min_heap.push(head -> val ) ; 
                head = head->next  ; 
            }
        }

        ListNode* new_head = new ListNode(-1) ;
        //ListNode* head_ptr = new_head ; 
        ListNode* curr = new_head ; 

        while(!min_heap.empty()){
            ListNode* temp = new ListNode(min_heap.top()) ; 
            curr->next = temp  ; 
            //cout<< "temp val : "<< temp->val << endl ; 
            curr  =temp ; 
            min_heap.pop();
        }

        return new_head->next ;  ;

    }
};
