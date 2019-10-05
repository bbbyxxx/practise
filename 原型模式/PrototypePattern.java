package 原型模式;

public class PrototypePattern {
    public static void main(String[] args) {
        ConcretePrototype cp = new ConcretePrototype();
        for (int i = 0; i < 5; i++) {
            ConcretePrototype clonecp = (ConcretePrototype)cp.clone();
            clonecp.show();
        }
    }
}

interface Prototype{
    public Prototype clone();
}

class ConcretePrototype implements Prototype,Cloneable{
    @Override
    public Prototype clone() {
        ConcretePrototype prototype = null;
        try{
            prototype = (ConcretePrototype)super.clone();
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
        return prototype;
    }

    public void show(){
        System.out.println("ConcretePrototype1:{}" + this.toString());
    }
}
