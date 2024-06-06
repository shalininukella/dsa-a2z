// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> result;
//         vector<int> prevRow;
        
//         for (int i = 0; i < numRows; i++) {
//             vector<int> currentRow(i + 1, 1);
            
//             for (int j = 1; j < i; j++) {
//                 currentRow[j] = prevRow[j - 1] + prevRow[j];
//             }
            
//             result.push_back(currentRow);
//             prevRow = currentRow;
//         }
        
//         return result;
//     }
// };

class Solution {
public:
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> generate(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}
};