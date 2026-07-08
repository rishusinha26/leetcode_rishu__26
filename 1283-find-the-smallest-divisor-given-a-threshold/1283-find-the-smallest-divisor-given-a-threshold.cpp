class Solution {
public:
    bool candivisor(vector<int>& nums, int threshold,int divisor){
        int sum=0;
        for(auto num:nums){
            sum+=(num+divisor-1)/(divisor);

            if(sum>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(candivisor(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};