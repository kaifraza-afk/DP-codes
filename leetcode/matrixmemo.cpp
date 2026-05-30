class Solution{
	public:
        int findMin(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
            if(i==j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int mini=INT_MAX;
            for(int k=i;k<j;k++){
                int steps=nums[i-1]*nums[k]*nums[j]+findMin(nums,i,k,dp)+findMin(nums,k+1,j,dp);
                mini=min(mini,steps);
            }
            return dp[i][j]=mini;
        }
		int matrixMultiplication(vector<int>& nums){
            //your code goes here
            if(nums.size()<=2) return 0;
            int n=nums.size();
            vector<vector<int>>dp(n,vector<int>(n,-1));
            return findMin(nums,1,nums.size()-1,dp);
    	}
};