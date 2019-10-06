package 解释器模式;

import java.util.ArrayList;
import java.util.List;

public class InterpreterPattern {
    public static void main(String[] args) {
        String inputExpr = "10";
        Context context = new Context(inputExpr);
        List list = new ArrayList();

        list.add(new PlusExpression());
        list.add(new PlusExpression());
        list.add(new MinusExpression());
        list.add(new MinusExpression());
        list.add(new MinusExpression());

        for (int i=0;i<list.size();i++) {
            AbstractExpression expression = (AbstractExpression)list.get(i);
            expression.interpret(context);
        }

        System.out.println(context.getOutput());
    }
}
//上下文类
class Context {
    private String input;
    private int output;

    public Context (String input) {
        this. input = input;
    }

    public String getInput() {
        return input;
    }

    public void setInput(String input) {
        this.input = input;
    }

    public int getOutput() {
        return output;
    }

    public void setOutput(int output) {
        this.output = output;
    }
}

//抽象表达式类
abstract class AbstractExpression {
    public abstract void interpret(Context context);
}
//非终结符表达式类
class PlusExpression extends AbstractExpression {
    public void interpret(Context context) {
        System.out.println("PlusExpression ++");
        String input = context.getInput();//得到终结符
        int parsedResult = Integer.parseInt(input);//将其进行类型转换
        parsedResult ++;//加一
        context.setInput(String.valueOf(parsedResult));//设置上下文信息
        context.setOutput(parsedResult);
    }
}
//非终结符表达式类
class MinusExpression extends AbstractExpression {
    public void interpret(Context context) {
        System.out.println("PlusExpression --");
        String input = context.getInput();
        int parsedResult = Integer.parseInt(input);
        parsedResult --;
        context.setInput(String.valueOf(parsedResult));
        context.setOutput(parsedResult);
    }
}