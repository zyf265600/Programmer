package com.yugutou.charpter1_linklist.level3;

import java.util.HashSet;
import java.util.Set;

public class HasCycle {
    /**
     * 判断是否存在环
     *
     * @param args
     */
    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5, 6};
        ListNode nodeA = null;

        //构造链表是否存在环
        int isCycle = 2;
        switch (isCycle) {
            case 1://构造的链表中存在环
                nodeA = initLinkedListHasCycle(a);
                break;
            case 2://构造的链表中部不存在环
                nodeA = initLinkedList(a);
                break;
        }


        //测试哪个方法
        int testmethod = 2;
        boolean result = false;
        switch (testmethod) {
            case 1:
                result = hasCycleByMap(nodeA);
                break;
            case 2:
                result = hasCycleByTwoPoint(nodeA);
                break;
        }

        System.out.println(result);

    }

    /**
     * 方法1：通过HashMap判断
     *
     * @param head
     * @return
     */
    public static boolean hasCycleByMap(ListNode head) {
        Set<ListNode> seen = new HashSet<ListNode>();
        while (head != null) {
            if (!seen.add(head)) {
                return true;
            }
            head = head.next;
        }
        return false;
    }

    /**
     * 方法2 通过双指针实现
     *
     * @param head
     * @return
     */

    public static boolean hasCycleByTwoPoint(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
                return true;
        }
        return false;
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
