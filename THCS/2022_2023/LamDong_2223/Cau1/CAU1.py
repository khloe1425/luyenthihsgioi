def calculate_sum(n):
    total_sum = 0
    for i in range(1, n):
        total_sum += i * (i + 1) * (i + 2)
    return total_sum

def main():
    # Đọc dữ liệu từ file
    with open("CAU1.INP", "r") as input_file:
        n = int(input_file.readline().strip())  # Đọc n

    # Tính tổng theo công thức đã cho
    result = calculate_sum(n)

    # Ghi kết quả vào file
    with open("CAU1.OUT", "w") as output_file:
        output_file.write(f"{result}\n")

if __name__ == "__main__":
    main()
