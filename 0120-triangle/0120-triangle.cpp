class Solution {
public:
    // you can thik of two solutions 1st fisnd min of each row but the soln wont work because read the question properly you can only move to adjecent rows
    // you can apply dp its the best approach
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        //1 node can have atmost 

        //implement correct ly as you thought no mistakes 
        for(int i=1;i<n;i++) {
            int m=triangle[i].size();
            int j=0;
            triangle[i][j]=triangle[i][j]+triangle[i-1][j];
            for(j=1;j<m-1;j++) {
                triangle[i][j]=min(triangle[i][j]+triangle[i-1][j],triangle[i][j]+triangle[i-1][j-1]);
            }
            triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
        }
        //dont retrurn back return the smallest in all of them 
        // return triangle[n-1].back();
        int minVal=INT_MAX;
        for(int i:triangle[n-1]) {
            minVal=min(minVal,i);
        }
        return minVal;
    }
};