package com.yugutou.charpter1_linklist.level1;

/**
 * 构造链表，使用静态内部类定表示结点，实现增加和删除元素的功能
 *
 */
public class BasicLinkList {
    static class Node {
        final int data;
        Node next;
        public Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        // 头部添加节点1
        Node head = new Node(1);
        System.out.println("头部添加节点1：" + BasicLinkList.toString(head));

        System.out.println("链表长度为：" + getLength(head));
        // 尾部添加节点2
        Node node = new Node(2);
        head = BasicLinkList.insertNode(head, node, 2);
        System.out.println("尾部添加节点2：" + BasicLinkList.toString(head));
        System.out.println("链表长度为：" + getLength(head));
        // 中间添加节点3
        node = new Node(3);
        head = BasicLinkList.insertNode(head, node, 2);
        System.out.println("中间添加节点3：" + BasicLinkList.toString(head));

        // 删除中间节点2
        head = BasicLinkList.deleteNode(head, 2);
        System.out.println("删除中间节点3：" + BasicLinkList.toString(head));

        // 删除头部节点1
        head = BasicLinkList.deleteNode(head, 1);
        System.out.println("删除头部节点1：" + BasicLinkList.toString(head));
    }

    /**
     * 获取链表长度
     *
     * @param head 链表头节点
     * @return 链表长度
     */
    public static int getLength(Node head) {
        int length = 0;
        Node node = head;
        while (node != null) {
            length++;
            node = node.next;
        }
        return length;
    }

    /**
     * 链表插入
     *
     * @param head       链表头节点
     * @param nodeInsert 待插入节点
     * @param position   待插入位置，取值从2开始
     * @return 插入后得到的链表头节点
     */
    public static Node insertNode(Node head, Node nodeInsert, int position) {
        // 需要判空，否则后面可能会有空指针异常
        if (head == null) {
            return nodeInsert;
        }
        //越界判断
        int size = getLength(head);
        if (position > size + 1 || position < 1) {
            System.out.println("位置参数越界");
            return head;
        }

        //在链表开头插入
        if (position == 1) {
            nodeInsert.next = head;
//            return nodeInsert;
            //上面return还可以这么写：
            head = nodeInsert;
            return head;
        }

        Node pNode = head;
        int count = 1;
        while (count < position - 1) {
            pNode = pNode.next;
            count++;
        }
        nodeInsert.next = pNode.next;
        pNode.next = nodeInsert;

        return head;
    }

    /**
     * 删除节点
     *
     * @param head     链表头节点
     * @param position 删除节点位置，取值从1开始
     * @return 删除后的链表头节点
     */
    public static Node deleteNode(Node head, int position) {
        if (head == null) {
            return null;
        }
        int size = getLength(head);
        //思考一下，这里为什么是size，而不是size+1
        if (position > size || position <1) {
            System.out.println("输入的参数有误");
            return head;
        }
        if (position == 1) {
            //curNode就是链表的新head
            return head.next;
        } else {
            Node cur = head;
            int count = 1;
            while (count < position - 1) {
                cur = cur.next;
                count++;
            }
            Node curNode = cur.next;
            cur.next = curNode.next;
        }
        return head;
    }

    /**
     * 输出链表
     *
     * @param head 头节点
     */
    public static String toString(Node head) {
        Node current = head;
        StringBuilder sb = new StringBuilder();
        while (current != null) {
            sb.append(current.data).append("\t");
            current = current.next;
        }
        return sb.toString();
    }

}
