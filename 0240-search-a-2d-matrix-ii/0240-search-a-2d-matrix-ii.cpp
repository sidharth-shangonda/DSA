class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++) {
            if(matrix[i][n-1]>=target) {
                int rows=lower_bound(matrix[i].begin()+i,matrix[i].end(),target)-matrix[i].begin();
                if(rows<n && matrix[i][rows]==target) return true;
            }
            if(i<n && matrix[m-1][i]>=target) {
                int low=i;
                int high=m-1;
                while(low<=high) {
                    int mid=low+(high-low)/2;
                    if(matrix[mid][i]==target) return true;
                    else if(matrix[mid][i]>target) {
                        high=mid-1;
                    } else {
                        low=mid+1;
                    }
                }
            }
        }
        return false;
    }
};