"""
그리디 알고리즘
"""
import sys
os = sys.platform
if os != "linux":
    print("명재야 보아하니 백준에서 푼게 아니구나")
    input = open("example.txt", "rt").readline
else:
    input = sys.stdin.readline

n, target = map(int, input().split())
coin_type = list(reversed([int(input()) for _ in range(n)]))

cnt = 0
for coin in coin_type:
    if target // coin >= 1:
        cnt += target // coin
        target = target % coin
print(cnt)
