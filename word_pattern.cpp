/*
LeetCode: https://leetcode.com/problems/word-pattern/
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, string> code_p_word;  // store code-word corresponding to each letter of pattern
        unordered_map<string, char> code_word_p; // store char-coode corresponding to each word in s
        
        int i=-1, i_word_start;
        string word;
        char p;
        for (int j=0; j<pattern.size(); ++j) {
            p = pattern[j];
            i_word_start = ++i;
            if (i>=s.size())
                return false;
            while (i < s.size() && s[i] != ' ') ++i;  // get next word
            word = s.substr(i_word_start, i-i_word_start);
            
            auto p_code = code_p_word.find(p);
            
            if (p_code != code_p_word.end()) {
                if (p_code->second != word)
                    return false;
            } else{
                auto word_code = code_word_p.find(word);
                if (word_code != code_word_p.end())
                    return false;
                code_p_word.insert({p, word});
                code_word_p.insert({word,p});
                
            }
            
        } // for p
        if (i<s.size())
            return false;
        return true;
                    
    }
};
