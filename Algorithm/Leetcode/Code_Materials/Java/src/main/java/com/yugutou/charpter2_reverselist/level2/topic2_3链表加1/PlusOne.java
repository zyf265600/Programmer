package com.yugutou.charpter2_reverselist.level2.topic2_3链表加1;

import java.util.Stack;

/**
 * LeetCode369 单链表加1
 */
public class PlusOne {
    public static void main(String[] args) {
        int[] a = {7, 8};
//        int[] a = {9,9,9};
//        int[] a = {1, 2, 3};
        ListNode nodeA = initLinkedList(a);

        ListNode node = plusOne(nodeA);

        System.out.println(toString(node));

    }

    public static ListNode plusOne(ListNode head) {
        Stack<Integer> st = new Stack();
        while (head != null) {
            st.push(head.val);
            head = head.next;
        }
        int carry = 0;
        ListNode dummy = new ListNode(0);
//        int adder = 1;
        while (!st.empty() || carry > 0) {
            int digit = st.empty() ? 0 : st.pop();
            int sum = digit + 1 + carry;
            carry = sum >= 10 ? 1 : 0;
            sum = sum >= 10 ? sum - 10 : sum;
            ListNode cur = new ListNode(sum);
            cur.next = dummy.next;
            dummy.next = cur;
//            adder = 0;
        }
        return dummy.next;
    }


    /**
     * 初始化链表
     *
     * @param array
     * @return
     */
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

    static class ListNode {
        public int val;
        public ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
