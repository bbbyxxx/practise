package 工厂模式;

public abstract class AbstractFactoryPattern {
    protected Productb productb;
    public abstract void send();

    public static void main(String[] args) {
        AbstractFactoryPattern a = new FactoryA(new Product4());
        a.send();
    }
}
interface Productb{
    void Do();
}
class Product3 implements Productb{
    public void Do(){
        System.out.println("Product3");
    }
}
class Product4 implements Productb{
    public void Do(){
        System.out.println("Product4");
    }
}
class FactoryA extends AbstractFactoryPattern{
    public FactoryA(Productb product){
        productb = product;
    }
    public void send(){
        productb.Do();
    }
}
class FactoryB extends AbstractFactoryPattern{
    public FactoryB(Productb product){
        productb = product;
    }
    public void send(){
        productb.Do();
    }
}