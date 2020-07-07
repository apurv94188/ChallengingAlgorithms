// create a map -> key:word value:WordClass
// then we run over string s by hopping by fixed word len (wlen).
// to cover all cases we run over s wlen times, with offset 0 to wlen-1

class CWord {
    
    public:
    string m_sWord;
    int m_iCount=1;
    queue<int> m_pqLoc;
    
    CWord (string word) : m_sWord (word) {} 
    
    // reset loc
    void reset_pq() {
        m_pqLoc = {};
    }
    
    // add the new encountered word index to the queue
    // but first remove all the words (i.e. their indices) from the queue which were encountered before the start index
    // is the queue size is already full then return false
    bool inc_count (int start_loc, int cur_loc) {
        
        while (m_pqLoc.size() > 0 && m_pqLoc.front() < start_loc)
            m_pqLoc.pop();
        
        if (m_pqLoc.size() < m_iCount){
            m_pqLoc.push(cur_loc);
            return true;
        }
        
        return false;
    }
    
    // remove all the indices which is lees than start index
    // then remove the index which is first encountered at or after the start index
    // return the new start index just after this removed index
    int get_start (int start_loc, int cur_loc, int wlen) {
        while (m_pqLoc.front() < start_loc)
            m_pqLoc.pop();
        start_loc = m_pqLoc.front() + wlen;
        m_pqLoc.push(cur_loc);
        while (m_pqLoc.front() < start_loc)
            m_pqLoc.pop();
       
        return start_loc;
    }
    
};

vector<int> validate(string s, unordered_map<string, CWord> word_obj, int wlen, int total_lett, int start) {
    vector<int> ans;
    int count = 0;
    int dic_len = total_lett/wlen; // total num of words in dic
    
    for (int i=start; i<=s.size()-wlen;) {
        string word = s.substr(i,wlen);
        if (word_obj.find(word) == word_obj.end()) {
            start = i+wlen;
            count = 0;
        }
        else {
            CWord& obj = word_obj.find(word)->second;
            if (obj.inc_count(start, i) == false) {
                // freq of word (since the start index) increased more than the max freq allowed (as per dic)
                // remove the first encountered "this word" after the start. shift the start index too.
                start = obj.get_start(start, i, wlen);
                count = (i-start)/wlen+1;
            }
            else{
                if (++count == dic_len) {
                  // all words encountered....
                    ans.push_back(start);
                    start += wlen;
                    --count;
                }
            }
        }
        
        if (start + total_lett > s.size())
            break;
        
        i += wlen;
    }
    
    return ans;
}


class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size()==0)
            return {};
        if (s.size()==0)
            return {};
        
        vector<int> ans;
        if (words[0]=="") {
            for (int i=0; i<=s.size(); ++i)
                ans.push_back(i);
            return ans;
        }
        unordered_map<string, CWord> word_obj;
        
        for (string word : words) {
            if (word_obj.find(word) == word_obj.end()){
                CWord a(word);
                word_obj.insert({word, a});
            }
            else{
                CWord& obj = word_obj.find(word)->second;
                obj.m_iCount += 1;
            }
        }
        
        int wlen = words[0].size();
        int total_lett = wlen*words.size();
        int count;
        for (int turn=0; turn<wlen; ++turn) {
            int start = 0+turn; // offset
            vector<int> ans2 = validate(s, word_obj, wlen, total_lett, start);
            
            for (int a : ans2)
                ans.push_back(a);
            
        }
        
        return ans;
    }
};
