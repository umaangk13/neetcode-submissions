class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currFuel=0;
        int totalNet=0;
        int idx=0;
        for(int i=0;i<gas.size();i++){
            if(currFuel + gas[i] - cost[i] < 0){
                idx = i+1;
                currFuel = 0;
            }
            else{
                currFuel += gas[i] - cost[i];
            }
            totalNet += gas[i] - cost[i];
        }

        return totalNet<0?-1:idx;
    }
};
