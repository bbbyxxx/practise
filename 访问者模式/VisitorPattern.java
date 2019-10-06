package 访问者模式;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class VisitorPattern {
    public static void main(String[] args) {
         List<Element> list = ObjectStruct.getList();
        for (Element e:list) {
            e.accept(new Visitor1());
        }
    }
}

//抽象元素类
abstract class Element{
    public abstract void accept(Visitor visitor);
    public abstract void doSomething();
}

//具体元素类
class ConcreteElement1 extends Element{
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    @Override
    public void doSomething() {
        System.out.println("元素1");
    }
}
//具体元素类
class ConcreteElement2 extends Element{
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    @Override
    public void doSomething() {
        System.out.println("元素2");
    }
}

//抽象访问者类
abstract class Visitor{
    public abstract void visit(ConcreteElement1 element1);
    public abstract void visit(ConcreteElement2 element2);
}

//具体访问者类
class Visitor1 extends Visitor{
    @Override
    public void visit(ConcreteElement1 element1) {
        element1.doSomething();
    }

    @Override
    public void visit(ConcreteElement2 element2) {
        element2.doSomething();
    }
}

//对象结构类
class ObjectStruct{
    public static List<Element> getList(){
        List<Element> list = new ArrayList<Element>();
        Random ran = new Random();
        for (int i = 0; i < 10; i++) {
            int a = ran.nextInt(100);
            if (a>50){
                list.add(new ConcreteElement1());
            }else{
                list.add(new ConcreteElement2());
            }
        }
        return list;
    }
}
