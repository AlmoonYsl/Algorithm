/**
 * leetcode no.49
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map <double,vector<string> > map;
    double a[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    for(string& s : strs)
    {
        double t = 1;
        for(char c : s)
            t *= a[c - 'a'];

        map[t].push_back(s);
    }
    for(auto& n : map)
        res.push_back(n.second);
    return res;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map <string,vector<string> > map;
        for(string& s : strs)
        {
            string t = s;
            sort(t.begin(),t.end());
            map[t].push_back(s);  
        }
        for(auto& n : map)            
            res.push_back(n.second);
        return res;
}