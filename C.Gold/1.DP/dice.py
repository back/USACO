n=int(input())
dp = [0] * (n+1)
dp[0] = 1
for i in range(1,n+1):
    for j in range(i-6,i):
        if j>=0:
            dp[i]+=dp[j]
    dp[i] %= 1000000007      
print(dp[n])
