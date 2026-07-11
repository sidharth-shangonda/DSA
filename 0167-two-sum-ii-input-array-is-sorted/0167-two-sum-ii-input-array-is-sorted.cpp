class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0,csum;
        int end=numbers.size() -1;
        vector <int > vec;

    while (start<end) {
        csum=numbers[start]+numbers[end];
        if (csum==target) {
            start++;
            end++;
            vec={start,end};
            return vec;
        } else if(csum>target ) {
            end--;
        } else{
            start++;
        }
    }
     return vec;
    }
};