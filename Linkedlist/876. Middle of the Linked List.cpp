#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        

        while (temp) {
            cnt++;
            temp = temp->next;
        }
        temp = head;

        for (int i = 1; i <= cnt / 2; i++) {
            temp = temp->next;
        }
        
        return temp;
    }
};

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    Solution solution;


    ListNode* middle = solution.middleNode(head);


    std::cout << "Middle Node Value: " << middle->val << std::endl;


    return 0;
}
