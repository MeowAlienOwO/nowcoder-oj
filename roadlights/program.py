# 小Q正在给一条长度为n的道路设计路灯安置方案。
# 为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。
# 小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
# 小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。

# 输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
# 接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
# 第二行一个字符串s表示道路的构造,只包含'.'和'X'。

# 对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。

import sys

def readInput():
    lines = sys.stdin.readlines()
    t = int(lines[0].strip())
    #c = [list(map(int, line.strip.split)) for line in lines[1:a]]
    roads = list(zip(lines[1::2], lines[2::2]))

    return t, roads

def solution(t, roads):
    for k in range(t):
        # print("k=", k)
        (n, s) = roads[k]
        s = s.strip()
        count = 0;
        ptr = 0
        while ptr < len(s):
            if s[ptr] == 'X':
                ptr += 1
            else:
                step =min(3, len(s) - ptr)
                sliced = s[ptr:ptr+step]
                # print("ptr=", ptr, sliced)
                if not len([c for c in sliced if c =='X']) == len(sliced) and len(sliced) > 0:
                    count += 1
                ptr += step
        print(count)






if __name__ == "__main__":
    solution(*readInput())