import {ListNode} from "../common/listNode.js";
import {TreeNode} from "../common/treeNode.js";

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    const preOrderList = [];
    traverse(root, preOrderList);
    return preOrderList;
};

var traverse = function (root, preOrderList) {
    if (root === null) {
        return;
    }
    preOrderList.push(root.val);
    traverse(root.left, preOrderList);
    traverse(root.right, preOrderList);
}

//leetcode submit region end(Prohibit modification and deletion)

// your test code here
const root = TreeNode.createRoot([1,2,3,4,5,null,8,null,null,6,7,9])
console.log(preorderTraversal(root));
