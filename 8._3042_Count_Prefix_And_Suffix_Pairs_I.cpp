/*
Q--> You are given a 0-indexed string array words.
Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:isPrefixAndSuffix(str1, str2) returns true if str1 is both a 
prefix and a suffix of str2, and false otherwise.
For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.
*/
//-------> APPROACH - 1      TC = O (N^2 *M)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                if(words[i].size()>words[j].size()) continue;
                if(words[j].find(words[i])==0 && words[j].rfind(words[i])==words[j].size()-words[i].size()){
                    count++;
                }
            }
        }
        return count;
    }
};
