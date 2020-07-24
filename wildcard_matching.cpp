// leetcode - https://leetcode.com/problems/wildcard-matching/submissions/
// starting from first char in 's' using pointer 'is'
// and from first char in 'p' using pointer 'ip', try to match s[is] == p[ip]
// Use dfs on every * encountered
// when any * is encountered at p[ip], check the next char in the pattern i.e. p[ip+1]
// if p[ip] == '?' then
//    then call isMatch function recursively and in each iteration increate 'is' by 1
//    keeping 'ip' = ip+1 in each iteration. In each iteration sub-probelm is s[is:] & p[ip+1:]
// if p[ip] == 'a-z' then skip all the character in 's' (starting from current pos 'is')
//    to the next occurence of char p[ip+1] inside the string 's'
// save the result in cache of each sub-probelm and before executing sub-problem check if
// already solved

class Solution {
public:
    
    unordered_map<int, unordered_map<int,bool>> cache; //ip -> {is->IsMatch}
    
    // check if sub-problem alread solved
    bool cache_exists(int ip, int is, bool& result){
        auto itr_ip = cache.find(ip);
        if (itr_ip == cache.end())
            return false;
        
        unordered_map<int,bool>& is_match = itr_ip->second;
        
        auto itr_is = is_match.find(is);
        if (itr_is == is_match.end())
            return false;
        
        result = itr_is->second;
        return true;
    }
    
    // save the result of sub-problem in the cache
    void save_to_cache(int ip, int is, bool result) {
        auto itr_ip = cache.find(ip);
        if (itr_ip == cache.end()){
            unordered_map<int, bool> is_match;
            is_match.insert({is,result});
            cache.insert({ip, is_match});
            return;
        }
        
        unordered_map<int, bool>& is_match = itr_ip->second;
        is_match.insert({is,result});
    }
    
    bool isMatch(string s, string p, int is, int ip) {
        //cout << endl << s.substr(is) << " " << p.substr(ip);
        
        // keep matching p[ip] and s[is] untill p[ip] =='*'
        --ip; --is;
        while (++ip < p.size() & ++is < s.size()) {
            if (p[ip] == '?') continue;
            if (p[ip] == '*') break;
            if (p[ip] != s[is]) return false;
        }
        
        if (ip==p.size()){
            if (is==s.size())
                return true;
            return false;
        }
        else if (is == s.size()) {
            // return true if only '*' is left in the pattern else return false
            while (p[ip]=='*' && ++ip < p.size());
            return ip==p.size();
        }
        
        // p[ip] is * at this point
        // skip all the consecutive *
        while (ip+1 < p.size() && p[ip+1] == '*') ++ip;
        // again p[ip] is * at this point
        if (ip == p.size()-1) //if this * is the last char of p
            return true;

        // atleast 2 char left in p at this point
        
        while (is < s.size()) {
            // if next char in pattern is not ? then skip the s to the first occurence of p[ip+1]
            if (p[ip+1] != '?')
                is = s.find(p[ip+1], is);
            
            if (is == std::string::npos) // if p[ip+1] not found in the s
                return false;
            
            bool result;
            if (cache_exists(ip+1, is, result)){
                // sub-problem already solved
                if (result)
                    return true;
            }
            else if (isMatch(s, p, is, ip+1)){
                // sub-problem returns true 
                //cout << " save true " << is << " " << ip;
                save_to_cache(ip+1, is, true);
                //cout << " saved";
                return true;
            }
            else{
                //cout << " save false " << is << " " << ip;
                save_to_cache(ip+1, is, false);
                //cout << " saved";
            }
            ++is;
        }
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }
};
