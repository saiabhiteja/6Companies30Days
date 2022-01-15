/*
link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
Given an integer array arr of size N, the task is to divide it into two 
sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference
*/

int minDifference(int arr[], int n)  { 
    
    long sum = 0 ;
    
    for(int i = 0;i<n;i++){
        sum = sum+arr[i] ;
    }
	    
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
        
        vector <int> temp ;
        for(int i = 0; i<=(sum+1)/2 ; i++){
            if(dp[n][i]){
                temp.push_back(i);
            }
        }
        
        int min = INT_MAX ;
        
        for(int i = 0;i<temp.size();i++){
            int x = abs(sum - (2*temp[i]));
            if(x<min){
                min = x ;
            }
            
        }
        return min ;
        /*
        Time : O(N^2)
        Space : O(N)
        */
	} 