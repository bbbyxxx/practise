package 适配器模式;

public class AdapterPattern {
    public static void main(String[] args) {
        new Adapter(new Adaptee()).Adaptee();
    }
}

class Adaptee{
    public void Adaptee(){
        System.out.println("11111");
    }
}
class Adapter{
    private Adaptee at;
    public Adapter(Adaptee t){
        at = t;
    }
    public void Adaptee(){
        at.Adaptee();
    }
}
