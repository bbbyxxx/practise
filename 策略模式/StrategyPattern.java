package 策略模式;
/*
Context: 上下文类
具体类
选择策略解决问题（通过一个ConcreteStrategy对象来配置）。
维持着一个抽象策略类Strategy的引用。
Strategy: 抽象策略类
具体类/抽象类/接口
具体策略类的父类。
定义所有支持的算法的接口。Context使用这个接口来调用某个ConcreteStrategy定义的算法。
ConcreteStrategy: 具体策略类
具体类
抽象策略类Strategy的子类。
每个策略类对应一种策略。
 */
public class StrategyPattern {
    public static void main(String[] args) {
            Context context = new Context();
            ConcreteStrategyA concreteStrategyA = new ConcreteStrategyA();
            context.setStrategy(concreteStrategyA);
            context.algorithm();
    }
}

class Context{
    //对抽象策略类的引用
    private Strategy strategy;

    public void setStrategy(Strategy strategy){
        this.strategy = strategy;
    }

    //调用策略类
    public void algorithm(){
        strategy.algorithm();
    }
}

//抽象策略类
abstract class Strategy{
    public abstract void algorithm();
}

//具体策略类
class ConcreteStrategyA extends Strategy{
    @Override
    public void algorithm() {
        System.out.println("具体策略类A");
    }
}

class ConcreteStrategyB extends Strategy{
    @Override
    public void algorithm() {
        System.out.println("具体策略类B");
    }
}


