package 单例模式;
//单例模式可以延迟实例化
//懒汉式，线程不安全
/*public class Singleton {
    private static Singleton uniqueInstance;
    private Singleton(){
        System.out.println("This is SingleTonn");
    }
    public static Singleton getInstance(){
        if (uniqueInstance==null){
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
    }
}*/

/*处理多线程：通过增加Synchronized关键字到getInstance（）方法中，这样迫使每个线程在进入这个方法前
要先等待别的线程离开该方法。也就是说不会有两个线程可以同时进入这个方法。 但是，同步会降低性能。
 */


import com.sun.org.apache.xerces.internal.parsers.CachingParserPool;

//如果将getInstance（）的程序使用在频繁运行的地方，就不能使用加锁或者延迟创建对象的方式。
//懒汉式，线程安全
/*public class Singleton{
    private static Singleton uniqueInstance = null;
    private Singleton(){}
    public static synchronized Singleton getInstance(){
        if (uniqueInstance==null){
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
    }*/


//饿汉式，线程安全
/*public class Singleton{
    private static Singleton uniqueInstance = new Singleton();//保证了线程安全
    private Singleton(){}
    public static Singleton getInstance(){
        return uniqueInstance;
    }
}*/

//第二种方案是：用“双重检查加锁”，在getInstance（）中减少使用同步
//首先检查是否实例已经创建了，如果还没创建，才进行同步。这样就保证了，只有第一次会同步。

/*public class Singleton{
    //volatile关键字确保：当uniqueInstance变量被初始化成Singleton实例时，多个线程正确地处理uniqueInstance变量
    private volatile static Singleton uniqueInstance;
    private Singleton(){}
    public static Singleton getInstance(){
        if (uniqueInstance == null){//只有第一次才彻底执行这里的代码
            synchronized (Singleton.class){
                if (uniqueInstance == null){//进入区块后，再检查一次。如果仍是null，才创建实例
                    uniqueInstance = new Singleton();
                }
            }
        }
        return uniqueInstance;
    }
}*/

//注意：你如果使用多个类加载器，可能会导致单件（例/身）模式失效而产生多个实例

//静态（类级）内部类
//类级内部类，也就是静态的成员式内部类，该内部类的实例与外部类的实例
// 没有绑定关系，而且只有被调用到时才会装载，从而实现了延迟加载
public class Singleton{
    private Singleton(){}
    private static class SingletonXxx{
        //静态初始化器，由JVM来保证线程安全
        private static Singleton singleton = new Singleton();
    }
    public static Singleton getInstance(){
        return SingletonXxx.singleton;
    }
}