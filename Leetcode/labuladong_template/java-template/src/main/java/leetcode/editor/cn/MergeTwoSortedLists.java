/*
 * @lc app=leetcode.cn id=21 lang=java
 * @lcpr version=30008
 *
 * [21] 合并两个有序链表
 */

package leetcode.editor.cn;

import java.util.*;
import leetcode.editor.common.*;

public class MergeTwoSortedLists {

    // @lc code=start
    class Solution {
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            // 虚拟头结点
            ListNode dummy = new ListNode(-1), p = dummy;
            ListNode p1 = l1, p2 = l2;
    
            while (p1 != null && p2 != null) {
                // 比较 p1 和 p2 两个指针
                // 将值较小的的节点接到 p 指针
                if (p1.val > p2.val) {
                    p.next = p2;
                    p2 = p2.next;
                } else {
                    p.next = p1;
                    p1 = p1.next;
                }
                // p 指针不断前进
                p = p.next;
            }
    
            if (p1 != null) {
                p.next = p1;
            }
    
            if (p2 != null) {
                p.next = p2;
            }
    
            return dummy.next;
        }
    }
    // @lc code=end
    
    public static void main(String[] args) {
        Solution solution = new MergeTwoSortedLists().new Solution();
        // put your test code here
        ListNode l1 = ListNode.createHead(new int[]{1,2,4});
        ListNode l2 = ListNode.createHead(new int[]{1,3,4});

        ListNode res = solution.mergeTwoLists(l1, l2);
        ListNode.print(res);
    }
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

