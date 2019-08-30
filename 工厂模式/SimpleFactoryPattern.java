package 工厂模式;
//在设计模式中，所谓的“实现一个接口”，并“不一定”表示“写一个类，并利用implements杆件自实现某个接口”
//“实现一个接口”泛指“实现某个超类型（可以是类或接口）的某个方法”
public class SimpleFactoryPattern {
    private Product product;
    public SimpleFactoryPattern(int n ){
        switch(n){
            case 1:product = new ProductA();
                break;
            case 2:product = new ProductB();
                break;
            case 3:product = new ProductC();
        }
    }
    public void send(){
        product.Do();
    }

    public static void main(String[] args) {
        SimpleFactoryPattern factory = new SimpleFactoryPattern(1);
        factory.send();
    }
}

interface Product{
    void Do();
}

class ProductA implements Product{
    public void Do(){
        System.out.println("ProductA");
    }
}
class ProductB implements Product{
    public void Do(){
        System.out.println("ProductB");
    }
}
class ProductC implements Product{
    public void Do() {
        System.out.println("ProductC");
    }
}
