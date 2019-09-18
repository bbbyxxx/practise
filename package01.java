package 背包;

import java.util.*;

public class package01 {
    private static int packageCapacity;//给定的背包容量
    private static int n;//商品个数
    private static int[][] dp;//每一容量对应的最大价值
    private static Map<Integer,Integer> map;//商品重量及其所对应的价值
    public static void  gift(){//构建商品列表
        Scanner in = new Scanner(System.in);
        System.out.print("请输入商品个数：");
        n = in.nextInt();
        System.out.print("请输入背包的最大容量：");
        packageCapacity = in.nextInt();
        dp = new int[n+1][packageCapacity+1];//行数和列数各加一是因为当容量或者价格等于0时，肯定只有一个结果0
        map = new TreeMap<>();//需要排序，先将商品按重量排序
        System.out.println("请输入每个商品重量及价值：");
        map.put(0,0);
        for (int i = 1; i < n+1; i++) {
            int height = in.nextInt();
            int values = in.nextInt();
            map.put(height,values);
        }
    }

    public static void oneAndTwoPackage(){
        Collection collection = map.values();//得到商品价值列表
        Iterator coll = collection.iterator();
        int[] list = new int[collection.size()];
        int k = 0;
        while(coll.hasNext()){
            list[k++] =(int)coll.next();
        }
        System.out.println(Arrays.toString(list));
        Set set = map.keySet();//得到商重量列表
        Iterator se = set.iterator();
        int[] sets = new int[set.size()];
        int m = 0;
        while(se.hasNext()){
            sets[m++] =(int)se.next();
        }
        System.out.println(Arrays.toString(sets));
        for (int i = 1; i < dp.length; i++) {//行
            for (int j = 1; j < dp[i].length; j++) {//列
                if (sets[i]>j){//物品的重量比背包的剩余容量大
                    dp[i][j] = dp[i-1][j];//总价钱就等于1~i-1个商品的能取价值
                }else{//商品质量没有背包剩余容量大，则表示可装入或者选择不装入
                    //选择当前商品，则新的价值为1~i-1之前的价值加上当前商品的价值，
                    // 并且背包剩余容量要减去当前商品容量
                    int value1 = dp[i-1][j-sets[i]] + list[i];
                    int value2 = dp[i-1][j];//不选，则原封不动
                    if (value1>value2){//选出哪种方案效益大
                        dp[i][j] = value1;
                    }else{
                        dp[i][j] = value2;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        gift();//构建商品列表
        oneAndTwoPackage();//求最大装入价值
        System.out.print("最大收入为："+dp[n][packageCapacity]);
        System.out.println();
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                System.out.print(dp[i][j] + "  ");
            }
            System.out.println();
        }

    }
}
