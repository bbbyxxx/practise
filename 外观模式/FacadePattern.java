package 外观模式;

public class FacadePattern {
    public static void main(String[] args) {
        Facade fd = new Facade();
        fd.funA();
        fd.funB();
    }

}

class SubSystemA{
    public void funA(){
        //业务代码
        System.out.println("SubSystemA--funA()");
    }
}

class SubSystemB{
    public void funB(){
        //业务代码
        System.out.println("SubSystemB--funB()");
    }
}

class Facade{
    private SubSystemA sa = new SubSystemA();
    private SubSystemB sb = new SubSystemB();

    public void funA(){
        sa.funA();
    }
    public void funB(){
        sb.funB();
    }
}
