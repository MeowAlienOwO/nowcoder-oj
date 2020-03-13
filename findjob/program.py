import sys
import bisect
sys.path.append('..')
from nowcoder.nowcodertools import fn_timer
# 为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。

# 每个输入包含一个测试用例。
# 每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
# 接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
# 接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
# 保证不存在两项工作的报酬相同。

# 对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

# 输入
# 3 3 
# 1 100 
# 10 1000 
# 1000000000 1001 
# 9 10 1000000000

# 输出
# 100 
# 1000 
# 1001

def readInput():
    (N, M) = list(map(int, sys.stdin.readline().strip().split()))
    W = []
    for i in range(N):
        line = sys.stdin.readline()
        line = line.strip()
        W.append(list(map(int, line.split())))
    A = list(map(int, sys.stdin.readline().strip().split()))
    return M, N, W, A
# @profile
# @fn_timer
def solution(M, N, W, A):
    W.sort(key = lambda x: x[0])
    Wkeys = [w[0] for w in W]
    D = {}


    max_p = 0
    for (d, p) in W:
        max_p = max(p, max_p)
        D[d] = max_p
    for a in A:
        if a in D:
            print(D[a])
        else:
            idx = bisect.bisect(Wkeys, a)
            if idx == 0:
                print(0)
            else:
                print(D[Wkeys[idx-1]])
        

if __name__ == '__main__':
    solution(*readInput())