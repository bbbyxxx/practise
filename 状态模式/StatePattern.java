package 状态模式;

public class StatePattern {
    public static void main(String[] args) {
        //创建环境类对象
        Context context = new Context();
        //创建状态A对象
        ConcreteStateA stateA = new ConcreteStateA();
        context.setState(stateA);
        context.request();

        context.changeValue(1);
        context.request();

        context.changeValue(0);
        context.request();
    }
}

//抽象状态类
abstract class State{
    //声明抽象方法，多态到具体实现类
    public abstract void handle(Context context);
}

//具体状态类
class ConcreteStateA extends State {
    public void handle(Context context) {
        System.out.println("当前状态是 A.");
    }
}
class ConcreteStateB extends State {
    public void handle(Context context) {
        System.out.println("当前状态是B.");
    }
}

//环境类
class Context{
    private State state;//维持一个抽象状态对象的引用
    public void setState(State state){
        this.state = state;
    }
    //状态转换（不遵守开闭原则）
    public void changeValue(int value){
        if (value==0){
            this.setState(new ConcreteStateA());
        }else{
            this.setState(new ConcreteStateB());
        }
    }

    public void request(){
        state.handle(this);//调用对应不同状态对象的业务方法
    }
}