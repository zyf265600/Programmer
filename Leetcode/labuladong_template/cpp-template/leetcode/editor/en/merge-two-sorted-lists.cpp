#include <iostream>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // dummy head node
        ListNode dummy(-1), *p = &dummy;
        ListNode *p1 = l1, *p2 = l2;

        while (p1 != nullptr && p2 != nullptr) {
            // compare two pointers p1 and p2
            // attach the node with the smaller value to the p pointer
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            // the p pointer moves forward continuously
            p = p->next;
        }

        if (p1 != nullptr) {
            p->next = p1;
        }

        if (p2 != nullptr) {
            p->next = p2;
        }

        return dummy.next;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;

    // your test code here
    ListNode *l1 = ListNode::createHead({1, 3, 5});
    ListNode *l2 = ListNode::createHead({2, 4, 6});

    ListNode *result = Solution().mergeTwoLists(l1, l2);
    ListNode::print(result);
}
