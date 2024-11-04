def count_zero_sum_subarrays(arr):
    # Tạo một dictionary để lưu trữ tổng và số lần xuất hiện của tổng
    prefix_sum_counts = {}
    prefix_sum_counts[0] = 1  # Để xử lý trường hợp tổng bằng 0 từ đầu dãy
    current_sum = 0
    count = 0

    for number in arr:
        current_sum += number
        # Nếu tổng đã xuất hiện trước đó, nghĩa là có đoạn con tổng bằng 0
        if current_sum in prefix_sum_counts:
            count += prefix_sum_counts[current_sum]
            prefix_sum_counts[current_sum] += 1
        else:
            prefix_sum_counts[current_sum] = 1

    return count

def main():
    # Đọc dữ liệu từ file
    with open("TONG.INP", "r") as infile:
        n = int(infile.readline().strip())
        arr = list(map(int, infile.readline().strip().split()))

    # Tính số đoạn con có tổng bằng 0
    result = count_zero_sum_subarrays(arr)

    # Ghi kết quả vào file
    with open("TONG.OUT", "w") as outfile:
        outfile.write(f"{result}\n")

if __name__ == "__main__":
    main()
