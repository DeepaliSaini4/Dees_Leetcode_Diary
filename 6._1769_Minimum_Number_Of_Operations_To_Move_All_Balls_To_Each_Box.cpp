/*
Q--> You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.
*/
//--------------------------------->APPROACH - 1.  (BRUTE).       TC = O(N^2)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int dis = 0;
            for(int j=0;j<n;j++){

                if(boxes[j]=='1') //ball found!
                dis += abs(j-i);
            }
            ans.push_back(dis);
        }
        return ans;
    }
};
//--------------------------------->APPROACH - 2  (OPTIMAL)      TC = O(N)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n,0);
        int movestoleft = 0;
        int ballstoleft = 0;
        int movestoright = 0;
        int ballstoright = 0;
        for(int i=0;i<n;i++){

            //left pass --> Track moves as balls accumulate from left
            ans[i] += movestoleft;
            ballstoleft += boxes[i]-'0';
            movestoleft += ballstoleft; 

            //right pass --> Tracks moves as balls accumulates from the right
            int j= n-i-1;
            ans[j] += movestoright;
            ballstoright +=boxes[j]-'0';
            movestoright +=ballstoright;
        }
        return ans;
    }
};