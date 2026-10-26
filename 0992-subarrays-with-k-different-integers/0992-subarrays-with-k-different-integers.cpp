class Solution {
public:
    int cntsubarray(vector<int>&nums,int k){
        int n=nums.size(),l=0,r=0,cnt=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return cntsubarray(nums,k)-cntsubarray(nums,k-1);
    }
};