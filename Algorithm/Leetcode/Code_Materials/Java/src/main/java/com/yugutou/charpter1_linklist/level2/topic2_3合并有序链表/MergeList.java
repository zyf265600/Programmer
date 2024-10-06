package com.yugutou.charpter1_linklist.level2.topic2_3合并有序链表;

public class MergeList {
    public static void main(String[] args) {
        int[] a = {1, 5, 8, 12};
        ListNode nodeA = initLinkedList(a);
        int[] b = {2, 5, 9, 13};
        ListNode nodeB = initLinkedList(b);
        int[] c = {3, 6, 10, 14};
        ListNode nodeC = initLinkedList(c);
        ListNode[] array = {nodeA, nodeB, nodeC};
        ListNode d = null;

        int[] e = {1, 2, 3, 4, 5, 6};
        ListNode nodeD = initLinkedList(e);
        System.out.println(middleNode(nodeD).val);

        int testMethod = 2;
        switch (testMethod) {
            case 1://最直接的方法
                d = mergeTwoLists2(nodeA, nodeB);
                break;
            case 2://简化方法1中的方法
                d = mergeTwoListsMoreSimple(nodeA, nodeB);
                break;
            case 3://通过递归方式来实现
                d = mergeTwoListsByRe(nodeA, nodeB);
                break;
            case 4://测试K个链表合并
                d = mergeKLists(array);
        }


        System.out.println(toString(d));

    }

    public static ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    /**
     * 方法1：面试时就能写出来的方法
     *
     * @param list1
     * @param list2
     * @return
     */
    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // write code here
        ListNode newHead = new ListNode(-1);
        ListNode res = newHead;
        while (list1 != null || list2 != null) {

            if (list1 != null && list2 != null) {//都不为空的情况
                if (list1.val < list2.val) {
                    newHead.next = list1;
                    list1 = list1.next;
                } else if (list1.val > list2.val) {
                    newHead.next = list2;
                    list2 = list2.next;
                } else { //相等的情况，分别接两个链
                    newHead.next = list2;
                    list2 = list2.next;
                    newHead = newHead.next;
                    newHead.next = list1;
                    list1 = list1.next;
                }
                newHead = newHead.next;
            } else if (list1 != null && list2 == null) {
                newHead.next = list1;
                list1 = list1.next;
                newHead = newHead.next;
            } else if (list1 == null && list2 != null) {
                newHead.next = list2;
                list2 = list2.next;
                newHead = newHead.next;
            }
        }
        return res.next;
    }


    public static ListNode mergeTwoLists2(ListNode list1, ListNode list2) {
        // write code here
        ListNode newHead = new ListNode(-1);
        ListNode res = newHead;
        while (list1 != null && list2 != null) {

            if (list1.val < list2.val) {
                newHead.next = list1;
                list1 = list1.next;
            } else if (list1.val > list2.val) {
                newHead.next = list2;
                list2 = list2.next;
            } else { //相等的情况，分别接两个链
                newHead.next = list2;
                list2 = list2.next;
                newHead = newHead.next;
                newHead.next = list1;
                list1 = list1.next;
            }
            newHead = newHead.next;

        }
        while (list1 != null) {
            newHead.next = list1;
            list1 = list1.next;
            newHead = newHead.next;
        }
        while (list2 != null) {
            newHead.next = list2;
            list2 = list2.next;
            newHead = newHead.next;
        }

        return res.next;
    }


    /**
     * 方法2：比方法1更加精简的实现方法
     *
     * @param l1
     * @param l2
     * @return
     */
    public static ListNode mergeTwoListsMoreSimple(ListNode l1, ListNode l2) {
        ListNode prehead = new ListNode(-1);
        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }
        // 最多只有一个还未被合并完，直接接上去就行了,这是链表合并比数组合并方便的地方
        prev.next = l1 == null ? l2 : l1;
        return prehead.next;
    }

    /**
     * 方法3：通过递归方式来实现
     *
     * @param l1
     * @param l2
     * @return
     */
    public static ListNode mergeTwoListsByRe(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
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

    /**
     * 合并K个链表
     *
     * @param lists
     * @return
     */
    public static ListNode mergeKLists(ListNode[] lists) {
        ListNode res = null;
        for (ListNode list : lists) {
            res = mergeTwoListsMoreSimple(res, list);
        }
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

    static class ListNode {
        public int val;
        public ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
