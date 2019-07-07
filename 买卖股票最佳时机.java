package practice;

public class 买卖股票最佳时机 {
    public static int maxProfit(int[] prices) {
     /*   int i,j,t;
	int cnt=0;
	for(i=0;i<prices.length-1;i++){
        for(j=i+1;j<prices.length;j++){
            t=prices[j]-prices[i];
            if(t>cnt){
                cnt=t;
            }
        }
	}
	return cnt;*/
        if(prices == null || prices.length == 0) return 0;
        int min = Integer.MAX_VALUE;
        int maxProfit = 0;
        for(int i = 0; i < prices.length; i++){
            if(prices[i] <= min){
                min = prices[i];
            }else if(prices[i] - min > maxProfit){
                maxProfit = prices[i] - min;
            }
        }
        return maxProfit;
    }
    public static void main(String[] args) {
        System.out.println(maxProfit(ArrayScanfAndPrintf.way()));
    }
}
