#include <cstdio>
#include <cstdlib>

typedef struct ListNode {
    ListNode * next;
    int val;
} ListNode;

void arr_to_LN_front(ListNode ** ln, const int * arr, int arr_elem){
    for (int ii = 0; ii < arr_elem; ii++){
        ListNode * h;
        h = (ListNode *) malloc(sizeof(ListNode));
        h->val = arr[ii];
        h->next = *ln;
        *ln = h;
    }
}

void arr_to_LN_back(ListNode ** ln, const int * arr, int arr_elem){
    ListNode * head;
    head = *ln; 
    for (int ii = 0; ii < arr_elem; ii++){
        ListNode * h;
        h = (ListNode *) malloc(sizeof(ListNode));
        h->val = arr[ii];
        h->next = NULL;
        if (!(*ln)){
            *ln = h;       
        } else {
            (*ln)->next = h;            
            *ln = (*ln)->next;            
        }        
    }
    *ln = head;
}

void print_LN(ListNode * ln){
    while (ln){
        printf("%d\n", ln->val);
        ln = ln->next;        
    }
}

int main(void){
    ListNode * a = NULL;
    int arr[] = {1,2,3,4,5};
    arr_to_LN_back(&a, &arr[0], 5);
    print_LN(a);
}