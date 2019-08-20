package practice;

import java.util.Arrays;
import java.util.Scanner;

/*
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释：
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
所有字符串中都仅包含小写英文字母

来源：力扣（LeetCode）
 */
public class 拼写单词 {
    /*public static int countCharacters(String[] words, String chars) {
        int cnt = 0;
        int[] nums = new int[26];//看单词表都有哪些单词
        for (int i = 0; i < chars.length(); i++) {//计算单词表中元素及其个数
            nums[chars.charAt(i)-'a']++;
        }
        for (int i = 0; i < words.length; i++) {//找出每个字符串
            String s = words[i];
            int[] ex = new int[26];//判断是否能背出此单词
            for (int j = 0; j < s.length(); j++) {//判断每个字符串各个字母的个数
                ex[s.charAt(j)-'a']++;
            }
            //判断此单词是否能背出
            boolean xx = judgeExAndNums(nums,ex,s);
            if (xx){//能背出
                cnt += s.length();
                System.out.println(s);
            }
        }
        return cnt;
    }

    public static boolean judgeExAndNums(int[] nums,int[] ex,String s){
        int j = 0;
            for (; j < 26; j++) {
                if (ex[j]!=0&&(ex[j]>nums[j]||nums[j]==0)){
                    break;
                }
            }
            if (j == 26){
                return true;
            }else{
                return false;
            }
    }*/

    public  static int countCharacters(String[] words, String chars) {
        int[] count = getCount(chars);
        int res = 0;
        for (int i = 0; i < words.length; i++) {
            boolean flag = true;
            int[] temp = getCount(words[i]);
            for (int j = 0; j < 26; j++) {
                if (temp[j] > count[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res += words[i].length();
        }
        return res;
    }

    private static int[] getCount(String word) {
        int[] count = new int[26];
        char[] s = word.toCharArray();
        for (char c : s)
            count[c-'a']++;
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组长度:");
        int n = in.nextInt();
        System.out.print("请输入数组元素：");
        String[] nums = new String[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.next();
        }
        System.out.print("请输入单词表：");
        String s = in.next();
        System.out.println(countCharacters(nums,s));
    }
}
