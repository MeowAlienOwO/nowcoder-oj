# 给定排序数组arr和整数k，不重复打印arr中所有相加和为k的不降序三元组
# 例如, arr = [-8, -4, -3, 0, 1, 2, 4, 5, 8, 9], k = 10，打印结果为：
# -4 5 9
# -3 4 9
# -3 5 8
# 0 1 9
# 0 2 8
# 1 4 5
# [要求]
# 时间复杂度为O(n^2)空间复杂度为O(1)

# 第一行有两个整数n, k
# 接下来一行有n个整数表示数组内的元素
# 输出若干行，每行三个整数表示答案
# 按三元组从小到大的顺序输出(三元组大小比较方式为每个依次比较三元组内每个数)
import sys

def readInput():
    lines = sys.stdin.readlines()
    n, k = list(map(int, lines[0].strip().split()))
    A = list(map(int, lines[1].strip().split()))
    return n, k, A

def solution(*args):
    n, k, A = args
    # for i in range(n-2):
    while i < n-3:
        while A[i] == A[i+1]:
            i+= 1
        l, r = i+1, n-1
        t = k - A[i]
        while l < r:
            if A[l] + A[r] == t:
                print(A[i], A[l], A[r])
                while A[l] == A[l+1]:
                    l += 1
                while A[r] == A[r-1]:
                    r -= 1
                l += 1
                r -= 1
            elif A[l] + A[r] < t:
                l += 1
            else:
                r -= 1
        i += 1


if __name__ == "__main__":
    solution(*readInput())