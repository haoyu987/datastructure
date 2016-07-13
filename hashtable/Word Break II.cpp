/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]
*/


class Solution {
public:
    unordered_map<string,vector<string>> res;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(res.count(s)!=0) return res[s];
        vector<string> result;
        if(wordDict.count(s)!=0) result.push_back(s);
        for(int i=1;i<s.length();i++){
            string word=s.substr(i);
            if(wordDict.count(word)>0){
                string rem=s.substr(0,i);
                vector<string> pre = wordBreak(rem,wordDict);
                for(auto i=pre.begin();i!=pre.end();i++){
                    *i += ' '+word;
                }
                result.insert(result.end(),pre.begin(),pre.end());
            }
        }
        res[s] = result;
        return result;
    }
};
