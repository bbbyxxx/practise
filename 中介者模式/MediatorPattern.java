package 中介者模式;

import javax.print.attribute.standard.Media;

public class MediatorPattern {
    public static void main(String[] args) {
        //创建中介者
        ConcreteMediator mi = new ConcreteMediator();
        //创建同事对象
        ConcreteColleague1 c1 = new ConcreteColleague1(mi);
        ConcreteColleague2 c2 = new ConcreteColleague2(mi);
        //将同事对象放入中介者    也可用构造函数注入，参数为基类引用
        mi.setC1(c1);
        mi.setC2(c2);
        c1.myselfMethod();
        c1.depMethod();
        c2.myselfMethod();
        c2.depMethod();
    }
}

//抽象同事类
abstract class Colleague{
    protected Mediator mediator;
    public Colleague(Mediator mediator){
        this.mediator = mediator;
    }
}

//具体同事类
class ConcreteColleague1 extends Colleague{
    //通过构造函数传递中介者
    public ConcreteColleague1(Mediator mediator){
        super(mediator);
    }
    //自己的业务方法
    public void myselfMethod(){
        System.out.println("同事一的方法");;
    }
    //自己处理不了的方法
    public void depMethod(){
        super.mediator.doSomething2();
    }
}

class ConcreteColleague2 extends Colleague{
    //通过构造函数传递中介者
    public ConcreteColleague2(Mediator mediator){
        super(mediator);
    }
    //自己的业务方法
    public void myselfMethod(){
        System.out.println("同事二的方法");;
    }
    //自己处理不了的方法
    public void depMethod(){
        super.mediator.doSomething1();
    }
}

//抽象中介者类
abstract class Mediator{
    //定义同事类
    protected ConcreteColleague1 c1;
    protected ConcreteColleague2 c2;

    public void setC1(ConcreteColleague1 c1) {
        this.c1 = c1;
    }

    public void setC2(ConcreteColleague2 c2) {
        this.c2 = c2;
    }

    public ConcreteColleague1 getC1() {
        return c1;
    }

    public ConcreteColleague2 getC2() {
        return c2;
    }

    //具体中介者应实现的业务
    public abstract void doSomething1();
    public abstract void doSomething2();
}

//具体中介者
class ConcreteMediator extends Mediator{
    @Override
    public void doSomething1() {
        super.c1.myselfMethod();
    }
    @Override
    public void doSomething2() {
        super.c2.myselfMethod();
    }
}
