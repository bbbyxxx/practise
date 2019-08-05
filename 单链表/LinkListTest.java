package com.Fengkuangjava.单链表;

public class LinkListTest {
    public static void main(String[] args) {
        LinkList<String> list = new LinkList<>();
        list.insert("aaaaa",0);
        list.add("bbbbb");
        list.add("ccccc");
        //在索引为1处插入一个元素
        list.insert("ddddd",1);
        System.out.println(list);
        //删除索引为2处的元素
        list.delete(2);
        System.out.println(list);
        //获取ccccc字符串在链表中的位置
        System.out.println(list.locate("ccccc"));
        System.out.println(list.get(1));
    }
}
