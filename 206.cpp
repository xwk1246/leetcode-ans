#include <iostream>
#include <vector>
using namespace std;

ListNode* reverse(ListNode last, ListNode cur) {
    if (cur)return last;
    ListNode* tmp;
    tmp = cur->next;
    cur->next = last;
    return reverse(cur, tmp);
}

ListNode* reverseList(ListNode* head) {
    reverse(nullptr, cent nodes and return its head.You must solve the problem without modifying the values in the list's nodehead)
}

int main() {
    return 0;
}