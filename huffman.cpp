#include <bits/stdc++.h>

using namespace std;

#define LEFT    '0'
#define RIGHT   '1'

int g_order = 0;

map<int, string> codeMap = {};
map<int, int> indexMap = {};

struct HuffmanTreeNode {    
    int val;
    HuffmanTreeNode* left, *right;
    int count;
    int order;
    HuffmanTreeNode(int _count, int _val = 0) : val(_val), count(_count), left(nullptr), right(nullptr), order(g_order) { ++ g_order; }
};

void preOrder(HuffmanTreeNode* root, const string code) {
    if(root == nullptr) {
        return;
    }
    if(root->left == nullptr && root->right == nullptr) {
        codeMap[root->val] = code;
    }
    preOrder(root->left, code + LEFT);
    preOrder(root->right, code + RIGHT);
}

struct cmp {
    bool operator() (HuffmanTreeNode* const &node1, HuffmanTreeNode* const &node2) const {
        return node1->count == node2->count ? 
                (
                    node1->val != 0 && node2->val != 0 ?
                        indexMap[node1->val] < indexMap[node2->val] :
                        (
                            node1->val == 0 && node2->val == 0 ? 
                                node1->order < node2->order :
                                node1->val > 0
                        )
                ) :
                node1->count < node2->count;
    }
};

HuffmanTreeNode* unionHuffmanKey(set<HuffmanTreeNode*, cmp>& nodeSet) {
    if(nodeSet.size() == 1) {
        return *nodeSet.begin();
    }
    auto node1 = *nodeSet.begin();
    nodeSet.erase(nodeSet.begin());

    auto node2 = *nodeSet.begin();
    nodeSet.erase(nodeSet.begin());

    HuffmanTreeNode* root = new HuffmanTreeNode(node1->count + node2->count);
    root->left = node1;
    root->right = node2;
    nodeSet.insert(root);

    return unionHuffmanKey(nodeSet);
}


HuffmanTreeNode* buildHuffmanTree(const string& str) {
    if(str.empty()) {
        return nullptr;
    }
    unordered_map<int, int> countMap;
    for(char c : str) {
        countMap[c]++;
    }
    
    set<HuffmanTreeNode*, cmp> nodeSet = {};
    for(auto [key, value] : countMap) {
        nodeSet.insert(new HuffmanTreeNode(value, key));
    }
    return unionHuffmanKey(nodeSet);
}

string decode(HuffmanTreeNode* root, const string& before) {

    HuffmanTreeNode* cur = nullptr;
    string after = "";
    int index = 0;
    while(index < before.size()) {
        cur = root;
        while(index < before.size()) {
            if(cur->left == nullptr && cur->right == nullptr) {
                after += char(cur->val);
                break;
            }
            if(before[index] == LEFT) {
                if(cur->left == nullptr) {
                    return "INVALID";
                }
                cur = cur->left;
            } 
            else {
                if(cur->right == nullptr) {
                    return "INVALID";
                }
                cur = cur->right;
            }
            ++ index;
        }
    }
    if(!(cur->left == nullptr && cur->right == nullptr)) {
        return "INVALID";
    }
    after += char(cur->val);
    return after;
    
}


int main() {

    string str, before1, before2;
    getline(cin, str);
    getline(cin, before1);
    getline(cin, before2);

    for(int i = 0; i < str.size(); ++i) {
        if(indexMap.count(str[i]) == 0) {
            indexMap[str[i]] = i;
        }
    }
    HuffmanTreeNode* root = buildHuffmanTree(str);
    preOrder(root, "");

    int beforeSize = str.size();
    int afterSize = 0;
    for(char c : str) {
        afterSize += codeMap[c].size();
    }
    afterSize = (afterSize + 7) / 8;
    cout << beforeSize << " " << afterSize << endl;

    vector<pair<int, string>> vec = {};
    for(auto& [key, value] : codeMap) {
        vec.push_back({key, value});
    }
    sort(vec.begin(), vec.end(), [&](auto& p1, auto& p2) {
        return p1.second.size() == p2.second.size() ?
            indexMap[p1.first] < indexMap[p2.first] :
            p1.second.size() > p2.second.size();
    });
    for(auto& pi : vec) {
        cout << char(pi.first) << ":" << pi.second << endl;
    }

    cout << decode(root, before1) << endl;
    cout << decode(root, before2) << endl;

    return 0;

}