#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//better approach for rotate matrix 90.
//step 1: transpose the matrix (interchange row and column)
//step 2: reverse
void rotate90(vector<vector<int>>& matrix, int& n) {
    //transposing 
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
              swap(matrix[i][j], matrix[j][i]);
            }
        }
      for (int k = 0; k < n; k++) {
           reverse(matrix[k].begin(), matrix[k].end());
          }
    }


int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = matrix.size();
    rotate90(matrix, n);
    
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
    }