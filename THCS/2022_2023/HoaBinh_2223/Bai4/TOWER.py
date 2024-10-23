import bisect

def min_towers(n, blocks):
    towers = []
    
    for block in blocks:
        # Tìm vị trí thích hợp để thay thế hoặc tạo tháp mới
        pos = bisect.bisect_right(towers, block)
        
        if pos < len(towers):
            towers[pos] = block
        else:
            towers.append(block)
    
    return len(towers)

# Nhập dữ liệu
n = int(input())
blocks = list(map(int, input().split()))

# Xuất kết quả
print(min_towers(n, blocks))
