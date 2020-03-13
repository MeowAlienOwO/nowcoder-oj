/**
 * author: meow
 * 题目描述
 * 给定一个矩阵matrix，其中的值有正、有负、有0，返回子矩阵的最大累加和
 * 例如，矩阵matrix为：
 * -90 48 78
 * 64 -40 64
 * -81 - 7 66
 * 其中，最大的累加和的子矩阵为：
 * 48 78
 * -40 64
 * -7 66
 * 所以返回累加和209。
 * 例如，matrix为：
 * -1 -1 -1
 * -1 2 2
 * -1 -1 -1
 * 其中，最大累加和的子矩阵为：
 * 2 2
 * 所以返回4
 * [要求]
 * 时间复杂度为O(n^2m)空间复杂度为O(nm)
 * 输入描述:
 * 第一行有两个整数N，M。分别表示矩阵的行数/列数
 * 接下来N行，每行M个整数表示矩阵内的数
 * 输出描述:
 * 输出一个整数表示答案
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;

int main(){

    // freopen("input.txt","r",stdin); 
    int n, m;
    scanf("%d %d", &n, &m);
    vector< vector<int> > matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int res = -INF;

    for(int i = 0; i < n; i++){
        vector<int> s(m, 0);
        for(int k = i; k < n; k++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                s[j] += matrix[k][j];
                sum += s[j];
                res = max(sum, res);
                if(sum < 0){
                    sum = 0;
                }
            }

        }
    }
   cout << res << endl;

    return EXIT_SUCCESS;
}