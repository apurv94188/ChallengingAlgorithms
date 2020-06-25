class FreqStack {
public:
    
    // index+1 of outer vector represent frequency
    // inner vector represent elements and their order when they reached
    // that frequency
    vector<vector<int>> freq_x; 
    
    // elements and their current frequency
    unordered_map<int,int> x_freq;
    
    FreqStack() {
        
    }
    
    
    void push(int x) {
        
        if (freq_x.size()==0) {
            freq_x.push_back({x});
            x_freq.insert({x,1});
            //cout << x << "," << x_freq[x] << " ";
            return;
        }
        
        // increment current freq by 1
        if (x_freq.find(x) == x_freq.end())
            x_freq.insert({x,1});
        else
            x_freq[x] += 1;
        
        // add element to 2-D vector
        if (freq_x.size() == x_freq[x]-1)
            freq_x.push_back({x});
        else
            freq_x[x_freq[x]-1].push_back(x);
        //cout << x << "," << x_freq[x] << " ";
    }
    
    int pop() {
        vector<int>& last_freq = freq_x.back();
        int x = last_freq.back();
        if (last_freq.size()==1) // if x only had the max freq
            freq_x.pop_back();
        else
            last_freq.pop_back();  // remove ele from highest freq list
        
        if (x_freq[x]==1)
            x_freq.erase(x);
        else
            x_freq[x] -= 1;
        //cout << "pop" << x <<","<<x_freq[x] << endl;
        return x;
    }
};
