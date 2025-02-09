class Solution {
public:

    int LCS(string &text1,string &text2,int m,int n,vector<vector<int>> &dp)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(text1[i]==text2[j]) dp[i+1][j+1]=dp[i][j]+1;
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[m][n];
    }

    int longestCommonSubsequence(string text1, string text2) 
    {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int i=0;i<=m;i++) dp[i][0]=0;
        return LCS(text1,text2,m,n,dp);
    }
};