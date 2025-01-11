/*
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
*/
#include<bits/stdc++.h>
using nmaesapce std;
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k==s.size()){
            return true;
        }
        //count the number of repeating words
        map<char,int>count;
        for(auto it:s){
            count[it]++;
        }
        int c =0;
        for(auto it:count){
            if(it.second %2!=0)
            c++;
        }
        if(c<=k && k<s.size())
        return true;

        return false;
    }
};
/*
For the string to be palindromic we need to have characters in such a way that all occur twice expect one occurring once!
*/
