package com.yugutou.charpter1_linklist.level2.topic2_4双指针;

/**
 * 寻找链表中间结点
 */
public class MiddleNode {

    public static void main(String[] args) {
        int[] a = {1,2,3,4,5};
        ListNode nodeA = initLinkedList(a);
        ListNode middle = middleNode(nodeA);
        System.out.println(middle.val);
    }

    public static ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
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
