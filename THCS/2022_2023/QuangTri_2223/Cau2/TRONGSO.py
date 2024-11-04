def calculate_weight(s):
    # Lấy ra tất cả các chữ số trong xâu và tính trung bình cộng
    digits = [int(char) for char in s if char.isdigit()]
    if digits:
        return sum(digits) / len(digits)  # Trung bình cộng
    else:
        return 0  # Không có chữ số, trọng số là 0

def main():
    # Đọc dữ liệu từ file
    with open("TRONGSO.INP", "r") as infile:
        N = int(infile.readline().strip())
        strings = [infile.readline().strip() for _ in range(N)]

    max_weight = -1
    result_string = "0"  # Giá trị mặc định nếu không tìm thấy

    for s in strings:
        weight = calculate_weight(s)
        if weight > max_weight:
            max_weight = weight
            result_string = s

    # Ghi kết quả vào file
    with open("TRONGSO.OUT", "w") as outfile:
        outfile.write(result_string + "\n")

if __name__ == "__main__":
    main()
