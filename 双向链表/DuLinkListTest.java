package com.Fengkuangjava.双向链表;

public class DuLinkListTest {
    public static void main(String[] args) {
        DuLinkList<String> list = new DuLinkList<>();
        list.insert("aaaaa",0);
        list.add("bbbbb");
        list.insert("ccccc",0);
        list.insert("ddddd",1);
        System.out.println(list);
        list.delete(2);
        System.out.println(list);
        System.out.println(list.reverseToString());
        System.out.println(list.locate("ccccc"));
        System.out.println(list.get(2));
        list.remove();
        System.out.println(list);
        list.delete(0);
        System.out.println(list);
    }
}
