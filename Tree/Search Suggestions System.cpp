/**
 * leetcode no.1268
 */
 
struct Trie {
    unordered_map<char, Trie*> child;
    priority_queue<string> words;
};

void addWord(Trie* root, string& word) {
    Trie* cur = root;
    for (const char& c : word) {
        if (!cur->child.count(c)) {
            cur->child[c] = new Trie();
        }
        cur = cur->child[c];
        cur->words.push(word);
        if (cur->words.size() > 3) {
            cur->words.pop();
        }
    }
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie* root = new Trie();
    for (string& product : products) {
        addWord(root, product);
    }
    vector<vector<string>> res;
    Trie* cur = root;
    bool flag = false;
    for (const char& c : searchWord) {
        if (flag || !cur->child.count(c)) {
            res.emplace_back();
            flag = true;
        } else {
            cur = cur->child[c];
            vector<string> selects;
            while (!cur->words.empty()) {
                selects.push_back(cur->words.top());
                cur->words.pop();
            }
            reverse(selects.begin(), selects.end());
            res.push_back(selects);
        }
    }
    return res;
}