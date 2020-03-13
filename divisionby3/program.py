import sys
# 小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
# 并且小Q对于能否被3整除这个性质很感兴趣。
# 小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。 

# 输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。

# 输出一个整数, 表示区间内能被3整除的数字个数。

def readInput():
    line = sys.stdin.readline().strip()
    l, r = list(map(int, line.split()))
    return l, r



def solution(l, r):
    # 注意到规律：1, 12, 123... 的余数分别为1, 0, 0
    tail = [0, 0, 1]
    l = l-1
    left = l // 3 * 2 + tail[l % 3]
    right = r // 3 * 2 + tail[r % 3]
    print(right - left)



if __name__ == '__main__':
    solution(*readInput())