#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
int dfs(vector<vector<int>>& matrix, int i, int j, int lastValue, int dp[][205]){
        int row = matrix.size();
        int col = matrix[0].size();
        if(i<0 || j<0) return 0;
        if(i>=row || j>=col) return 0;
        if(matrix[i][j]<= lastValue) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int a = dfs(matrix, i+1,j,matrix[i][j],dp);
        int b = dfs(matrix, i-1,j,matrix[i][j],dp);
        int c = dfs(matrix, i,j-1,matrix[i][j],dp);
        int d = dfs(matrix, i,j+1,matrix[i][j],dp);

        int maxValue;
        maxValue = 1 + max(a,max(b,max(c,d)));
        dp[i][j]=maxValue;
        return maxValue;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxValue =INT_MIN;
        int dp[205][205];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int temp = dfs(matrix, i, j, -1, dp);
                maxValue= max(maxValue,temp);
            }
        }
        return maxValue;


    }