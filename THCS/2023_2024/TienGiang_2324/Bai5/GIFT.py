def longest_increasing_subsequence(values):
    max_length = 0
    current_length = 1

    for i in range(1, len(values)):
        if values[i] > values[i - 1]:  # Kiểm tra nếu giá trị tăng
            current_length += 1
        else:
            max_length = max(max_length, current_length)  # Cập nhật độ dài lớn nhất
            current_length = 1  # Reset độ dài hiện tại
    
    # Cập nhật một lần nữa để xem chuỗi cuối có phải là dài nhất không
    max_length = max(max_length, current_length)

    return max_length

def main():
    with open("GIFT.INP", "r") as infile:
        lines = infile.readlines()  # Đọc tất cả các dòng từ file

    results = []
    for line in lines:
        # Chuyển các số trong dòng thành danh sách số nguyên
        values = list(map(int, line.strip().split()))
        result = longest_increasing_subsequence(values)
        results.append(result)

    # Ghi kết quả vào file
    with open("GIFT.OUT", "w") as outfile:
        for res in results:
            outfile.write(f"{res}\n")

if __name__ == "__main__":
    main()
