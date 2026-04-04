class KthLargest {
public:
    int k=0;
    priority_queue<int, vector<int>, greater<int>> minheap;
    KthLargest(int kth, vector<int>& nums) {
        k = kth;
        for(int i=0;i<nums.size();i++){
            if(k > 0){
                k--;
                minheap.push(nums[i]);
            }
            else{
                if(minheap.top()<nums[i]){
                    minheap.pop();
                    minheap.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(k > 0){
            k--;
            minheap.push(val);
        }
        else{
            if(minheap.top()<val){
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};
