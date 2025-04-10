import {ListNode} from "../common/listNode.js";
import {TreeNode} from "../common/treeNode.js";

//leetcode submit region begin(Prohibit modification and deletion)
var addTwoNumbers = function (l1, l2) {

    let carry = 0;
    let dummy = new ListNode(0);
    let current = dummy;

    while (l1 !== null || l2 !== null) {
        const x = l1 !== null ? l1.val : 0;
        const y = l2 !== null ? l2.val : 0;
        const sum = x + y + carry;
        carry = Math.floor(sum / 10);
        current.next = new ListNode(sum % 10);
        current = current.next;
        if (l1 !== null) l1 = l1.next;
        if (l2 !== null) l2 = l2.next;
    }

    if (carry > 0) {
        current.next = new ListNode(carry);
    }

    return dummy.next;
};
//leetcode submit region end(Prohibit modification and deletion)

let result = addTwoNumbers(ListNode.createHead([2, 4, 3]), ListNode.createHead([5, 6, 4]));
ListNode.print(result)

