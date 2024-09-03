#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getlength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int len = getlength(head);
        if (len < k) {
            return head;
        }
        int position = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (position < k) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            position++;
        }
        if (curr != nullptr) {
            ListNode* recursionhead = reverseKGroup(curr, k);
            head->next = recursionhead;
        }
        return prev;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    
    Solution solution;
    ListNode *result = solution.reverseKGroup(head, k);

    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
