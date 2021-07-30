#include <iostream>
#include <vector>
using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) :val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) :val(x), next(next) {}
    };

    MyLinkedList() {
        _dummyHead = new ListNode;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* cur;
        cur = _dummyHead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        if (cur)
            return cur->val;
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        _dummyHead->next = new ListNode(val, _dummyHead->next);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* cur = _dummyHead;
        while (cur->next)cur = cur->next;
        cur->next = new ListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* cur = _dummyHead;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->next = new ListNode(val, cur->next);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* cur = _dummyHead;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        if (cur->next) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
    }
private:
    ListNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    cout << obj->get(1);
    obj->deleteAtIndex(1);
    cout << obj->get(1);
    return 0;
}