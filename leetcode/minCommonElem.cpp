class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int left=0,right=0;
        while(left<nums1.size() && right<nums2.size()){
            if(nums1[left]==nums2[right]) return nums1[left];
            else if(nums1[left]>nums2[right]){
                right++;
            }
            else{
                left++;
            }
        }
        return -1;
    }
};