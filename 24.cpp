#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = dummy;
    ListNode* tmp;
    while (cur->next && cur->next->next) {
        tmp = cur->next->next;
        cur->next->next = cur->next->next->next;
        tmp->next = cur->next;
        cur->next = tmp;
        cur = cur->next->next;
    }
    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode* swapped = swapPairs(head);
    return 0;
}