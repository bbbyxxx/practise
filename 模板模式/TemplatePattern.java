package 模板模式;
/*
AbstractClass：抽象类
抽象类
定义基本操作和模板方法。
基本操作(PrimitiveOperations)：每一个基本操作对应实现算法的一个步骤，在其子类中可以重定义或实现这些步骤。
模板方法(Template Method)：用于定义算法的框架。可以调用抽象类中基本方法，在抽象类的子类中实现的基本方法，还可以调用其他对象中的方法。
ConcreteClass：具体子类
具体类
抽象类的子类。
实现在父类中声明的抽象基本操作，或者重写在父类中已经实现的具体基本操作。
 */
public class TemplatePattern {
    public static void main(String[] args) {
        AbstractClass c = new ConcreteClassA();
        c.templateMethod();
        System.out.println("-------------");
        c = new ConcreteClassB();
        c.templateMethod();
    }
}

//模板方法为具体的方法，因此不能用接口，只能用抽象类来实现
abstract class AbstractClass{
    //将基本方法组合在一起
    public void templateMethod(){
        primitiveOperation1();
        primitiveOperation2();
        primitiveOperation3();
    }
   //抽象类中的基本方法
    public void primitiveOperation1(){
        System.out.println("AbstractClass primitiveOperation1（）");
    }
    //让子类实现的方法
    public abstract void primitiveOperation2();
    //空方法，子类中通过选择是否通过覆盖此方法来控制某些操作是否执行
    public void primitiveOperation3(){

    }
}

class ConcreteClassA extends AbstractClass{

    @Override
    public void primitiveOperation2() {
        System.out.println(" ConcreteClassA primitiveOperation2()");
    }

    @Override
    public void primitiveOperation3() {
        System.out.println(" ConcreteClassA primitiveOperation3()");
    }
}

class ConcreteClassB extends AbstractClass{

    @Override
    public void primitiveOperation2() {
        System.out.println(" ConcreteClassB primitiveOperation2()");
    }

    @Override
    public void primitiveOperation3() {
        System.out.println(" ConcreteClassB primitiveOperation3()");
    }
}