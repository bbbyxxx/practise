package com.Fengkuangjava.数组;

import com.Fengkuangjava.SequenceList;

public class SequenceListTest {
    public static void main(String[] args) {
        SequenceList<String> list = new SequenceList<>();
        list.add("aaaaa");
        list.add("bbbbb");
        list.add("ccccc");
        //在索引为1处插入一个新元素
        list.insert("ddddd",1);
        System.out.println(list);//输出
        //删除索引为2处的元素
        list.delete(2);
        System.out.println(list);
        //获取ccccc字符串在顺序线性表中的位置
        System.out.println(list.locate("ccccc"));
        //获取指定索引处的值
        System.out.println(list.get(2));
    }
}
