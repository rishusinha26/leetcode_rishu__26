class Solution {
public:
    bool cansplit(vector<int>&nums,int k,int sum){
        int subarray=1;
        int last_place=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]+last_place<=sum){
                last_place+=nums[i];
            }
            else{
                subarray++;
                last_place=nums[i];
            }
        }
        return subarray<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(cansplit(nums,k,mid)){
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