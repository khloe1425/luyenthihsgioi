def process_queries(n, k, p, array, queries):
    results = []
    
    for query in queries:
        if query == '!':
            # Truy vấn loại 1: Dịch chuyển phần tử cuối về đầu
            last = array[-1]
            for i in range(n - 1, 0, -1):
                array[i] = array[i - 1]
            array[0] = last  # Đặt phần tử cuối vào đầu
        elif query == '?':
            # Truy vấn loại 2: Tìm đoạn con có nhiều 1 nhất
            max_count = 0
            current_count = sum(array[:k])  # Tính số lượng 1 trong đoạn đầu tiên
            max_count = current_count
            
            # Di chuyển đoạn con
            for i in range(k, n):
                current_count += array[i] - array[i - k]  # Cập nhật số lượng 1
                max_count = max(max_count, current_count)
            
            # Lưu kết quả cho truy vấn loại 2
            results.append(max_count)
    
    return results

# Đọc dữ liệu từ file input
with open('query.inp', 'r') as f:
    n, k, p = map(int, f.readline().strip().split())
    array = list(map(int, f.readline().strip().split()))
    queries = f.readline().strip()

# Xử lý truy vấn
results = process_queries(n, k, p, array, queries)

# Ghi kết quả vào file output
with open('query.out', 'w') as f:
    for result in results:
        f.write(str(result) + '\n')
