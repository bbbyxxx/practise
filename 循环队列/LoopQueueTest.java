package com.Fengkuangjava.循环队列;

public class LoopQueueTest {
    public static void main(String[] args) {
        LoopQueue<String> queue = new LoopQueue<>("aaaaa",3);
        queue.add("bbbbb");
        queue.add("ccccc");
        System.out.println(queue);
        queue.remove();
        System.out.println(queue);
        queue.add("aaaaa");
        System.out.println(queue);
        System.out.println(queue.length());
    }
}
