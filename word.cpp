class CTrie {
    
    bool m_bEnd = false;
    public:
    char m_cRep;
    unordered_map<char,CTrie*> m_setNext;
    CTrie (char rep) : m_cRep(rep){}
    bool is_end() { return m_bEnd;}
    void set_end() { m_bEnd=true;}
    
    static unordered_map<char, CTrie*> MapCharTrie;
    static bool word_search(string& A, int i);
    
    void insert_word(string word) {
        if (word.size() < 2){
            set_end();
            //cout << "&"<<word[0] << " ";
            return;
        }
        if (m_setNext.find(word[1]) == m_setNext.end()){
            m_setNext.insert({word[1], new CTrie(word[1])});
            //cout << "*" << word[1] << " ";
        }
        m_setNext[word[1]]->insert_word(word.substr(1));
    }
    
    bool subword_search (string& A, int i) {
        bool found=false;
        //cout << A[i] << " ";
        if (i+1 == A.size())
            return is_end();
        
        if (i < A.size()-1 && m_setNext.find(A[i+1]) != m_setNext.end())
            found = m_setNext[A[i+1]]->subword_search(A, i+1);
        //cout << "-nope-"<<A[i];
        if (found == false && m_bEnd && i < A.size()-1)
            found = CTrie::word_search(A, i+1);
        
        return found;
    }
    
    
};

unordered_map<char, CTrie*> CTrie::MapCharTrie;
bool CTrie::word_search(string& A, int i) {
    
    if (MapCharTrie.find(A[i]) == MapCharTrie.end())
        return false;
    //cout << "\n--";
    return MapCharTrie[A[i]]->subword_search(A, i);
}

int Solution::wordBreak(string A, vector<string> &B) {
    
    for (string word : B) {
        if (CTrie::MapCharTrie.find(word[0]) == CTrie::MapCharTrie.end())
            CTrie::MapCharTrie.insert({word[0], new CTrie(word[0])});
        CTrie::MapCharTrie[word[0]]->insert_word(word);
    }
    //cout <<"\n\n";
    return CTrie::word_search(A, 0);
    
}
