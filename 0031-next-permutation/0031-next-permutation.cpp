// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = n -2; i>=0 ;i--){
//             if(nums[i]<nums[i+1]){

//             }
//         }
//     }
//     int nextsuccesor(int num){
//     int min = -1;
//     for(int i =n-1;i>0;i--){
//     }
// };
class Solution {
public:
    int nextsuccesor(vector<int>& nums,int pivot){
        for(int i=nums.size()-1;i>pivot;i--){
            if(nums[i]>nums[pivot]) return i;
        }
        return -1;
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),pivot=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        int start=0;
        if(pivot!=-1){
            int j=nextsuccesor(nums,pivot);
            int temp=nums[pivot];
            nums[pivot]=nums[j];
            nums[j]=temp;
            start=pivot+1;
        }
        int left=start,right=n-1;
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
    }
};