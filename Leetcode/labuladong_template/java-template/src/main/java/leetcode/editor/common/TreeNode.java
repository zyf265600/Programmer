package leetcode.editor.common;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode() {
    }

    public TreeNode(int x) {
        val = x;
    }

    public TreeNode(int x, TreeNode left, TreeNode right) {
        val = x;
        this.left = left;
        this.right = right;
    }


    // 按照力扣的序列化规则输入生成二叉树，返回根节点
    public static TreeNode createRoot(Integer[] nums) {
        if (nums.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(nums[0]);
        TreeNode[] tree = new TreeNode[nums.length];
        tree[0] = root;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != null) {
                tree[i] = new TreeNode(nums[i]);
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (tree[i] != null) {
                if (2 * i + 1 < nums.length) {
                    tree[i].left = tree[2 * i + 1];
                }
                if (2 * i + 2 < nums.length) {
                    tree[i].right = tree[2 * i + 2];
                }
            }
        }
        return root;
    }

}
