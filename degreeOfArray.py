
# degree of an array is defined as the freq of a number with max freq in the array
# here maxCount is the degree
# minSubArrLen is the length of the smallest sub-array whose degree is equal to degree of the array

arr = [1,2,2,3,1]
maxCount = 1. # degree of the array
minSubArrLen = 1.
dic = {}    # n:[count, start, end]

for i in range(len(arr)):
    n = arr[i]
    if n in dic.keys():
        dic[n][0] += 1
        dic[n][2] = i
        if maxCount < dic[n][0]:     # if degree is larger than what so far found
            maxCount = dic[n][0]
            minSubArrLen = dic[n][2] - dic[n][1] + 1
        elif maxCount == dic[n][0]:
            # if degree == count of this n then check if the minSubArrLen is less
            l = dic[n][2] - dic[n][1] + 1
            if minSubArrLen > l:
                minSubArrLen = l
    else:
        dic[n] = [1,i,i]

print(maxCount, " ")
print(minSubArrLen, " ")






        
