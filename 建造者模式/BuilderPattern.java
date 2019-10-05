package 建造者模式;

public class BuilderPattern {
    public static void main(String[] args) {
        ConcreteBuilder concreteBuilder = new ConcreteBuilder();
        Director director = new Director(concreteBuilder);
        Product product = director.construct();
        System.out.println(product.toString());
        System.out.println("-----------------");
        ConcreteBuilder2 concreteBuilder2 = new ConcreteBuilder2();
        director = new Director(concreteBuilder2);
        product = director.construct();
        System.out.println(product);
    }

}

//产品类
class Product{
    private String partA;
    private String partB;
    private String partC;

    public void setPartA(String partA) {
        this.partA = partA;
    }

    public void setPartB(String partB) {
        this.partB = partB;
    }

    public void setPartC(String partC) {
        this.partC = partC;
    }

    public String getPartA() {
        return partA;
    }

    public String getPartB() {
        return partB;
    }

    public String getPartC() {
        return partC;
    }

    @Override
    public String toString() {
        return "Product{" +
                "partA='" + partA + '\'' +
                ", partB='" + partB + '\'' +
                ", partC='" + partC + '\'' +
                '}';
    }
}

//抽象建造者
interface Builder{
    public  void buildPartA();
    public  void buildPartB();
    public  void buildPartC();
    public  Product getResult();
}
//具体建造者
class ConcreteBuilder implements Builder{
    Product product = new Product();

    @Override
    public void buildPartA() {
        product.setPartA("A");
    }

    @Override
    public void buildPartB() {
        product.setPartB("B");
    }

    @Override
    public void buildPartC() {
        product.setPartC("C");
    }

    @Override
    public Product getResult() {
        return product;
    }
}
//具体建造者
class ConcreteBuilder2 implements Builder{
    Product product = new Product();

    @Override
    public void buildPartA() {
        product.setPartA("aa");
    }

    @Override
    public void buildPartB() {
        product.setPartB("bb");
    }

    @Override
    public void buildPartC() {
        product.setPartC("cc");
    }

    @Override
    public Product getResult() {
        return product;
    }
}
//指挥/导演类
class Director {
    private Builder builder;

    public Director(Builder builder) {
        this.builder = builder;
    }

    public void setBuilder(Builder builder) {
        this.builder = builder;
    }

    public Product construct() {
        builder.buildPartA();
        builder.buildPartB();
        builder.buildPartC();
        return builder.getResult();
    }
}
