class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0) return grid;
        vector<int> flattend;
        size_t total=0;
        for(const auto& row:grid) {
            total+=row.size();
        }
        flattend.reserve(total);
        for(const auto& row:grid) {
            flattend.insert(flattend.end(),row.begin(),row.end());
        }
        int size=flattend.size();
        k=k%size;
        int m=size-k;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                m=m%size;
                grid[i][j]=flattend[m];
                m++;
            }
        }
        return grid;
    }
};