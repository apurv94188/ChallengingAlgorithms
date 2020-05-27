int Solution::majorityElement(const vector<int> &A) {
    
    int a_count[4][2] = {{0,0},{0,0},{0,0},{0,0}};
    for (int a : A) {
        int min_count = 0, i;
        for (i=0; i<4; ++i) {
            if (a_count[i][0] == a){
                ++a_count[i][1];
                break;
            }
            else if(a_count[i][1] < a_count[min_count][1])
                min_count = i;
        }
        
        if (i==4){
            a_count[min_count][0] = a;
            a_count[min_count][1] = 1;
        }
    }
    
    int max=0;
    for (int i=1; i<4; ++i)
        max = a_count[max][1] < a_count[i][1] ? i : max;
    return a_count[max][0];
}
