package practict2;

import java.util.Scanner;

/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false

来源：力扣（LeetCode）
 */
public class 正则表达式匹配 {
    //return s.matches(p);//告知此字符串是否匹配给定的 正则表达式。

   /*public boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) return text.isEmpty();
//判断 text 是否为空，防止越界，如果 text 为空， 表达式直接判为 false, text.charAt(0)就不会执行了
        boolean first_match = (!text.isEmpty() &&
                (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));
        //只有长度大于 2 的时候，才考虑 *
        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            //两种情况
            //pattern 直接跳过两个字符。表示 * 前边的字符出现 0 次
            //pattern 不变，例如 text = aa ，pattern = a*，第一个 a 匹配，然后 text 的第二个 a 接着和 pattern 的第一个 a 进行匹配。表示 * 用前一个字符替代。
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }*/

   //自顶向下
    public static boolean isMatch(String s,String p){
        boolean[][] dp = new boolean[s.length()+1][p.length()+1];
        dp[0][0] = true;
        for (int i = 1; i <=p.length() ; i++) {
            if (p.charAt(i-1)=='*'&&dp[0][i-2]){
                dp[0][i] = true;
            }
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j < p.length(); j++) {
                if (s.charAt(i-1) == p.charAt(j-1)||p.charAt(j-1)=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if (p.charAt(j-1)=='*'){
                    if (p.charAt(j-2)!=s.charAt(i-1)&&p.charAt(j-2)!='.'){
                        dp[i][j] = dp[i][j-2];
                    }else{
                        dp[i][j] = (dp[i][j-2]||dp[i][j-1]||dp[i-1][j]);
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }


   /*自底向上
public static boolean isMatch(String text, String pattern) {
        // 多一维的空间，因为求 dp[len - 1][j] 的时候需要知道 dp[len][j] 的情况，
        // 多一维的话，就可以把 对 dp[len - 1][j] 也写进循环了
        boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
        // dp[len][len] 代表两个空串是否匹配了，"" 和 "" ，当然是 true 了。
        dp[text.length()][pattern.length()] = true;

        // 从 len 开始减少
        for (int i = text.length(); i >= 0; i--) {
        for (int j = pattern.length(); j >= 0; j--) {
        // dp[text.length()][pattern.length()] 已经进行了初始化
        if(i==text.length()&&j==pattern.length()) continue;

        boolean first_match = (i < text.length() && j < pattern.length()
        && (pattern.charAt(j) == text.charAt(i) || pattern.charAt(j) == '.'));
        if (j + 1 < pattern.length() && pattern.charAt(j + 1) == '*') {
        dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
        } else {
        dp[i][j] = first_match && dp[i + 1][j + 1];
        }
        }
        }
        return dp[0][0];
        }*/


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("输入字符串1：");
        String s1 = in.next();
        System.out.println("输入字符串2：");
        String s2 = in.next();
        System.out.println(isMatch(s1,s2));
    }
}
