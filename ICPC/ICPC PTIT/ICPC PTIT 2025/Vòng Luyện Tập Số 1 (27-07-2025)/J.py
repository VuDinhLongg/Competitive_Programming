# Author : Vũ Hoàng Anh - B23DCVT037
import sys
import bisect

# Nếu như h_j - h_i > p_i thì bạn phải trả thêm p_i -> Mục tiêu nhảy miễn phí nhiều nhất mà ko phải trả thêm p_i

data = sys.stdin.read().split()
n = int(data[0])
h = [0]*n
p = [0]*n
idx = 1
for i in range(n):
    h[i] = int(data[idx]); p[i] = int(data[idx+1])
    idx += 2

# Tạo một mảng chỉ lưu idx và sort theo chiều cao của đảo

order = list(range(n))
order.sort(key=lambda i: (h[i], i))

hs = [h[i] for i in order]
ps = [p[i] for i in order]

f = [0]*n
for i in range(n):
    T = hs[i] + ps[i]
    j = bisect.bisect_right(hs, T) - 1 # Duyệt qua mảng đã sắp xếp theo chiều cao, tìm khoảng xa nhất mà đảo hiện tại có thể nhảy free đến
    f[i] = j

m = [0]*n
m[0] = f[0]
for i in range(1, n):
    m[i] = max(m[i-1], f[i]) # Mảng m lưu trữ sự tích lũy xa nhất mà nhảy free được, có thể từ khoảng xa nhất của ngay trước đó hoặc là f[i]

segs = []
start = 0
for i in range(n):
    if m[i] == i: # m[i] = i là khoảng xa nhất mà seg từ start -> i nhảy đến được, mục đích của mình là tìm seg xa nhất nhảy free
        segs.append((start, i))
        start = i + 1

extra = 0
for t in range(len(segs)-1):
    L, R = segs[t]
    nextL = segs[t+1][0]
    maxT = max(hs[i] + ps[i] for i in range(L, R+1)) # Tìm giá trị cao nhất của h_i + p_i
    minHn = hs[nextL] # Giá trị nhỏ nhất ở seg kế tiếp
    if minHn > maxT:
        extra += (minHn - maxT) # Mục đích để nhảy nhỏ nhất giữa các seg
total_p = sum(ps)
print(total_p + extra)
