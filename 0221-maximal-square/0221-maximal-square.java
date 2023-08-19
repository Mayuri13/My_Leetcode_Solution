class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length, n = matrix[0].length, min = Math.min(m, n);
        int minSize = 1;
        while (minSize <= min) {
            boolean squareFound = false;
            outerloop:
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (r + minSize > m || c + minSize > n) break;
                    int curR = Math.min(r + minSize, m), curC = Math.min(c + minSize, n);
                    boolean squareExistsTemp = true;
                    insideloop:
                    for (int i = r; i < curR; i++) {
                        for (int j = c; j < curC; j++) {
                            if (matrix[i][j] == '0') {
                                squareExistsTemp = false;
                                break insideloop;
                            }
                        }
                    }
                    if (squareExistsTemp) {
                        squareFound = true;
                        minSize++;
                        break outerloop;
                    }
                }
            }
            if (!squareFound) break;
        }
        minSize--;
        return minSize * minSize;
    }
}