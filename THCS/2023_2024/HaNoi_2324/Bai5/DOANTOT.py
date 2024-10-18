class Segment:
    def __init__(self, l, r):
        self.l = l
        self.r = r

def main():
    MOD = 10**9 + 7
    
    # Đọc dữ liệu
    with open('DOANTOT.INP', 'r') as f:
        N = int(f.readline().strip())
        segments = []
        for _ in range(N):
            L, R = map(int, f.readline().strip().split())
            segments.append(Segment(L, R))
    
    # Danh sách lưu các nhóm đoạn thẳng
    groups = []
    results = []
    
    for i in range(N):
        current_segment = segments[i]
        merged = False
        
        # Kiểm tra xem đoạn thẳng hiện tại có giao nhau với nhóm nào không
        for j in range(len(groups)):
            group = groups[j]
            # Kiểm tra giao nhau
            if any(seg.l <= current_segment.r and seg.r >= current_segment.l for seg in group):
                group.append(current_segment)
                merged = True
                break
        
        if not merged:
            # Tạo nhóm mới
            groups.append([current_segment])
        
        # Tính tích độ tốt
        total_goodness = 1
        for group in groups:
            total_goodness = (total_goodness * len(group)) % MOD
        
        results.append(total_goodness)

    # Ghi kết quả ra tệp
    with open('DOANTOT.OUT', 'w') as f:
        for res in results:
            f.write(str(res) + '\n')


if __name__ == "__main__":
    main()
