#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) {
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        int ans = count - n;
        temp = head;
        ListNode* prev = NULL;
        int a = 0;
        while (temp != NULL) {
            if (a == ans) {
                if (prev != NULL) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                return head;
            }
            prev = temp;
            temp = temp->next;
            a++;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    Solution solution;
    ListNode* updatedHead = solution.removeNthFromEnd(head, n);

    ListNode* current = updatedHead;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    return 0;
}
