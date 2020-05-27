vector<int> Solution::nextPermutation(vector<int> &A) {
    
    int i;
    for (i=A.size()-1; i>0; --i) {
        if (A[i-1] < A[i])
            break;
    }
    
    if (i>0) {
        int t = i, temp;
        for (int j=i+1; j<A.size(); ++j)
            if (A[i-1] < A[j] && A[t] > A[j])
                t = j;
        
        temp = A[t];
        A[t] = A[i-1];
        A[i-1] = temp;
    }
    
    sort(A.begin()+i, A.end());
    return A;
}
