package com.yugutou.charpter5_queue_map.level1;

public class LinkQueue {
    private Node front;
    private Node rear;
    private int size;

    public LinkQueue() {
        this.front = new Node(0);
        this.rear = new Node(0);
    }

    /**
     * 入队
     */
    public void push(int value) {
        Node newNode = new Node(value);
        Node temp = front;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        rear = newNode;
        size++;
    }

    /**
     * 出队
     */
    public int pull() {
        if (front.next == null) {
            System.out.println("队列已空");
        }
        Node firstNode = front.next;
        front.next = firstNode.next;
        size--;
        return firstNode.data;
    }

    /**
     * 遍历队列
     */
    public void traverse() {
        Node temp = front.next;
        while (temp != null) {
            System.out.print(temp.data + "\t");
            temp = temp.next;
        }
    }

    static class Node {
        public int data;
        public Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    //测试main方法
    public static void main(String[] args) {
        LinkQueue linkQueue = new LinkQueue();
        linkQueue.push(1);
        linkQueue.push(2);
        linkQueue.push(3);
        System.out.println("第一个出队的元素为:" + linkQueue.pull());
        System.out.println("队列中的元素为:");
        linkQueue.traverse();
    }
}

