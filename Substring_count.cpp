long substrCount(int n, string s) {
    
    long count=1, last_count=1;
    int b=0, m=-1,i=1, left;
    while (i<n) {
        if (m==-1) {
            if (s[i] == s[i-1]) {
                count += ++last_count;
            }
            else {
                m = i;
                left = m;
                last_count = 1;
                count += last_count;
            }
        }
        else {
            if (s[i] == s[i-1]) {
                if (--left >= 0 && s[left] == s[i])
                    count += ++last_count;
                else {
                    if (m+1==i)
                        ++last_count;
                    m=-1;
                    count += last_count;
                }
            }
            else{
                if (m+1==i) {
                    if (--left >= 0 && s[left] == s[i])
                        count += ++last_count;
                    else {
                        ++m;
                        left=m;
                        last_count = 1;
                        count += last_count;
                    }
                }
                else {
                    if (m+2==i && s[m]==s[i] && s[m+1]!=s[i])
                        ++count;
                    m=i;
                    left=m;
                    last_count = 1;
                    count += last_count;
                }
            }
        }
        //cout << s[i] << "-" << count << "-" << m << " ";
        ++i;
    }

    return count;
}
