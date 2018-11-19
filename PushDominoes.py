class Solution:
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        domi = ""
        i=-1
        j=0
        prevR = False
        rLen = 0
        while j < len(dominoes):
            if dominoes[j] == "L":
                if prevR:
                    # find out half distance
                    ir = int((j-i-1)/2)
                    domi += ("R"*ir)   #add R to first half of the distance
                    # adding . if it is odd middle dominoes
                    if (j-i-1)%2 != 0:
                        domi += "."
                    domi += ("L"*(ir+1))  # add L to 2nd half + 1 L
                    prevR = False
                    i = j
                else:
                    domi += ("L"*(j-i))   # set left all . to L
                    i = j
            elif dominoes[j] == "R":
                if prevR:
                    domi += ("R"*(j-i))  # set all . to R b/w the 2 R
                else:
                    domi += (dominoes[i+1 : j+1])  # if no prev R - then copy
                prevR = True
                i = j
            j += 1

        # if last element is "."
        if dominoes[j-1] == ".":
            if prevR:
                    domi += ("R"*(j-i-1))
            else:
                domi += (dominoes[i+1 : j])

        return domi
