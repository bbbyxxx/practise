package bfs;

import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.util.*;

public class again {
    public static Map<String,String[]> graph(){//构建地图
        Map<String,String[]> map = new HashMap<>();
        String[] A = {"B","C"};
        String[] B = {"A","C","D"};
        String[] C = {"A","B","D","E"};
        String[] D = {"B","C","E","F"};
        String[] E = {"C","D"};
        String[] F = {"D"};
        map.put("A",A);
        map.put("B",B);
        map.put("C",C);
        map.put("D",D);
        map.put("E",E);
        map.put("F",F);
        return map;
    }

    public static List<String> bfs(Map<String,String[]> map,String s){
        Queue<String> queue = new LinkedList();
        queue.offer(s);
        Set<String> set = new HashSet<>();
        set.add(s);
        List<String> list = new ArrayList<>();
        list.add(s);

        while(queue.size()>0){
            String s1 = queue.poll();
            String[] nodes = map.get(s1);
            for (String s2:nodes) {
                if (!set.contains(s2)) {
                    queue.offer(s2);
                    set.add(s2);
                    list.add(s2);
                }
            }
        }
        return list;
    }
    public static void main(String[] args) {
       List list = bfs(graph(),"B");
        System.out.println(list);
    }
}
