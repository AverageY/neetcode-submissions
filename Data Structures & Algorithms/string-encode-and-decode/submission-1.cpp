class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string result=to_string(strs[0].size())+"#"+strs[0];
        for(int i =1; i<strs.size(); i++){
            result+=to_string(strs[i].size())+"#"+strs[i];
        }
    return result;
    }

    vector<string> decode(string s) {
    vector<string> result;
    int i = 0;
    while (i < s.size()) {
        // Find the position of the next '#' to get the length prefix
        size_t found = s.find('#', i);
        
        // Extract the length and move the pointer past the '#'
        int len = stoi(s.substr(i, found - i));
        i = found + 1;
        
        // Read exactly 'len' characters as the original string
        result.push_back(s.substr(i, len));
        
        // Advance the pointer to the start of the next length prefix
        i += len;
    }
    return result;
}
};
