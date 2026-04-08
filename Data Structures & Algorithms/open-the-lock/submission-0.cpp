class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> visited(10000,0);
        for(string s : deadends){
            visited[stoi(s)]=1;
        }
        if(visited[0000] == 1) return -1;
        visited[0000] = 1;

        queue<string> q;
        q.push("0000");
        int level=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front(); q.pop();
                if(curr == target) return level;

                for(int i = 0; i < 4; i++){
                    char temp = curr[i];
                    
                    // 1. Turn the wheel UP
                    curr[i] = (temp - '0' + 1) % 10 + '0';
                    if(visited[stoi(curr)] != 1){
                        visited[stoi(curr)] = 1;
                        q.push(curr);
                    }
                    
                    // Reset to original state
                    curr[i] = temp;
                    
                    // 2. Turn the wheel DOWN (adding 9 % 10 is the same as -1 % 10)
                    curr[i] = (temp - '0' + 9) % 10 + '0';
                    if(visited[stoi(curr)] != 1){
                        visited[stoi(curr)] = 1;
                        q.push(curr);
                    }
                    
                    // Reset for the next character iteration
                    curr[i] = temp;
                }
            }
            level++;
        }

        return -1;
    }
};