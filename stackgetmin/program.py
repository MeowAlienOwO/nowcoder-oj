# 题目描述
# 实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。
# 
# 输入描述:
# 第一行输入一个整数N，表示对栈进行的操作总数。
# 下面N行每行输入一个字符串S，表示操作的种类。
# 如果S为"push"，则后面还有一个整数X表示向栈里压入整数X。
# 如果S为"pop"，则表示弹出栈顶操作。
# 如果S为"getMin"，则表示询问当前栈中的最小元素是多少。
# 输出描述:
# 对于每个getMin操作，输出一行表示当前栈中的最小元素是多少。

import sys

def readInput():
    lines = sys.stdin.readlines()
    a, b = list(map(int, lines[0].strip().split()))
    c = [list(map(int, line.strip().split())) for line in lines[1:a]]
    return a, b, c

def solution(*args):
    pass

if __name__ == "__main__":
    solution(*readInput())