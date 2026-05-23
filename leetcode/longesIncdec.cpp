class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
        int n=arr.size(),ans=1;
        vector<int>dp1(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }
        vector<int>dp2(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j++){
                if(arr[i]>arr[j]){
                    dp2[i]=max(dp2[j]+1,dp2[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,dp1[i]+dp2[n-i-1]);
        }
        return ans;
    }
};
