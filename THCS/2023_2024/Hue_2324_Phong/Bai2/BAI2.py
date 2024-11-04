# Đọc dữ liệu từ file CHECK.INP
with open("CHECK.INP", "r") as infile:
    # Đọc số lượng hành khách
    N = int(infile.readline().strip())

    # Mở file để ghi kết quả
    with open("CHECK1.OUT", "w") as outfile1, open("CHECK2.OUT", "w") as outfile2:
        # Duyệt qua từng hành khách
        for i in range(1, N + 1):
            # Đọc các kiện hàng của hành khách
            line = infile.readline().strip()
            weights = list(map(float, line.split()))
            
            # Tính tổng trọng lượng và số lượng kiện hàng
            total_weight = sum(weights)
            item_count = len(weights)
            
            # Ghi tổng số cân nặng vào CHECK1.OUT, định dạng để không có .0 nếu là số nguyên
            if total_weight.is_integer():
                outfile1.write(f"{int(total_weight)}\n")
            else:
                outfile1.write(f"{total_weight}\n")
            
            # Kiểm tra điều kiện và ghi vào CHECK2.OUT nếu không đạt yêu cầu
            if total_weight > 20 or item_count > 10:
                outfile2.write(f"{i}\n")
