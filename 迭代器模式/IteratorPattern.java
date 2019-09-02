package 迭代器模式;

import java.util.ArrayList;
import java.util.List;

/*
定义：提供一种方法访问一个容器对象中各个元素，而又不暴露该对象的内部细节。
类型：行为类模式
迭代器模式的结构：
抽象容器：一般是一个接口，提供一个iterator()方法，例如java中的Collection接口，List接口，Set接口等。
具体容器：就是抽象容器的具体实现类，比如List接口的有序列表实现ArrayList，List接口的链表实现LinkList，Set接口的哈希列表的实现HashSet等。
抽象迭代器：定义遍历元素所需要的方法，一般来说会有这么三个方法：取得第一个元素的方法first()，取得下一个元素的方法next()，判断是否遍历结束的方法isDone()（或者叫hasNext()），移出当前对象的方法remove(),
迭代器实现：实现迭代器接口中定义的方法，完成集合的迭代。
 */
public class IteratorPattern {
    public static void main(String[] args) {
        Aggregate ag = new ConcreteAggregate();
        ag.add("1");
        ag.add("2");
        ag.add("3");
        Iterator it = ag.iterator();
        while(it.hasNext()){
            System.out.println((String)it.next());
        }
    }
}
interface Iterator{
    public Object next();
    public boolean hasNext();
}
class ConcreteIterator implements Iterator{
    private List list = new ArrayList();
    private int cnt = 0;
    public ConcreteIterator(List list){
        this.list = list;
    }

    public Object next() {
        Object obj = null;
        if (this.hasNext()){
            obj = this.list.get(cnt++);
        }
        return obj;
    }

    public boolean hasNext() {
        if (cnt == list.size()){
            return false;
        }
        return true;
    }
}
interface Aggregate{
    public void add(Object obj);
    public void remove(Object obj);
    public Iterator iterator();
}
class ConcreteAggregate implements Aggregate{
    private List list = new ArrayList();

    public void add(Object obj) {
        list.add(obj);
    }

    public void remove(Object obj) {
        list.remove(obj);
    }

    public Iterator iterator() {
        return new ConcreteIterator(list);
    }
}

