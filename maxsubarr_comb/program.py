# 先给出可整合数组的定义：如果一个数组在排序之后，每相邻两个数的差的绝对值都为1，或者该数组长度为1，则该数组为可整合数组。例如，[5, 3, 4, 6, 2]排序后为[2, 3, 4, 5, 6]，符合每相邻两个数差的绝对值都为1，所以这个数组为可整合数组
#给定一个数组arr, 请返回其中最大可整合子数组的长度。例如，[5, 5, 3, 2, 6, 4, 3]的最大可整合子数组为[5, 3, 2, 6, 4]，所以请返回5
#时间复杂度为O(n^2)空间复杂度为O(n)

# N个整数，分别表示数组内的元素

# 输出一个整数，表示最大可整合子数组的长度

import sys

def readInput():
    arr = list(map(int, sys.stdin.readline().strip().split()))
    return arr

def solution(arr):
    
    max_c = 1
    for l in range(len(arr) - 1):
        if max_c > len(arr) - l:
            break
        s = set()
        maxval = arr[l]
        minval = arr[l]
        for r in range(l, len(arr)):
            if arr[r] in s:
                break;
            s.add(arr[r])
            maxval = max(arr[r], maxval)
            minval = min(arr[r], minval)
            if maxval - minval == r - l:
                max_c = max(maxval - minval + 1 , max_c)
    print(max_c)


if __name__ == "__main__":
    solution(readInput())