class Solution {
public:
    
    inline int get_distance(char a, char b) {
        if (a<=b)
            return b-a;
        return 26-(a-'a'+1)+(b-'a'+1);  // example a='g' and b='d'
    }
    
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size())
            return false;
        if (s == "")
            return true;
        
        vector<int> ik (26, 0);
        
        int distance;
        
        for (int i=0; i<s.size(); ++i) {
            distance = get_distance(s[i], t[i]);
            if (distance==0)
                continue;
            
            // ik[distance] tells that how many 26 char shifting previous char, having same distance, had to make.
            // soo this char will have to make 1 more time 26 char shifting + the distance.
            if (ik[distance]*26+distance > k)
                return false;
            
            ++ik[distance];
        }
        
        return true;
    }
};
