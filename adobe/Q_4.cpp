/*
link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/

bool isSubsetSum(int n, int arr[], int sum){
        // array of booleans
        bool dp[n+1][sum+1];

        //base condition = intialising the the matrix
        for(int i = 0 ;i<=n;i++){
            for(int j = 0;j<=sum;j++){
                
                if(j==0){
                    dp[i][j] = true;
                }
                
                if(i==0 & j>0){
                    dp[i][j] = false ;
                }
                
            }
        }
        //other conditions 
        for(int i =1;i<=n;i++){
            for(int j =1;j<=sum;j++){
                if(arr[i-1]<=j){
                    //using or operator in place of max operator
                    dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j] ;
                }
            }
        }
        
        return dp[n][sum] ;
    }
    int equalPartition(int N, int arr[])
    {
        long sum = 0;
        for(int i=0;i<N;i++){
            sum = sum+arr[i];
        }
        
        if (sum%2 != 0){
            return 0;
        }
        
        else{
            if(isSubsetSum(N,arr,sum/2)){
                return 1;
            }
            else{
                return 0 ;
            }
        }
    }