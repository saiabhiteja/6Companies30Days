/*
link : https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/

*/
int minSteps(int D){
         int steps = 0, sum = 0;
        while(true){
            sum = sum + steps;
            steps++;
            if(sum == D){
                return steps-1;
                break;
            }
            if(sum > D and (sum-D)%2 == 0){
                return steps-1;
                break;
            }
        }
        return 0;
}