class Solution {
public:
    int search(vector<int>& arr,int target) {
        int low=0;
        int high=arr.size()-1;//use size-1
        int ans=-1;
        while(low<=high) {
            int mid=low + (high - low) / 2;
            if(arr[mid]<=target) {
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        } 
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int idx=search(arr,x);
        int i=idx;
        int j=idx+1;
        while(k>0 && i>=0 && j<n) {
            long long d1 = abs((long long)arr[i] - x);//make sure of overflow
            long long d2 = abs((long long)arr[j] - x);
            if(d1 > d2) j++;
            else i--;
            k--;
        }
        while(k>0 && i>=0) {
            i--;
            k--;
        }
        while(k>0 && j<n) {
            j++;
            k--;
        }
        vector <int> ans;
        for(int m=i+1;m<j;m++) {
            ans.push_back(arr[m]);
        }
        return ans;
    }
};