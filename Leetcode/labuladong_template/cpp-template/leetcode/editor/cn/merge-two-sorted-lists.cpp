/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30008
 *
 * [21] 合并两个有序链表
 */


#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 虚拟头结点
        ListNode dummy(-1), *p = &dummy;
        ListNode *p1 = l1, *p2 = l2;

        while (p1 != nullptr && p2 != nullptr) {
            // 比较 p1 和 p2 两个指针
            // 将值较小的的节点接到 p 指针
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            // p 指针不断前进
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
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    ListNode *l1 = ListNode::createHead({1, 2, 4});
    ListNode *l2 = ListNode::createHead({1, 3, 4});

    ListNode *res = solution.mergeTwoLists(l1, l2);
    ListNode::print(res);
    
    ListNode::freeList(l1);
    ListNode::freeList(l2);

}



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

