package 工厂模式;

public class FactoryMethodPattern {
    private Producta product;
    public FactoryMethodPattern(Producta product){
        this.product = product;
    }
    public void send(){
        product.Do();
    }

    public static void main(String[] args) {
        FactoryMethodPattern fc = new FactoryMethodPattern(new Product2());
        fc.send();
    }
}

interface Producta{
   void Do();
}
class Product1 implements Producta{
    public void Do() {
        System.out.println("Product1");
    }
}
class Product2 implements Producta{
    public void Do() {
        System.out.println("Product2");
    }
}
