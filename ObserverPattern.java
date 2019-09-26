package 观察者模式;

import java.util.ArrayList;

public class ObserverPattern {
    public static void main(String[] args) {
        ConcreteSubjectA csa = new ConcreteSubjectA();//具体主题类对象（即被观察者）
        ConcreteObserverA coa = new ConcreteObserverA(csa);//具体观察者观察某被观察者
        ConcreteObserverB cob = new ConcreteObserverB(csa);
        csa.dataChange(3,4);
        coa.print();
        cob.print();
    }
}

//抽象主题类
abstract class Subject{
    public abstract void add(Observer t);
    public abstract void notifys();
}

//具体主题类
class ConcreteSubjectA extends Subject{
    private int x;
    private int y;
    private ArrayList<Observer> list = new ArrayList<Observer>();
    public ConcreteSubjectA(){
        x = 0;
        y = 0;
    }
    public ConcreteSubjectA(int x,int y){
        this.x = x;
        this.y = y;
    }
    @Override
    public void add(Observer t) {
        list.add(t);
    }

    @Override
    public void notifys() {
        for (Observer ob:list) {
            ob.update(x,y);
        }
    }

    public void dataChange(int x,int y){
        this.x = x;
        this.y = y;
        notifys();
    }
}

class ConcreteSubjectB extends Subject{
    private int x;
    private int y;
    private ArrayList<Observer> list = new ArrayList<Observer>();
    public ConcreteSubjectB(){
        x = 0;
        y = 0;
    }
    public ConcreteSubjectB(int x,int y){
        this.x = x;
        this.y = y;
    }
    @Override
    public void add(Observer t) {
        list.add(t);
    }

    @Override
    public void notifys() {
        for (Observer ob:list) {
            ob.update(x,y);
        }
    }

    public void dataChange(int x,int y){//处理数据变换
        this.x = x;
        this.y = y;
        notifys();
    }
}

//抽象观察者类
abstract class Observer{
    protected Subject st;
    public Observer(Subject t){
        st = t;
        st.add(this);//基类指针指向派生类对象  多态
    }
    public abstract void update(int x,int y);
}
//具体的观察者类
class ConcreteObserverA extends Observer{
    private int x;
    private int y;
    public ConcreteObserverA(Subject tt){
        super(tt);//调上去来做初始化，从而实现自己判断要观察哪个
    }
    @Override
    public void update(int x,int y) {
        this.x = x;
        this.y = y;
    }

    public void print(){
        System.out.println(x+"   "+y);
    }
}

class ConcreteObserverB extends Observer{
    private int x;
    private int y;
    public ConcreteObserverB(Subject tt){
        super(tt);//调上去来做初始化，从而实现自己判断要观察哪个
    }
    @Override
    public void update(int x,int y) {
        this.x = x;
        this.y = y;
    }

    public void print(){
        System.out.println(x+"   "+y);
    }
}
