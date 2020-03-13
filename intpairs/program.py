# 牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
# 但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
# 牛牛希望你能帮他计算一共有多少个可能的数对。

# 输入包括两个正整数n,k(1 <= n <= 10^5, 0 <= k <= n - 1)。
# 对于每个测试用例, 输出一个正整数表示可能的数对数量。
# 输入 5 2
# 输出 7
# (2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)

import sys

def readInput():
    lines = sys.stdin.readlines()
    n, k = list(map(int, lines[0].strip().split()))
    return n, k

def solution(*args):
    n, k = args
    if k == 0:
        print(n * n)
        return

    count = 0

    for y in range(k, n+1):
        count += (n // y) * (y - k)
        count += max(0, n % y - k + 1)
    print(count)

if __name__ == "__main__":
    solution(*readInput())