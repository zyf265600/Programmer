
package leetcode.editor.cn;

import java.sql.Array;
import java.util.*;
import leetcode.editor.common.*;

public class BinaryTreePreorderTraversal {

    //leetcode submit region begin(Prohibit modification and deletion)
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode() {}
     *     TreeNode(int val) { this.val = val; }
     *     TreeNode(int val, TreeNode left, TreeNode right) {
     *         this.val = val;
     *         this.left = left;
     *         this.right = right;
     *     }
     * }
     */
    class Solution {
        List<Integer> res = new ArrayList<>();

        public List<Integer> preorderTraversal(TreeNode root) {
            traversal(root);
            return res;
        }

        void traversal(TreeNode root) {
            if (root == null) {
                return;
            }
            res.add(root.val);
            traversal(root.left);
            traversal(root.right);
        }
    }
    //leetcode submit region end(Prohibit modification and deletion)

    
    public static void main(String[] args) {

        Solution solution = new BinaryTreePreorderTraversal().new Solution();
        // put your test code here
        TreeNode root = TreeNode.createRoot(new Integer[]{1,2,3,4,5,null,8,null,null,6,7,9});

        List<Integer> result = solution.preorderTraversal(root);
        System.out.println(result);
    }
}