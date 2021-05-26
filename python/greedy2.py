n, m, k = map(int, input().split())
# n : number of data 
# m : number of add time
# k : number of overlap
data = list(map(int, input().split()))

data.sort()
first_bignum = data[n-1]
second_bignum = data[n-2]

count = int(m / (k+1)) * k
count += m % (k+1)

result = 0
result = count*first_bignum
result += (m-count)*second_bignum

print(result)