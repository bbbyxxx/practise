package 适配器模式;

public class ClassAdapterPattern {
    public static void main(String[] args) {
        Target tt = new AdapterA(new Adaptee2(3));
        tt.Print();
    }
}

interface Target{
    void Print();
}

class AdapterA implements Target{
    private Adaptee2 pc = null;
    public AdapterA(Adaptee2 c){
        pc = c;
    }
    public void Print() {
        pc.Print(pc.getC());
    }
}


class AdapterB implements Target{
    private Adaptee2 pc = null;
    public AdapterB(Adaptee2 c){
        pc = c;
    }
    public void Print() {
        pc.Print();
    }
}

class Adaptee2{
    private int c;
    public Adaptee2(int ttt){
        c = ttt;
    }
    public void Print(int t){
        System.out.println(t);
    }
    public void Print(){
        System.out.println(0);
    }

    public int getC() {
        return c;
    }
}


