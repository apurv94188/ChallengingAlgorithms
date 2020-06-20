class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if (newInterval.size()==0)
            return intervals;
        
        if (intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // new interval is the last interval
        if (intervals.back()[1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // new interval is the first interval
        if (intervals[0][0] > newInterval[1]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
         // new interval is the first interval with continuation       
        if (intervals[0][0] == newInterval[1]) {
            intervals[0][0] = newInterval[0];
            return intervals;
        }
        
        int i;
        // first find position of start of newInterval
        for (i=0; i<intervals.size(); ++i) {
            if (intervals[i][1] >= newInterval[0])
                break;
        }
        
        // find the position of end interval of newInterval
        int j=i;
        for ( ;j<intervals.size(); ++j) {
            if (intervals[j][1] >= newInterval[1]) {
                if (intervals[j][0] <= newInterval[1])
                    newInterval[1] = intervals[j][1];
                else
                    break;
            }
        }
        cout << i << " " << j << " " << newInterval[0] <<"," << newInterval[1] << endl;
        // j represents the interval which fals after the newInterval
        // if ith interval can be merged with new interval..
        if(intervals[i][0] <= newInterval[0]) {
            if (i<j){
                // delete the interval which overlaps with current interval
                intervals.erase(intervals.begin()+i+1, intervals.begin()+j);
            }
            intervals[i][1] = max(intervals[i][1], newInterval[1]);
        }
        else{
            //if (intervals[i][0] > newInterval[0]) { // insert at pos i
            if (i<j){
                // delete the interval which overlaps with current interval
                intervals.erase(intervals.begin()+i, intervals.begin()+j);
            }
            intervals.insert(intervals.begin()+i, {newInterval[0], newInterval[1]});;
        }
        
        return intervals;
    }
    
    
};
