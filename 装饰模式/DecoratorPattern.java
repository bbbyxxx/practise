package 装饰模式;

public class DecoratorPattern {
    public static void main(String[] args) {
        Component component = new ConcreteComponent();
        Decorator decorator = new ConcreteDecorator(component);
        component.operation();
        System.out.println("-----------------------------------");
        decorator.operation();
    }
}
interface Component{
    void operation();
}
class ConcreteComponent implements Component{
    public void operation() {
        System.out.println("ConcreteComponent.operation()");
    }
}
//装饰器为它增加其他额外方法
class Decorator implements Component{
    private Component component;//维持一个对抽象构件对象的引用
    public Decorator(Component component){//注入一个抽象构件类型的对象
        this.component = component;
    }

    public void operation() {
        component.operation();//调用原有业务的方法
    }
}
//具体装饰类
class ConcreteDecorator extends Decorator{
    public ConcreteDecorator(Component component){
        super(component);
    }
    //新增业务方法
    public void addedBehavior(){
        System.out.println("ConcreteDecorator.addedBehavior()");
    }
    public void operation() {
        super.operation(); // 调用原有业务方法
        addedBehavior(); // 调用新增业务方法
    }
}