#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        auto stringToInt = [](const string& str) -> int {
            int result = 0;
            for(char c : str) {
                result |= (1 << (c - 'a'));
            }
            return result;
        };

        const int size = words.size();
        vector<int> nums(size);
        for(int i = 0; i < size; ++i) {
            nums[i] = stringToInt(words[i]);
        }
        int result = 0;
        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if((nums[i] & nums[j]) == 0) {
                    result = max(result, (int)words[i].length()(int)words[j].length());
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> words = {
        "abcw","baz","foo","bar","xtfn","abcdef"
    };
    cout << solution.maxProduct(words) << endl;
    return 0;
}