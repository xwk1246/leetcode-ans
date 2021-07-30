#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int sizeA = 0, sizeB = 0;
    ListNode* ptrA = new ListNode();
    ptrA->next = headA;
    ListNode* ptrB = new ListNode();
    ptrB->next = headB;
    ListNode* tmp = ptrA;
    while (tmp->next) {
        sizeA++;
        tmp = tmp->next;
    }
    tmp = ptrB;
    while (tmp->next) {
        sizeB++;
        tmp = tmp->next;
    }
    if (sizeA > sizeB) {
        for (int i = 0; i < sizeA - sizeB; i++) {
            ptrA = ptrA->next;
        }
    }
    else if (sizeB > sizeA) {
        for (int i = 0; i < sizeB - sizeA; i++) {
            ptrB = ptrB->next;
        }
    }
    while (ptrA && ptrB) {
        if (ptrA == ptrB)return ptrA;
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return nullptr;
}

int main() {
    ListNode* tmp;
    ListNode* headA = new ListNode(0, tmp = new ListNode(1, new ListNode(2)));
    ListNode* headB = new ListNode(5, new ListNode(4, tmp));
    cout << getIntersectionNode(headA, headB);
}