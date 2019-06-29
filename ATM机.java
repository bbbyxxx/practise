package pro0629;

import java.util.Scanner;

/*
实现ATM机，ATM可以实现存款,取款,改密,查询和退出操作,登录时如果密码连续错误三次吞卡
初始密码(int)和余额可以写死
 */
public class DemoC {
    private int pass = 123456;
    private int money = (int)(Math.random()*100000+333);
    private Scanner in = new Scanner(System.in);

    public void 输入密码(int num){
        System.out.print("请输入密码:");
        int pass = in.nextInt();
        if(this.pass==pass){
            主界面();
        }else{
            num++;
            if(num==3){
                System.out.println("密码错误次数过多,已锁卡！");
            }else{
                System.out.println("密码输入错误！你还有"+(3-num)+"次机会！");
                输入密码(num);
            }
        }
    }

    public void 主界面(){
        System.out.println("*******************************************");
        System.out.println("***********欢迎访问中国XX银行ATM***************");
        System.out.println("*******************************************");
        System.out.println("请选择您的操作:");
        System.out.println("1.取款");
        System.out.println("2.存款");
        System.out.println("3.查询");
        System.out.println("4.改密");
        System.out.println("5.退出");
        int type = in.nextInt();
        switch (type){
            case 1:
                取款();
                break;
            case 2:
                存款();
                break;
            case 3:
                查询();
                break;
            case 4:
                改密();
                break;
            case 5:
                退出();
                break;
        }
    }

    public void 取款(){
        System.out.print("请输入取款金额:");
        int money = in.nextInt();
        if(money%100!=0){
            System.out.println("ATM机只支持100元面值的钞票");
            取款();
        }else if(money>this.money){
            System.out.println("余额不足！");
            取款();
        }else if(money>5000){
            System.out.println("单次取款金额不能超过5000元");
            取款();
        }else if(money<0){
            System.out.println("输入不正确！");
            取款();
        }else{
            this.money-=money;
            System.out.println("您本次成功取出:"+money+"元！");
            主界面();
        }
    }

    public void 存款(){
        System.out.print("请输入存款金额:");
        int money = in.nextInt();
        if(money%100!=0){
            System.out.println("ATM机只支持100元面值的钞票");
            存款();
        }else{
            this.money+=money;
            System.out.println("您本次成功存入:"+money+"元！");
            主界面();
        }
    }

    public void 查询(){
        System.out.println("您的余额为:"+money+"元");
        主界面();
    }

    public void 改密(){
        System.out.print("请输入原始密码:");
        int pass = in.nextInt();
        if(this.pass==pass){
            System.out.print("请输入新密码:");
            int pass1 = in.nextInt();
            System.out.print("请再次输入新密码:");
            int pass2 = in.nextInt();
            if(pass1==pass2){
                this.pass = pass1;
                System.out.println("改密成功！");
                输入密码(0);
            }else{
                System.out.println("两次输入密码不一致，改密失败！");
                主界面();
            }
        }else{
            System.out.println("原始密码错误！");
            主界面();
        }
    }
    public void 退出(){
        System.out.println("欢迎下次访问！");
    }
    public static void main(String[] args) {
        DemoC dc = new DemoC();
        dc.输入密码(0);
    }
}
