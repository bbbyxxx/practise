package 代理模式;

public class ProxyPattern {
    public static void main(String[] args) {
        Base bs = new Proxy(new Source());
        bs.method(2);

    }
}

interface Base{
    void method();
    void method(int t);
}

class Proxy implements Base{
    private Base bs = null;
    public Proxy(Base bs){
        this.bs = bs;
    }
    public void method() {
        bs.method();
    }

    public void method(int t) {
        bs.method(t);
    }
}

class Source implements Base{
    public void method() {
        System.out.println("我才是无参的实现类");
    }
    public void method(int x){
        System.out.println("我是有参的实现类"+x);
    }
}
