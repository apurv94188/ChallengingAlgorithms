class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        // sort based on euclidean distance
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return (pow(a[0],2) + pow(a[1], 2)) < (pow(b[0],2) + pow(b[1], 2));
        });
        
        // remove nik elements
        points.erase(points.begin()+K,points.end());
        return points;
    }
};
