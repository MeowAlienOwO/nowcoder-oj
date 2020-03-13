# 给定排序数组arr和整数k，不重复打印arr中所有相加和为k的不降序二元组
# 例如, arr = [-8, -4, -3, 0, 1, 2, 4, 5, 8, 9], k = 10，打印结果为：
# 1, 9
# 2, 8
# [要求]
# 时间复杂度为O(n)，空间复杂度为O(1)

# 第一行有两个整数n, k
# 接下来一行有n个整数表示数组内的元素
# 输出若干行，每行两个整数表示答案
# 按二元组从小到大的顺序输出(二元组大小比较方式为每个依次比较二元组内每个数)

import sys

def readInput():
    lines = sys.stdin.readlines()
    n, k = list(map(int, lines[0].strip().split()))
    A = list(map(int, lines[1].strip().split()))
    return n, k, A

def solution(*args):
    n, k, A = args
    l, r = 0, len(A)-1
    while l < r:
        if A[l] + A[r] == k:
            print(A[l], A[r])

            while A[l+1] == A[l]:
                l += 1
            while A[r-1] == A[r]:
                r -= 1
            
            l += 1
            r -= 1

        elif A[l] + A[r] < k:
            l += 1
        else:
            r -= 1
if __name__ == "__main__":
    solution(*readInput())