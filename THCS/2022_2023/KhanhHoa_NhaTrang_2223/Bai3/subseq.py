def max_subarray(arr):
    """Hàm tìm dãy con có tổng lớn nhất và vị trí của nó."""
    max_sum = float('-inf')  # Khởi tạo tổng lớn nhất
    current_sum = 0
    start = 0
    best_start = 0
    best_end = 0

    for i in range(len(arr)):
        current_sum += arr[i]
        
        if current_sum > max_sum:
            max_sum = current_sum
            best_start = start
            best_end = i
        
        if current_sum < 0:
            current_sum = 0
            start = i + 1  # Bắt đầu dãy con mới từ phần tử tiếp theo

    return best_start, best_end, max_sum

def main():
    # Đọc dữ liệu từ file
    with open("subseq.inp", "r") as f:
        n = int(f.readline().strip())
        arr = [int(f.readline().strip()) for _ in range(n)]

    # Tìm dãy con có tổng lớn nhất
    start_index, end_index, max_sum = max_subarray(arr)

    # Ghi kết quả vào file
    with open("subseq.out", "w") as f:
        f.write(f"{start_index + 1}\n")  # Chuyển đổi chỉ số thành 1-based
        f.write(f"{end_index + 1}\n")    # Chuyển đổi chỉ số thành 1-based
        f.write(f"{max_sum}\n")

if __name__ == "__main__":
    main()
