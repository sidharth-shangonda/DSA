class Solution {
public:
    // just understand how the monotonic stack works 
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;
        int maxArea=0;
        int i;
        for( i=0;i<heights.size();i++) {
            while(!s.empty() && heights[i]<heights[s.top()]) {
                int height=heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width=i; //make sure of the total stack empty condition 
                else width=i-s.top()-1;
                maxArea=max(maxArea,width*height);
            }
            s.push(i);
        }
        while(!s.empty()) {
            int height=heights[s.top()];
            s.pop();
            int width;
            if(s.empty()) width=i; //make sure of the total stack empty condition 
            else width=i-s.top()-1;
            maxArea=max(maxArea,width*height);
        }
        return maxArea;
    }
};