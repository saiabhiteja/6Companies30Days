#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/generate-random-point-in-a-circle/
*/
class Solution {
    private:
    double r,xo,yo;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius ;
        xo = x_center;
        yo = y_center ;
    }
    
    vector<double> randPoint() {
        vector<double> ans ;
         double x, y;
        x = (double)rand()/RAND_MAX * (r + r) + xo - r;
        y = (double)rand()/RAND_MAX * (r + r) + yo - r;
        while (pow((x-xo),2)+pow(y-yo,2)>pow(r,2)) {
            x = (double)rand()/RAND_MAX * (r + r) + xo - r;
            y = (double)rand()/RAND_MAX * (r + r) + yo - r;
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans ;
        
    }
};
int main() {
/**/
return 0;
}