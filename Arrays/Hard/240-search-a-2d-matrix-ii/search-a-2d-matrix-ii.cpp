class Solution {
public:
/* we will start with top right corner, if that cell is equals to target, return true.
else if cell< target, we move downward.
else if cell > target, means uske niche target nhi milega as array is sorted row wise and col wise both.
so we slide to the prev row i.e., left.
 we will do the same untill we didn't get our target.
 
 if we did'nt get the target then eventually loop will break and then return false */ 

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // num of rows
        int m = matrix[0].size(); // num of cols
        int i = 0, j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};