class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        bool check=false;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(nums[i]!=i) check=true;
        }
        if(!check) return 0;
        for(int i =0;i<n;i++){
            if(!flag&&nums[i]!=i){
                flag=true;
                ans=nums[i];
            }
            if(nums[i]!=i) ans&=nums[i];
        }
        return ans;
    }
};