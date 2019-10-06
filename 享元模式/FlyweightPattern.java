package 享元模式;

import java.util.HashMap;

public class FlyweightPattern {
    public static void main(String[] args) {
        Flyweight fw = FlyweightFactory.getFlyweight("1");
        System.out.println(fw.toString());
        Flyweight fw2 = FlyweightFactory.getFlyweight("2515");
        System.out.println(fw2.toString());
        fw.operate();
    }
}

//抽象享元类
abstract class Flyweight{
    //内部状态
    private String intrinsic;
    //外部状态
    protected final String Extrinsic;
    //享元角色必须接受外部状态
    protected Flyweight(String Extrinsic) {
        this.Extrinsic = Extrinsic;
    }
    //业务操作
    public abstract void operate();
    //内部状态的getter/setter
    public String getIntrinsic(){
        return intrinsic;
    }
    public void setIntrinsic(String intrinsic){
        this.intrinsic = intrinsic;
    }
}

//具体享元类
class ConcreteFlyweight extends Flyweight{
    //接受外部状态
    public ConcreteFlyweight(String extrinsic){
        super(extrinsic);
    }
    @Override
    public void operate() {
        System.out.println("ConcreteFlyweight.operate()");
    }
}

//享元工厂类
class FlyweightFactory{
    //定义一个池容器
    private static HashMap pool = new HashMap();
    //享元工厂
    public static Flyweight getFlyweight(String Extrinsic){
        //需要返回的对象
        Flyweight flyweight = null;
        //在池中查找
        if (pool.containsKey(Extrinsic)){
            //有，直接取出
            flyweight =(Flyweight)pool.get(Extrinsic);
        }else{
            //根据外部状态创建享元对象并放入到池中
            flyweight = new ConcreteFlyweight(Extrinsic);
            pool.put(Extrinsic,flyweight);
        }
        return flyweight;
    }
}


