#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* InitList(){
    struct ListNode * L = malloc(sizeof(struct ListNode));
    L->next = NULL;
    return L;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *L = InitList();
    int val,
        carry = 0;
    struct ListNode *p = L;
    while (l1 != NULL || l2 != NULL) {

        int val1, val2;
        val1 = l1 == NULL ? 0 : l1->val;
        val2 = l2 == NULL ? 0 : l2->val;
        val = val1 + val2;
        if (carry == 1) {
            val++;
            carry = 0;
        }
        p->val = val % 10;
        if (val >= 10) {
            carry = 1;
        }
        if(l1 != NULL){
            l1 = l1->next;
        }
        if(l2 != NULL) {
            l2 = l2->next;
        }

        if(l1 != NULL || l2 != NULL) {
            p->next = InitList();
            p=p->next;

        } else {
            if(carry == 1){
                p->next = InitList();
                p=p->next;
                p->val = 1;
            }
        }
    }
    return L;
}

int main() {
    struct ListNode *l1 = InitList();
    struct ListNode *l2 = InitList();
    l1->val = 1;
    l1->next = InitList();
    l1->next->val = 8;
//    l1->next->next = InitList();
//    l1->next->next->val = 3;
    l2->val = 0;
//    l2->next = InitList();
//    l2->next->val = 6;
//    l2->next->next = InitList();
//    l2->next->next->val = 4;
    struct ListNode *res = addTwoNumbers(l1, l2);

    while(res != NULL) {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}