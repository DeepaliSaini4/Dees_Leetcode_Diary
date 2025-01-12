/*
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false
*/
//-------->APPROACH - 1          TC = O() ,  SC = O( )
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0) return false; // Length must be even

        // Forward pass: check for excess closing parentheses
        int open = 0, unlocked = 0;
        for (int i = 0; i < s.length(); i++) {
            if (locked[i] == '0') {
                unlocked++;
            } else if (s[i] == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else if (unlocked > 0) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }

        // Backward pass: check for excess opening parentheses
        int close = 0;
        unlocked = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                unlocked++;
            } else if (s[i] == ')') {
                close++;
            } else {
                if (close > 0) {
                    close--;
                } else if (unlocked > 0) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};



