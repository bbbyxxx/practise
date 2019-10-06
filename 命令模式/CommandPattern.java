package 命令模式;

public class CommandPattern {
    public static void main(String[] args) {
        Receiver receiver = new Receiver();
        ConcreteCommand concreteCommand = new ConcreteCommand(receiver);
        Invoker invoker = new Invoker(concreteCommand);
        invoker.call();
    }
}

//接收者类（就是干活的）
class Receiver{
    public void action(){
        //处理请求，实现具体的业务操作
        System.out.println("Recetver.action()");
    }
}

//抽象命令类
abstract class Command{
    public abstract void execute();
}

//具体命令类
class ConcreteCommand extends Command{
    private Receiver receiver;//维护一个请求接收者对象的引用
    public ConcreteCommand(Receiver receiver){
        this.receiver = receiver;
    }
    @Override
    public void execute() {
        receiver.action();//调用请求接收者类的业务处理方法
    }
}

//调用者类
class Invoker{
    private Command command;
    public Invoker(Command command){
        this.command = command;
    }

    public void setCommand(Command command){
        this.command = command;
    }

    //业务方法，用于调用命令类的execute（）方法
    public void call(){
        command.execute();
    }
}


