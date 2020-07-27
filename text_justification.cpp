// leetcode: https://leetcode.com/problems/text-justification/submissions/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Text Justification.
// Memory Usage: 7.4 MB, less than 87.84% of C++ online submissions for Text Justification.

/* Solution explaination:
there should be atleast 1 space between any 2 words.
for each line:
step 1: we will first run a loop which will check how many words we can accommodate byt checking size
step 2: then we cound number of spaces to be inserted between words
        step a.
        loop:
         new_line_size = ith word.size
         while new_line_size <= maxWidth:
            new_line_size +=  1 space + next_word.size
        end
        step b.
        extra_space_left = maxWidth - new_line_size
        distribute this extra scpae
        if only 1 owrd in line || last line:
            space b/w words = 1 (this is included in the new_line_size)
            total right end space = maxWidth - new_line_size
        else:
            space_per_word = extra_space_left / (number of slots in the line)
            number of left words to have 1 extra space = extra_space_left % (number of slots in the line)
         
step 3: we add words along with spaces
step 4: run step 1-3 for untill all words have been covered.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> text;
        string line;
        int i=0, begin, line_len, space_per_word, extra_space, rightend_space;
        
        while(i < words.size()) {
            line_len = words[i].size();
            begin = i;
            // calculate number of words that can fit in the line along with 1 space between then
            while (++i < words.size() && line_len+1+words[i].size() <= maxWidth)
                line_len += 1 + words[i].size();
            
            // calcualte number of spaces between words
            if (i == words.size() || i-begin-1==0){
                // if last line or only 1 word in the new line
                rightend_space = maxWidth - line_len; // spaces at the of the line
                space_per_word = 0; // as already we have counted 1 space b/w words
                extra_space = 0;
            }
            else{
                space_per_word = (maxWidth-line_len)/(i-begin-1); // spaces in addition to 1 space we counted between the words
                extra_space = (maxWidth-line_len)%(i-begin-1); // number of words from left to have 1 extra space 
                rightend_space = 0;
            }
            
            
            line = words[begin++];
            for (;begin<i;++begin) {
                line += " ";
                for (int s=0; s<space_per_word; ++s)
                    line += " ";
                if(extra_space) {
                    line += " ";
                    --extra_space;
                }
                line += words[begin];
            }
            while (rightend_space--)
                line += " ";
            
            text.push_back(line);
        }
        
        return text;
    }
};
