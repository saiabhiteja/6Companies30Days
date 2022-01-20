/*
link : https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/
*/

pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          set<pair<int, pair<int, int>>> s;
       
       pair<int, int> res{0, INT_MAX};
       
       for(size_t i = 0; i < k; ++i){
           s.insert( {KSortedArray[i][0], {i, 0}} );
       }
       
       while( !s.empty() ){
   
           int minVal = s.begin()->first; 
           int maxVal = s.rbegin()->first;
           if( res.second - res.first > maxVal - minVal )
           {
               res.first = minVal;
               res.second = maxVal;
           }
        
           int r = s.begin()->second.first;
           int c = s.begin()->second.second;
           s.erase(s.begin());
           if( c + 1 == n )
               break;
           s.insert( {KSortedArray[r][c+1], {r, c+1}} );
       }
       return res;
    }