#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
    cout << removeNthFromEnd(head, 3)->val;
}