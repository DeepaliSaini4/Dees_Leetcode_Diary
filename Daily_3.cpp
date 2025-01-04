/* 2270->NUMBER OF WAYS TO SPLIT AN ARRAY
Q-> You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.
*/
//------------------------>BRUTE FORCE  tc: O(nlogn)     sc: O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();

        //prefix sum array
        vector<long long>presum;
        vector<long long>postsum;
        long long sum = 0;
        long long psum=0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            psum+=nums[n-i-1];
            presum.push_back(sum);
            postsum.push_back(psum);
        }

        reverse(postsum.begin(),postsum.end()); 

        int count = 0;

       for(int i=1;i<n;i++){
        if(presum[i-1] >= postsum[i])
        count++;
       }

       return count;
    }
};
//----------------------------------->BETTER APPROACH       TC = O(N) ,  SC = O(N)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalsum=0;

        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        long long leftsum=0;

        vector<long long>lsum(n);

        for(int i=0;i<n;i++){
            leftsum+=nums[i];
            lsum[i]=leftsum;
        }

        long long rightsum;
        long long count =0;

        for(int i=0;i<n-1;i++){
            rightsum = totalsum - lsum[i];
            if(lsum[i]>=rightsum)
            count++;
        }

        return count;
    }
};
//------------------------------------->OPTIMAL APPROACH    TC = O(N) , SC = O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long rsum = 0;
        long long count = 0;
        long long lsum = 0;

        for(int i=0;i<n;i++){
            rsum+=nums[i];
        }

        for(int i=0;i<n-1;i++){
            lsum+=nums[i];
            rsum-=nums[i];
            if(lsum>=rsum)count++;
        }
       
        return count;
    }
};
