def main():
    # Đọc dữ liệu từ tệp bai3.inp
    try:
        with open("bai3.inp", "r") as infile:
            # Đọc dòng đầu tiên
            first_line = infile.readline().strip()
            n, k = map(int, first_line.split())
            
            # Đọc dòng thứ hai chứa danh sách số
            second_line = infile.readline().strip()
            a = list(map(int, second_line.split()))
        
        # Sắp xếp mảng theo thứ tự giảm dần
        a.sort(reverse=True)

        # Tính tổng k số lớn nhất
        sum_positive = sum(a[:k])
        
        # Tính tổng n-k số còn lại
        sum_negative = sum(a[k:])

        # Kết quả cuối cùng
        result = sum_positive - sum_negative

        # Ghi kết quả vào tệp bai3.out
        with open("bai3.out", "w") as outfile:
            outfile.write(f"{result}\n")

    except Exception as e:
        print(f"Có lỗi xảy ra: {e}")


if __name__ == "__main__":
    main()
