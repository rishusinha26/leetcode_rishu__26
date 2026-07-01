class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int jump=0;
        int fartest=0;
        while(r<n-1){
            for(int index=l;index<=r;index++){
                fartest=max(fartest,nums[index]+index);
            }
            l=r+1;
            r=fartest;
            jump++;
        }
        return jump;
    }
};