class Solution {
public:
    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        vector<int> result(n,n);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first > heights[i]){
                result[st.top().second] = i;
                st.pop();
            }
            st.push({heights[i],i});
        }
        return result;
    }
    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        vector<int> result(n,-1);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first > heights[i]){
                result[st.top().second] = i;
                st.pop();
            }
            st.push({heights[i],i});
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nSe = nse(heights);
        vector<int> pSe = pse(heights);
        
        int maxArea=0;
        for(int i=0;i<n;i++){
            int leftLimit = pSe[i];
            int rightLimit = nSe[i];
            maxArea = max(maxArea, heights[i] * (rightLimit - leftLimit - 1));
        }

        return maxArea;
    }
};
