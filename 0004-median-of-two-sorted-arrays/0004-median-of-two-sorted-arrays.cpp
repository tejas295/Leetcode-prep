class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i=0, j=0;
        int m=nums1.size(), n=nums2.size();
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }
            else{
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            merge.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            merge.push_back(nums2[j]);
            j++;
        }
        int r=merge.size();
        if(r%2==0){
            double result=(merge[r/2]+merge[r/2-1])/2.0;
            return result;
        }
        else{
            double answer=merge[r/2];
            return answer;
        }
    }
};