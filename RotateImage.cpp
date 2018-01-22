/*
48. Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Hint:
1. Transpose the matrix
2. Swap colums

For rotating anti-clockwise:
1. Transpose the matrix
2. Swap rows
*/

    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<i;j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
      
        for (int i=0;i<m/2;i++) {
            for (int j=0;j<n;j++) {
                swap(matrix[i][j], matrix[m-1-i][j]);
            }
        }
    }
