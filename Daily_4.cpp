/*
1930_Unique_Length3_Palindromic_Subsequence
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
*/

//-------> APPROACH - 1       TC=O(N)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.size();

        unordered_set<char>ch; 

        for(auto k:s){
            ch.insert(k);
        }

        int count = 0;

        for(auto v:ch){
            int i = -1;
            int j = 0;

            unordered_set<char>c;

               for(int k=0;k<n;k++){
                if(s[k] == v){
                    if(i==-1){
                        i=k;
                    }
                    j=k;
                }
            }

            unordered_set<char>bw;

            for(int k=i+1;k<j;k++){
                bw.insert(s[k]);
            }
            count+=bw.size();
        
        }

        return count;
    }
};

