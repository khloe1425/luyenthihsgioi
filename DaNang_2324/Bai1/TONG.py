input_path = "./THCS/2024/DaNang/Bai1/TONG.INP"
output_path = "./THCS/2024/DaNang/Bai1/TONG.OUT"

def calculate_sum_of_largest(input_file, output_file):
    with open(input_file, 'r') as infile:
        # Đọc N và K
        N, K = map(int, infile.readline().strip().split())
        
        # Đọc dãy số
        numbers = list(map(int, infile.readline().strip().split()))

    # Sắp xếp dãy số theo thứ tự giảm dần và tính tổng K phần tử lớn nhất
    largest_sum = sum(sorted(numbers, reverse=True)[:K])

    # Ghi kết quả vào tệp
    with open(output_file, 'w') as outfile:
        outfile.write(f"{largest_sum}\n")

calculate_sum_of_largest(input_path, output_path)
