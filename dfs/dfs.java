package dfs;

import java.util.*;

public class dfs {
    public static Map<String,String[]> graph(){//构建地图
        Map<String,String[]> map = new HashMap<>();
        String[] A ={"B","C"};
        String[] B ={"A","C","D"};
        String[] C ={"A","B","D","E"};
        String[] D ={"B","C","E","F"};
        String[] E ={"C","D"};
        String[] F ={"D"};
        map.put("A",A);
        map.put("B",B);
        map.put("C",C);
        map.put("D",D);
        map.put("E",E);
        map.put("F",F);
        return map;
    }

    public static List<String> dfs(Map<String,String[]> map,String s){
        Stack<String> stack = new Stack<>();//保存当前或其相邻节点压栈
        stack.add(s);
        HashSet<String> set = new HashSet<>();//判断是否使用过
        set.add(s);
        List<String> list = new ArrayList<>();
        while(!stack.isEmpty()){//栈不空
            String vertix = stack.pop();//栈顶元素出栈
            String[] nodes = map.get(vertix);//取出所有相邻接点
            for (String s1:nodes) {
                if (!set.contains(s1)){//没有使用过
                    stack.push(s1);//压栈
                    set.add(s1);//放入判断集合set
                }
            }
            list.add(vertix);
        }
        return list;
    }

    public static void main(String[] args) {
        List<String> list = dfs(graph(),"F");
        System.out.println(list);
    }
}
