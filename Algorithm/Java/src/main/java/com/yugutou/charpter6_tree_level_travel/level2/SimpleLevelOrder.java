package com.yugutou.charpter6_tree_level_travel.level2;

import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class SimpleLevelOrder {
    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBinaryTree();
        List<Integer> level = simpleLevelOrder(bTree.root);
        System.out.println(level.toString());
    }

    public static List<Integer> simpleLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<Integer>();
        }

        List<Integer> res = new ArrayList<Integer>();
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        //将根节点放入队列中，然后不断遍历队列
        queue.add(root);
        //有多少元素执行多少次
        while (queue.size() > 0) {
            //获取当前队列的长度，这个长度相当于 当前这一层的节点个数
            TreeNode t = queue.remove();
            res.add(t.val);
            if (t.left != null) {
                queue.add(t.left);
            }
            if (t.right != null) {
                queue.add(t.right);
            }
        }
        return res;
    }
}
