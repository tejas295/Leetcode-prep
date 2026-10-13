class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum =0;
        for(int i =0;i<n;i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        int halfn=n/2;
        for(int i=0;i<n;i++){
            if(i<halfn){
                sum-=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }return sum;
    }
};