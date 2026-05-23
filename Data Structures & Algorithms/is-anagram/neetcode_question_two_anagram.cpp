#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }

        unordered_map<char, int> mpps;
        unordered_map<char, int> mppt;

        //store frequenecy of each character in separate maps for both strings

        for(auto x: s){
            mpps[x]++;
        }
        for(auto x: t){
            mppt[x]++;
        }

        // if frequency of any character is different in both maps then return false
        for(auto it: mpps){
            if(it.second != mppt[it.first]){
                return false;
            }
        }
        return true;
    }
};
