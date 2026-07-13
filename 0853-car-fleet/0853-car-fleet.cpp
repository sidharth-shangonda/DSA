class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue <pair<int , int >> pq;
        stack <double> s;
        for(int i=0;i<speed.size();i++) {
            pq.push(make_pair(position[i],speed[i]));
        }
        while(!pq.empty()) {
            int dist=target-pq.top().first;
            int vel=pq.top().second;
            double time=1.0*dist/vel;
            pq.pop();
            if(s.empty()) {
                s.push(time);
            } else {
                if(time>s.top()) s.push(time);
            }
        }
        return s.size();
    }
};