package com.yugutou.charpter1_linklist.level2.topic2_4双指针;

/**
 * Leetcode61.旋转数组
 */
public class RotateRight {

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5};
        ListNode nodeA = initLinkedList(a);
        ListNode node = rotateRight(nodeA, 2);
        System.out.println(toString(node));
    }

    public static ListNode rotateRight(ListNode head, int k) {
        if (head == null || k == 0) {
            return head;
        }
        ListNode temp = head;
        ListNode fast = head;
        ListNode slow = head;
        int len = 0;
        while (head != null) {
            head = head.next;
            len++;
        }
        if (k % len == 0) {
            return temp;
        }
        while ((k % len) > 0) {
            k--;
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode res = slow.next;
        slow.next = null;
        fast.next = temp;
        return res;
    }

    /**
     * 输出链表
     *
     * @param head 头节点
     */
    public static String toString(ListNode head) {
        ListNode current = head;
        StringBuilder sb = new StringBuilder();
        while (current != null) {
            sb.append(current.val).append("\t");
            current = current.next;
        }
        return sb.toString();
    }

    private static ListNode initLinkedList(int[] array) {
        ListNode head = null, cur = null;

        for (int i = 0; i < array.length; i++) {
            ListNode newNode = new ListNode(array[i]);
            newNode.next = null;
            if (i == 0) {
                head = newNode;
                cur = head;
            } else {
                cur.next = newNode;
                cur = newNode;
            }
        }
        return head;
    }

    static class ListNode {
        public int val;
        public ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
