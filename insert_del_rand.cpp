// insert, delete, get random element in O(1) time
// using a vector and an unordered_map
// variable vsize tells u the last element in the vector
// in delete operation, we are not actually deleting, rather we are just 
// replacing the to be deleted with the last element in the vector
// a better solution can be to use 2 unordered_map. That would save time and space both.

#include<time.h> 
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> m_ds; //val-pos
    vector<int> m_valOrder;
    int vsize;
    
    RandomizedSet() {
        vsize = 0;
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m_ds.find(val) != m_ds.end())
            return false;
        
        if (m_valOrder.size() == vsize)
            m_valOrder.push_back(val);
        else
            m_valOrder[vsize] = val;
        
        m_ds.insert({val, vsize});
        ++vsize;
        
        // for (int i=0; i<vsize; ++i)
        //      cout << m_valOrder[i] << " ";
        // cout << " size:"<< vsize <<" " << m_valOrder.size() <<endl;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto ele = m_ds.find(val);
        if (ele == m_ds.end())
            return false;
        
        int index = (*ele).second;
        
        if (vsize>1){
            m_valOrder[index] = m_valOrder[vsize-1];
            (*m_ds.find(m_valOrder[vsize-1])).second = index;
        }
        --vsize;
        m_ds.erase(val);
        // for (int i=0; i<vsize; ++i)
        //      cout << m_valOrder[i] << " ";
        // cout << " size:"<< vsize << " " << m_valOrder.size() <<endl;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (vsize==1)
            return m_valOrder[0];
        //cout << k << " " << vsize <<endl;
        return m_valOrder[rand() % vsize];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
