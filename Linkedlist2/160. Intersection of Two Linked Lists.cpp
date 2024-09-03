#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp;
        while (headA != nullptr) {
            temp = headB;
            while (temp != nullptr) {
                if (headA == temp) {
                    return headA;
                }
                temp = temp->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};

int main() {
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode *common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);
    headA->next->next = common;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        std::cout << "Intersection at node with value: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection found." << std::endl;
    }

    return 0;
}
