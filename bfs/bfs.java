package bfs;

import java.util.*;

public class bfs {
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

    public static Map<String,String> BFS(Map<String,String[]> map,String s){
        Queue<String> queue = new LinkedList<>();//队列保存要访问的节点
        queue.offer(s);//添加要访问的节点
        HashSet<String> set = new HashSet<>();//set集合用于判断此元素是否已经被使用过了
        set.add(s);//每次添加要访问的结点
        Map<String,String> parent = new HashMap<>();//map集合映射路径顺序
        parent.put(s,null);
        while(queue.size()>0){//当队列中还有节点
            String vertex = queue.poll();//取出节点
            String[] nodes = map.get(vertex);//取出当前节点对应的所有邻接节点
            for (String w:nodes) {//遍历所有邻接点
                if (!set.contains(w)){//没有被使用过
                    queue.offer(w);//添加到队列中
                    set.add(w);//将此节点添加到判断集合set中
                    parent.put(w,vertex);//将节点添加到映射路径中去,如果仅仅是输出，可以用其他集合来代替
                }
            }
            System.out.print(vertex+"  ");
        }
        System.out.println();

        String s2 = "E";
        while(s2!=null){
            System.out.print(s2+" ");
            s2 = parent.get(s2);
        }

        System.out.println();
        return parent;
    }

    public static void main(String[] args) {
        Map<String,String> map = BFS(graph(),"A");
        System.out.println(map);
    }
}
