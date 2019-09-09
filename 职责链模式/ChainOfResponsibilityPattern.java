package 职责链模式;

import jdk.internal.org.objectweb.asm.Handle;

/*
Handler：抽象处理者
一般是抽象类。定义了处理请求的接口。
定义了请求处理抽象方法handleRequest()，规范了子类处理请求的操作。
为了将处理者组成一条链，抽象处理者需要返回一个本处理者的下个处理者的引用。
由于处理者的下方还是处理者，因此在抽象处理者中定义了一个抽象处理者类型的对象
（如结构图中的successor），作为下个处理者的引用（可选）。
ConcreteHandler：具体处理者
继承Handler的具体处理者角色。
实现了handleRequest()抽象方法来处理请求。
具体处理者接到请求后，如果可以处理就将请求处理掉；
否则通过对下个处理者的引用将请求转发给下个处理者。
 */
public class ChainOfResponsibilityPattern {
    public static void main(String[] args) {
        //组装职责链
        Handler handler1 = new ConcreteHandler1();
        Handler handler2 = new ConcreteHandler2();
       // handler2.setSuccessor(null);//最后一个节点successor域赋空或者给父节点直接赋
        handler1.setSuccessor(handler2);
        //提交请求
        handler1.handleRequest("adasdas");
        System.out.println("------------------");
        handler1.handleRequest("ac");
    }
}

abstract class Handler{
    protected Handler successor = null;

    public void setSuccessor(Handler successor){
        this.successor = successor;
    }

    public Handler getSuccessor(){
        return successor;
    }
    //传入请求
    public abstract void handleRequest(String judging);
}

class ConcreteHandler1 extends Handler{
    @Override
    public void handleRequest(String judging) {
        if (judging.length()<3){//长度小于3
            System.out.println(this.getClass().getSimpleName()+"处理请求");
        }else{
            System.out.println(this.getClass().getSimpleName()+"转发请求");
            if (this.successor!=null) {
                this.successor.handleRequest(judging);//转发请求
            }
        }
    }
}

class ConcreteHandler2 extends Handler{
    @Override
    public void handleRequest(String judging) {
        if (judging.length()>=3){//不是空
            System.out.println(this.getClass().getSimpleName()+"处理请求");
        }else{
            System.out.println(this.getClass().getSimpleName()+"转发请求");
            if (this.successor!=null) {
                this.successor.handleRequest(judging);//转发请求
            }
        }
    }
}

