package 备忘录模式;

public class MementoPattern {
    public static void main(String[] args) {
        //创建一个发起人对象
        Originator originator = new Originator();
        originator.setState("初始状态1");
        System.out.println(originator.getState());
        //创建一个备忘录管理员
        Caretaker caretaker = new Caretaker();
        //创建一个备忘录
        caretaker.setMemento(originator.createMemento());
        originator.setState("修改后的状态2");
        System.out.println(originator.getState());
        //恢复一个备忘录
        originator.restoreMemento(caretaker.getMemento());
        System.out.println("恢复备忘录后：：："+originator.getState());
    }
}

//备忘录
class Memento{
    //发起人的内部状态
    private String state = "";
    //构造函数传递参数
    public Memento(String state){
        this.state =state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }
}

//原发器(发起人角色)
class Originator{
    //内部状态
    private String state = "";
    public String getState(){
        return state;
    }
    public void setState(String state){
        this.state = state;
    }
    //创建一个备忘录
    public Memento createMemento(){
        return new Memento(state);
    }
    //恢复一个备忘录
    public void restoreMemento(Memento memento){
        this.setState(memento.getState());
    }
}

//备忘录管理者
class Caretaker{
    //备忘录对象
    private Memento memento;
    public Memento getMemento(){
        return memento;
    }
    public void setMemento(Memento memento){
        this.memento = memento;
    }
}