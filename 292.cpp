#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, bool> cache;

    bool canWinNim(int n) {
        if(n <= 3) {
            return true;
        }
        if(cache.count(n) != 0) {
            return cache[n];
        }
        bool result = canWinNim(n - 1) == false 
                    || canWinNim(n - 2) == false 
                    || canWinNim(n - 3) == false ;
        cache[n] = result;
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.canWinNim(124) << endl;
    return 0;
}