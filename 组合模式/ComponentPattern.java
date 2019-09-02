package 组合模式;

import java.util.ArrayList;

public class ComponentPattern {
    public static void main(String[] args) {
        Component leaf = new Leaf();
        leaf.add(leaf);
        leaf.operation();

        Component composite = new Composite();
        composite.add(leaf);
        composite.operation();
    }
}

interface Component{
    void add(Component c);
    void remove(Component c);
    Component getChild(int i);
    void operation();//业务方法
}
class Leaf implements Component{
    public void add(Component c) {
        // 异常处理或错误提示
        System.out.println("ERROR:叶子节点不存在此操作");
    }

    public void remove(Component c) {
        // 异常处理或错误提示
        System.out.println("ERROR:叶子节点不存在此操作");
    }

    public Component getChild(int i) {
        // 异常处理或错误提示
        System.out.println("ERROR:叶子节点不存在此操作");
        return null;
    }

    public void operation() {
        System.out.println("Leaf.operation()");
    }
}

class Composite implements Component{
    private ArrayList<Component> list = new ArrayList<Component>();

    public void add(Component c) {
        list.add(c);
    }

    public void remove(Component c) {
        list.remove(c);
    }

    public Component getChild(int i) {
        return (Component) list.get(i);
    }

    public void operation() {
        // 容器构件具体业务方法的实现
        // 递归调用成员构件的业务方法
        for (Object obj : list) {
            ((Component) obj).operation();
        }
    }
    /*
    实现具体业务方法时，由于容器构件充当的是容器角色，包含成员构件，
    因此它将调用其成员构件的业务方法。在组合模式结构中，
    由于容器构件中仍然可以包含容器构件，因此在对容器构件进行处理时需要使用递归算法
     */
}
/*
优点:
使用方便。客户端可以一致地使用一个组合结构或其中单个对象，不必关心处理的是单个对象还是整个组合结构。
符合“开闭原则”。在组合模式中新增叶子构件和容器构件都很方便。
*/