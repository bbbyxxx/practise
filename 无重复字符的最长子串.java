package practice;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
 */
public class 无重复字符的最长子串 {
    public static int lengthOfLongestSubstring(String s) {
       /* if (s.length()==0||s==null){
            return 0;
        }
        int cnt = 1;
        int max = 1;
        for (int i = 0; i < s.length()-1; i++) {
            for (int j = i+1; j < s.length(); j++) {
                if (s.charAt(j)==s.charAt(i)){
                    break;
                }else{
                    int k = i;
                    for (; k < j; k++) {
                        if (s.charAt(k)==s.charAt(j)){
                            break;
                        }
                    }
                    if (k==j) {
                        cnt++;
                    }else{
                        break;
                    }
                }
            }
            if (cnt>max){
                max = cnt;
            }
            cnt = 1;
        }
        return max;*/

       /*
       boolean[] letter = new boolean[128];
        int start = 0, end = 0, ans = 0;
        while (end < s.length()) {
            if (!letter[s.charAt(end)]) {
                letter[s.charAt(end)] = true;
                end++;
                ans = Math.max(ans, end - start);
            } else {
                letter[s.charAt(start)] = false;
                start++;
            }
        }
        return ans;
        */

       /*
       标签：滑动窗口
定义一个 map 数据结构存储 (k, v)，其中 key 值为字符，value 值为字符位置 +1，加 1 表示从字符位置后一个才开始不重复
我们定义不重复子串的开始位置为 start，结束位置为 end
随着 end 不断遍历向后，会遇到与 [start, end] 区间内字符相同的情况，此时将字符作为 key 值，
获取其 value 值，并更新 start，此时 [start, end] 区间内不存在重复字符
无论是否更新 start，都会更新其 map 数据结构和结果 ans。
时间复杂度：O(n)O(n)
        */

        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int end = 0, start = 0; end < n; end++) {
            char alpha = s.charAt(end);
            if (map.containsKey(alpha)) {
                start = Math.max(map.get(alpha), start);
            }
            ans = Math.max(ans, end - start + 1);
            map.put(s.charAt(end), end + 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        System.out.print("请输入字符串：");
        String s = in.next();
        System.out.println(lengthOfLongestSubstring(s));
    }
}
