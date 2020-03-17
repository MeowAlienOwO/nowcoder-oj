# 牛客网线下自刷题

自刷题库+简单的 shell 脚本用于查看输入输出，目前只支持 c++ 与 python

## 创建新的问题
```shell
./newproblem.sh <name> <suffix>
```


### 测试
简单的使用 diff 作为比较输入输出的方法
```shell
./runtest.sh <name> <suffix>
```

## 目录说明
- `problem/program.cpp/py` 主代码
- `problem/inputs.txt` 输入，三个#号开头+数字为分隔符
- `problem/outputs.txt`输出，三个#号开头+数字为分隔符，数字要与输入对应
- `problem/tmp.txt` debug用的文件，可以修改 runtest.sh 删掉
- `lib` 一些辅助函数
