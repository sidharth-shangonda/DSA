class Solution {
public:
    //bhai edge cases mat bhul na 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;//for empty one
        int n=matrix.size();
        int m=matrix[0].size();
        int i;
        for( i=0;i<n;i++) {
            if(target <= matrix[i][m-1]) break;
        }
        if(i==n) return false;
        int low=0;
        int high=m-1;
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(target==matrix[i][mid]) return true;
            else if(target < matrix[i][mid]) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};