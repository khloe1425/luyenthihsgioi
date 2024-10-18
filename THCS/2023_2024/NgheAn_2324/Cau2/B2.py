from itertools import combinations

# Đọc dữ liệu từ tệp B2.INP
with open("B2.INP", "r") as file:
    t = int(file.readline().strip())
    tests = [file.readline().strip().split() for _ in range(t)]

# Hàm để kiểm tra số có chia hết cho 5
def divisible_by_5(number_str):
    return int(number_str) % 5 == 0

# Hàm để kiểm tra số có chia hết cho 3
def divisible_by_3(number_str):
    return int(number_str) % 3 == 0

results = []
for number_str, flag in tests:
    n = len(number_str)
    best_number = '-1'  # Khởi tạo với giá trị rất nhỏ
    
    # Tạo các chuỗi con theo thứ tự từ lớn nhất đến nhỏ nhất
    for length in range(n, 0, -1):
        # Tạo tất cả các tổ hợp có độ dài là 'length'
        for combo in combinations(number_str, length):
            sub_number = ''.join(combo)
            if flag == '0' and divisible_by_5(sub_number):
                # Chia hết cho 5
                if best_number == '-1' or int(sub_number) > int(best_number):
                    best_number = sub_number
            elif flag == '1' and divisible_by_3(sub_number):
                # Chia hết cho 3
                if best_number == '-1' or int(sub_number) > int(best_number):
                    best_number = sub_number
        if best_number != '-1':  # Nếu tìm thấy kết quả
            break
    
    results.append(best_number)

# Ghi kết quả vào tệp B2.OUT
with open("B2.OUT", "w") as file:
    for result in results:
        file.write(result + "\n")
