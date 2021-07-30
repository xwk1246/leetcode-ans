#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* tmp;
    ListNode* dummy = new ListNode(0, head);
    ListNode* current = dummy;
    while (current->next) {
        if (current->next->val == val) {
            tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        }
        else {
            current = current->next;
        }
    }
    return dummy->next;
}


int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, nullptr)));
    removeElements(head, 2);
    return 0;
}