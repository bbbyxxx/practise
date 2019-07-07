import java.util.Scanner;

public class HuiWenShu {
    private static Scanner in = new Scanner(System.in);
    public static void main(String[] args){
        String s = new String();
        s = in.next();//键盘输入要判断的字符串
        if(JudegeHuiWen(s)){
            System.out.println("是一个回文字符串");
        }
        else{
            System.out.println("不是一个回文字符串");
        }
    }
    public static boolean JudegeHuiWen(String s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if (s.charAt(i)!=s.charAt(j)){
                break;
            }
            i++;
            j--;
        }
        if(i>=j){
            return true;
        }
        else{
            return false;
        }
    }
}
