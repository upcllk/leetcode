#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        const int size = s.size();
        int count0 = 0, count1 = 0;
        int result = 0;
        for(int i = 0; i < size; ++i) {
            if(s[i] == '0') {
                if(i  > 0 && s[i-1] == '1') {
                    count0 = 0;
                }
                ++ count0;
                count1 = 0;
            }
            else {
                ++ count1;
            }
            if(count1 != 0 && count1 <= count0) {
                result = max(result, 2 * count1);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    return 0;
}