/*
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
A substring is a contiguous sequence of characters within a string
*/
//--------------->APPROACH 1- BRUTE.     TC = O(N^2.M^2)
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isSubstring(string one, string two) {
        int n1 = one.size();
        int n2 = two.size();
        
        // If the second word is larger, it cannot be a substring
        if (n2 > n1) return false;

        for (int i = 0; i <= n1 - n2; i++) {
            int j = 0;
            while (j < n2 && one[i + j] == two[j]) {
                j++;
            }
            
            if (j == n2) {
                return true; // All characters matched
            }
        }
        return false; // No match found
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        set<string> temp;
        
        for (int i = 0; i < n; i++) {
            for (int m = 0; m < n; m++) {
                if (i == m) continue;

                if (isSubstring(words[m], words[i])) {
                    temp.insert(words[i]);
                }
            }
        }
        
        return vector<string>(temp.begin(), temp.end());
    }
};
