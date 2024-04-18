#include "stdio.h"
#include "stdlib.h"

struct ListNode;

struct ListNode {
    int val;
    struct ListNode * next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode dummy = {0, NULL}; // one way to initialize a struct
    struct ListNode* curr = &dummy; // point to the adress of dummy 
    int carry = 0, sum = 0; // carry is what is carried over to the next iteration and sum is current sum of digits and carry
    while(l1 != NULL || l2 != NULL || carry != 0){
        sum = carry + (l1 == 0 ? 0 : l1->val) + (l2 == 0 ? 0: l2->val);
        carry = sum/10;
        sum %= 10;
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = sum;
        curr->next->next = NULL;
        curr = curr->next;
        l1 = l1 == 0 ? 0 : l1->next;
        l2 = l2 == 0 ? 0 : l2->next;
    }
    return dummy.next;
}

int main(){
    struct ListNode q = {7, NULL};
    struct ListNode *qp = &q;
    qp->next = malloc(sizeof(struct ListNode));
    qp->next->val = 4;
    qp->next->next = NULL;
    qp = qp->next;
    qp->next = malloc(sizeof(struct ListNode));
    qp->next->val = 8;
    qp->next->next = NULL;

    struct ListNode t = {6, NULL};
    struct ListNode *tp = &t;
    tp->next = malloc(sizeof(struct ListNode));
    tp->next->val = 8;
    tp->next->next = NULL;
    tp = tp->next;
    tp->next = malloc(sizeof(struct ListNode));
    tp->next->val = 9;
    tp->next->next = NULL;

    struct ListNode * a = addTwoNumbers(qp, tp);

    while (a) {
        printf("%d ", a->val);
        a = a->next;
    }
    free(tp);
    free(qp);
    
    return 0;
}