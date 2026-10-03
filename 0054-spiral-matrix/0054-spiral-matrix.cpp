class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;//row
        int j=n-1;//column
        int k=m-1;//row
        int l=0;//coumn
        vector<int> ans;
        while(i<=k && l<=j) {
            for(int x=l;x<=j;x++) {
                ans.push_back(matrix[i][x]);
            }
            for(int x=i+1;x<=k;x++) {
                ans.push_back(matrix[x][j]);
            }
            for(int x=j-1;x>=l && k!=i;x--) {
                ans.push_back(matrix[k][x]);
            }
            for(int x=k-1;x>i && l!=j;x--) {
                ans.push_back(matrix[x][l]);
            }
            i++;
            j--;
            k--;
            l++;
        }
        return ans;
    }
};