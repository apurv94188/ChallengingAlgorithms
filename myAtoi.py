import re


p = re.compile('^\s*((-|\+)?\d+)')


class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        r = p.search(str)
        if r is not None:
            i = int(r.groups()[0])
            min = -2 ** 31
            if i < min:
                return min
            max = 2 ** 31 - 1
            if i > max:
                return max
            return i
        return 0
