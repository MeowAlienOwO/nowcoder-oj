# 给定一个N \times MN×M的整形矩阵matrix和一个整数K, matrix的每一行和每一列都是排好序的。
# 实现一个函数，判断K是否在matrix中
# [要求]
# 时间复杂度为O(N+M)，额外空间复杂度为O(1)

# 第一行有三个整数N, M, K
# 接下来N行，每行M个整数为输入的矩阵
# 若K存在于矩阵中输出"Yes"，否则输出"No"


import sys

def readInput():
    lines = sys.stdin.readlines()
    n, m, k = list(map(int, lines[0].strip().split()))
    matrix = [list(map(int, line.strip().split())) for line in lines[1:]]
    return n, m, k, matrix

def solution(*args):
    n, m, k, matrix = args;

    for i in range(n):
        l, r = matrix[i][0], matrix[i][m-1]
        if l < k < r:
            for j in range(m):
                if matrix[i][j] == k:
                    print("Yes")
                    return
    
    print("No")

if __name__ == "__main__":
    solution(*readInput())