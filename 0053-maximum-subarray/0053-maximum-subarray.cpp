class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        for(auto ele:nums)
        {
            sum=sum+ele;
            ans=max(ans,sum);
            if(sum<0)
            sum=0;
        }
        return ans;
        
    }
};