class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for(auto s : operations) {
            if(s == "+") {
                // Your exact logic: pop the top two, add them, push all three back
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                
                int t3 = t1 + t2;
                
                st.push(t2);
                st.push(t1);
                st.push(t3);
            } 
            else if(s == "D") {
                // "D" means double the previous score and push it
                st.push(st.top() * 2);
            } 
            else if(s == "C") {
                // "C" means cancel the previous score, so just pop it
                st.pop();
            } 
            else {
                // If it's not +, D, or C, it must be a number. 
                // Convert string to integer using stoi() and push it.
                st.push(stoi(s));
            }
        }
        
        // Finally, add up all the valid scores left in the stack
        int totalSum = 0;
        while(!st.empty()) {
            totalSum += st.top();
            st.pop();
        }
        
        return totalSum;
    }
};