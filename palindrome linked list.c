/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 struct ListNode* reverse(struct ListNode* l1){

    struct ListNode* curr=l1;
    struct ListNode* prev=NULL;
    struct ListNode* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;

 }
bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

    }
    if(fast!=NULL){
        slow=slow->next;

    }
    slow=reverse(slow);
    fast=head;
    while(slow!=NULL){
        if(slow->val!=fast->val){
            return false;

        }
        slow=slow->next;
        fast=fast->next;
    }
    return true;

    
}