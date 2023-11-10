#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int m = spells.size(), n = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> result;
        for(int num : spells) {
            int pos = binary(potions, num, success);
            if((long long) num * potions[pos] >= success) {
                result.push_back(n - pos);
            }
            else {
                result.push_back(0);
            }
        }
        return result;
    }

    int binary(vector<int>& potions, long long num, long long success) {
        int left = 0, right = potions.size() - 1;
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(num * potions[mid] >= success) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};


int main() {
    Solution solution;

    return 0;
}