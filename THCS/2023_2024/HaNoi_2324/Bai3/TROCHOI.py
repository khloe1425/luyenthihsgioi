import heapq

def main():
    # Đọc dữ liệu
    with open('TROCHOI.INP', 'r') as f:
        N, M = map(int, f.readline().strip().split())
        skills = []
        for _ in range(N):
            si, ei = map(int, f.readline().strip().split())
            skills.append((si, ei))
    
    # Tính sức mạnh tối đa
    max_power = 0
    max_heap = []
    
    # Thêm tất cả các kĩ năng vào heap
    for si, ei in skills:
        # Lần đầu tăng cấp
        heapq.heappush(max_heap, (-(si + ei), ei))
    
    # Nâng cấp trong M phút
    for _ in range(M):
        if max_heap:
            # Lấy kĩ năng có sức mạnh tối đa
            max_power += -max_heap[0][0]  # Thêm sức mạnh vào kết quả
            # Lần tăng cấp tiếp theo
            next_power = max_heap[0][1]  # Chỉ số sức mạnh cho lần sau
            heapq.heappop(max_heap)  # Xóa kĩ năng này
            heapq.heappush(max_heap, (-next_power, next_power))  # Thêm lại với chỉ số mới
    
    # Ghi kết quả ra tệp
    with open('TROCHOI.OUT', 'w') as f:
        f.write(str(max_power) + '\n')

if __name__ == "__main__":
    main()
