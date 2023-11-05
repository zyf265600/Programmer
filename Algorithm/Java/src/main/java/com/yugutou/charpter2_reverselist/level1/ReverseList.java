package com.yugutou.charpter2_reverselist.level1;

public class ReverseList {
    public static void main(String[] args) {
        int[] a = {4, 3, 2, 1};
        ListNode nodeA = initLinkedList(a);
        ListNode d = null;
        int testMethod = 4;
        switch (testMethod) {
            case 1://方法2：虚拟结点，,并复用已有的结点
                d = reverseListByDummyNotCreate(nodeA);
                break;
            case 2://方法3：不适用虚拟结点的反转方法
                d = reverseListSimple(nodeA);
                break;
            case 3:
                d = reverseListByRecurse(nodeA);
        }

        System.out.println(toString(d));

    }

    /**
     * 方法1：虚拟结点，,并复用已有的结点
     *
     * @param head
     * @return
     */
    public static ListNode reverseListByDummyNotCreate(ListNode head) {
        ListNode ans = new ListNode(-1);
        ListNode cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = ans.next;
            ans.next = cur;
            cur = next;
        }
        return ans.next;
    }


    /**
     * 方法3：不适用头结点，基本的反转方法
     *
     * @param head
     * @return
     */
    public static ListNode reverseListSimple(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    /**
     * 方法4：通过递归实现链表反转
     */

    public static ListNode reverseListByRecurse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode newHead = reverseListByRecurse(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
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