package practice;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。

例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。

我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。

最终结果按照字典顺序输出。

示例 1:

输入: "abbxxxxzzy"
输出: [[3,6]]
解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。
示例 2:

输入: "abc"
输出: []
解释: "a","b" 和 "c" 均不是符合要求的较大分组。
示例 3:

输入: "abcdddeeeeaabbbcd"
输出: [[3,5],[6,9],[12,14]]
说明:  1 <= S.length <= 1000

来源：力扣（LeetCode）
 */
public class 较大分组的位置 {
    public static List<List<Integer>> largeGroupPositions(String S) {
        /*List<List<Integer>> list = new ArrayList<>();
        int count = 0;
        int t = 0,k = 0;
        for (int i = 0; i < S.length(); i += count ) {
            count = 0;
            for (int j = i; j < S.length(); j++) {
                if (i == j) {
                    t = i;
                }
                if (S.charAt(i) == S.charAt(j)) {
                    count++;
                    k = j ;
                } else {
                    break;
                }
            }
            if (count>=3){
                List<Integer> a = new ArrayList<>();
                a.add(t);
                a.add(k);
                list.add(a);
            }
        }
        return list;*/

       /* List<List<Integer>> list = new ArrayList<>();
        if(S.length() <3) return list;
        for(int i = 0;i<S.length();){
            int j = i;
            while(j<S.length() && S.charAt(j) == S.charAt(i))
                j++;
            if(j-i>=3){
                List<Integer> temp = new ArrayList<Integer>();
                temp.add(i);
                temp.add(j - 1);
                list.add(temp);
            }
            i=j;
        }
        return list;*/

        List<List<Integer>> res = new ArrayList<>();
        if(S == null || S.isEmpty() || S.length() == 0){
            return res;
        }
        char cur = S.charAt(0);
        int left = 0;
        S = S + " "; // to ensure last char is different than all other chars and enter the if statement
        for(int i = 1; i < S.length(); i++){
            if(cur != S.charAt(i)){
                if(i - left >= 3){
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(left);
                    tmp.add(i - 1);
                    res.add(tmp);
                }
                cur = S.charAt(i);
                left = i;
            }

        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入字符串：");
        String s = in.next();
        List<List<Integer>> list = largeGroupPositions(s);
        System.out.println(list);
    }
}
