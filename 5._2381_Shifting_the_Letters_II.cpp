
/*
Q-> You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, 
shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting
a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.


*/

//-------------------------------->APPROACH-1.                TC = O(N+M).                  SC = O(N)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(
            n, 0);  // Initialize a difference array with all elements set to 0.

        for (auto shift : shifts) {
            if (shift[2] == 1) {        // If direction is forward (1):
                diffArray[shift[0]]++;  // Increment at the start index to
                                        // indicate a forward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]--;  // Decrement at the end+1 index to stop the
                                     // effect of the shift.
                }
            } else {                    // If direction is backward (0):
                diffArray[shift[0]]--;  // Decrement at the start index to
                                        // indicate a backward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]++;  // Increment at the end+1 index to stop the
                                     // effect of the shift.
                }
            }
        }

        string result(n, ' ');
        int numberOfShifts = 0;

        for (int i = 0; i < s.size(); i++) {
            numberOfShifts = (numberOfShifts + diffArray[i]) %
                             26;  // Update cumulative shifts, keeping within
                                  // the alphabet range.
            if (numberOfShifts < 0)
                numberOfShifts +=
                    26;  // Ensure `numberOfShifts` is non-negative.

            // Calculate the new character by shifting `s[i]`
            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }

        return result;
    }
};