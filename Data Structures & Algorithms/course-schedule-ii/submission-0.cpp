class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<int> inDeg(numCourses,0);
        unordered_map<int,vector<int>> mp;
        for(auto it : prerequisites){
            mp[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDeg[i] == 0){
                result.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front(); q.pop();
            for(int num : mp[curr]){
                inDeg[num]--;
                if(inDeg[num] == 0){
                    result.push_back(num);
                    q.push(num);
                }
            }
        }
        vector<int> empty;
        return result.size()==numCourses?result:empty;
    }
};
