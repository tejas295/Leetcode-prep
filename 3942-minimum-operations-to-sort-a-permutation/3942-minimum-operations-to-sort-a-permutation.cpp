#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int mn=nums[0],mx=nums[0];
        int minPos=0,maxPos=0;
        bool check=true;
        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn=nums[i];
                minPos=i;
            }
            if(nums[i]>mx){
                mx=nums[i];
                maxPos=i;
            }
        }
        if(minPos==0&&maxPos==n-1){
            check=true;
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1]){
                    check=false;
                    break;
                }
            }
            if(check)return 0;
        }
        if(maxPos==0&&minPos==n-1){
            check=true;
            for(int i=1;i<n;i++){
                if(nums[i]>nums[i-1]){
                    check=false;
                    break;
                }
            }
            if(check)return 1;
        }
        int ans=INT_MAX;
        check=true;
        for(int i=0;i<n;i++){
            int idx=(minPos+i)%n;
            if(nums[idx]!=i){
                check=false;
                break;
            }
        }
        if(check){
            ans=min(ans,minPos);
            ans=min(ans,n-minPos+2);
        }
        check=true;
        for(int i=0;i<n;i++){
            int idx=(maxPos+i)%n;
            if(nums[idx]!=n-1-i){
                check=false;
                break;
            }
        }
        if(check){
            ans=min(ans,maxPos+1);
            ans=min(ans,n-maxPos+1);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};