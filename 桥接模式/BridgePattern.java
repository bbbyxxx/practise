package 桥接模式;

public class BridgePattern {
    public static void main(String[] args) {
        Abstraction ac = new RefinedAbstraction(new ConcreteImplementorA());
        ac.operation();
        Abstraction ad = new RefinedAbstraction(new ConcreteImplementorB());
        ad.operation();
    }
}

abstract class Abstraction{
     protected Implementor im = null;
     public abstract void operation();
}
class RefinedAbstraction extends Abstraction{
    public RefinedAbstraction(Implementor implementor){
        im = implementor;
    }
    public void operation() {
        im.operationImpl();
    }
}

interface Implementor{
    void operationImpl();
}
class ConcreteImplementorA implements Implementor{
    public void operationImpl() {
        System.out.println("11111");
    }
}
class ConcreteImplementorB implements Implementor{
    public void operationImpl() {
        System.out.println("22222");
    }
}
