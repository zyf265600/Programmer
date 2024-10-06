package com.yugutou.charpter1_linklist.level2.topic2_5删除元素;


import java.util.Deque;
import java.util.LinkedList;

public class DeleteBackwardsPoint {
    /**
     * 几个与倒数有关的问题
     *
     * @param args
     */
    public static void main(String[] args) {
        int[] a = {4, 4, 5, 1, 9, 9};
        ListNode nodeA = initLinkedList(a);
        int testMethod = 4;
        ListNode result = null;
        switch (testMethod) {
            case 1://找链表的倒数第K个元素开始的链表
                result = getKthFromEnd(nodeA, 3);
                break;
            case 2:
                result = removeNthFromEndByLength(nodeA, 3);
                break;
            case 3:
                result = removeNthFromEndByStack(nodeA, 3);
                break;
            case 4:
                result = removeNthFromEndByTwoPoints(nodeA, 3);
                break;

        }

        System.out.println(toString(result));


    }

    /**
     * 找链表的倒数第K个元素开始的链表
     *
     * @param head
     * @param k
     * @return
     */
    public static ListNode getKthFromEnd(ListNode head, int k) {
        ListNode pre = head;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            if (k > 0)
                k--;
            else {
                pre = pre.next;
            }
        }
        return pre;
    }

    /**
     * 方法1：删除倒数第N个结点
     *
     * @param head
     * @param n
     * @return
     */
    public static ListNode removeNthFromEndByLength(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int length = getLength(head);
        ListNode cur = dummy;
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur.next;
        }
        cur.next = cur.next.next;
        ListNode ans = dummy.next;
        return ans;
    }

    public static int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            ++length;
            head = head.next;
        }
        return length;
    }

    /**
     * 方法2：通过栈实现
     *
     * @param head
     * @param n
     * @return
     */
    public static ListNode removeNthFromEndByStack(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        Deque<ListNode> stack = new LinkedList<ListNode>();
        ListNode cur = dummy;
        while (cur != null) {
            stack.push(cur);
            cur = cur.next;
        }
        for (int i = 0; i < n; ++i) {
            stack.pop();
        }
        ListNode prev = stack.peek();
        prev.next = prev.next.next;
        ListNode ans = dummy.next;
        return ans;
    }

    /**
     * 方法3：通过双指针
     *
     * @param head
     * @param n
     * @return
     */
    public static ListNode removeNthFromEndByTwoPoints(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = head;
        ListNode second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first.next;
        }
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;
        ListNode ans = dummy.next;
        return ans;
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
     * 构造存在环的情况
     *
     * @param array
     * @return
     */
    private static ListNode initLinkedListHasCycle(int[] array) {
        ListNode head = null, cur = null;
        ListNode corss = null;
        for (int i = 0; i < array.length; i++) {
            ListNode newNode = new ListNode(array[i]);
            newNode.next = null;
            if (i == 0) {
                head = newNode;
                cur = head;
            } else {
                cur.next = newNode;
                cur = newNode;
                //找到中间位置结点
                if (i == array.length / 2) {
                    corss = cur;
                }
            }
        }
        //制造环
        cur.next = corss;
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
