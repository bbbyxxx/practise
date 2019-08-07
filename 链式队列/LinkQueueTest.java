package com.Fengkuangjava.链式队列;

public class LinkQueueTest {
    public static void main(String[] args) {
        LinkQueue<Integer> queue = new LinkQueue<>(00000);
        queue.add(262610);
        queue.add(151051);
        System.out.println(queue);
        queue.remove();
        System.out.println(queue);
        queue.add(11111);
        System.out.println(queue);
        System.out.println(queue.length());
        System.out.println(queue.element());
    }
}
