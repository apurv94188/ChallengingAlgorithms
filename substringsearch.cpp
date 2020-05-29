class SubString {
public:
    int substr(string mainstring, string substring) {
        
        
        if (substring.size() > mainstring.size())
            return -1;
        if (substring.size() == mainstring.size())
            return substring == mainstring ? 0 : -1;
        
        if (substring.size() == 0)
            return 0;
        
        
        vector<int> ixsubstring(substring.size(),0);
        
        int j=0, i=1;
        
        while(i < substring.size()) {
            if (substring[j] == substring[i]) {
                ++j;
                ixsubstring[i] = j;
                ++i;
            }
            else if (j==0)
                    ++i;
            else {
                --j;
                j = ixsubstring[j];
            }
        }
        
        
        i=0;j=0;
        while (i<mainstring.size()) {
            
            if (mainstring[i] == substring[j]){
                ++i;++j;
                if (j==substring.size())
                    return i-j;
            }
            else if (j==0)
                ++i;
            else
                j = ixsubstring[j-1];
        }
        
        return -1;
    }
};
