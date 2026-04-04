class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> maxHeap;
        queue<pair<int,char>> q;

        vector<int> freq(26,0);
        for(char c : tasks){
            freq[c-'A']++;
        }

        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                maxHeap.push({freq[i],'A' + i});
            }
        }

        int time=1;
        while(!maxHeap.empty() || !q.empty()){
            if(maxHeap.empty()){
                auto [t,c] = q.front();
                time = t;
            }

            if(!q.empty() && q.front().first == time){
                auto [t,c] = q.front(); q.pop();
                maxHeap.push({freq[c-'A'],c});
            }

            auto [f,c] = maxHeap.top(); maxHeap.pop();
            freq[c-'A'] = f-1;
            if(f-1 > 0){
                int coolDown = time + n + 1;
                q.push({coolDown,c});
            }

            time++;
        }

        return time-1;
    }
};
