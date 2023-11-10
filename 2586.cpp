#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int result = 0;
        while(left <= right) {
            if(st.count(words[left][0]) && st.count(words[left].back())) {
                ++ result;
            }
            ++ left;
        }
        return result;
    }
};


int main() {
    Solution solution;

    return 0;
}