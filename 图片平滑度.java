package practice;

import java.util.Scanner;

public class 图片平滑度 {
        private static int row = 0;
        private static int col = 0;

        public static int[][] imageSmoother ( int[][] M){
            if (M == null || M.length < 1 || M[0] == null || M[0].length < 1) {
                return null;
            }

            row = M.length;
            col = M[0].length;

            int ans[][] = new int[row][col];

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    ans[i][j] = calcul(M, i, j);
                }
            }

            return ans;
        }

        // 上、下、左、右，上左，上右，下左，下右
        static int dirR[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static int dirC[] = {0, 0, -1, 1, -1, 1, -1, 1};

        private static int calcul ( int arr[][], int i, int j){
             int count = 1;
             int sum = arr[i][j];

            for (int k = 0; k < dirR.length; k++) {
                int nextR = i + dirR[k];
                int nextC = j + dirC[k];

                if (nextR >= 0 && nextR < row && nextC >= 0 && nextC < col) {
                    count++;
                    sum += arr[nextR][nextC];
                }
            }
            return sum / count;
        }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入二维数组行数和列数：");
        int row = in.nextInt();
        int col = in.nextInt();
        System.out.print("请输入二维数组元素：");
        int[][] nums = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                nums[i][j] = in.nextInt();
            }
        }
        nums = imageSmoother(nums);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(nums[i][j]);
            }
            System.out.println();
        }
    }
}
