package com.yugutou.charpter4_stack.level1;

import java.util.LinkedList;

/**
 * 基于Java的LinkedList来实现栈
 * @param <T>
 */
public class LinkedListStack<T> {
    private LinkedList<T> ll = new LinkedList<>();

    //入栈
    public void push(T t) {
        ll.addFirst(t);
    }

    //出栈
    public T pop() {
        return ll.removeFirst();
    }

    //栈顶元素
    public T peek() {
        T t = null;
        //直接取元素会报异常，需要先判断是否为空
        if (!ll.isEmpty())
            t = ll.getFirst();
        return t;
    }

    //栈空
    public boolean isEmpty() {
        return ll.isEmpty();
    }

    public static void main(String[] args) {
        LinkedListStack<String> stack = new LinkedListStack();
        System.out.println(stack.isEmpty());
        System.out.println(stack.peek());
        stack.push("java");
        stack.push("is");
        stack.push("beautiful");
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.isEmpty());
    }
}
