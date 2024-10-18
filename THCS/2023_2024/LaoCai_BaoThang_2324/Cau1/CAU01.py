def sum_of_divisors(n):
    # Tạo một danh sách để lưu tổng ước của từng số từ 1 đến n
    divisors_sum = [0] * (n + 1)
    
    # Tính tổng ước cho từng số
    for i in range(1, n + 1):
        for j in range(i, n + 1, i):
            divisors_sum[j] += i
            
    return divisors_sum

def count_amicable_pairs(n):
    # Tính tổng các ước
    divisors_sum = sum_of_divisors(n)
    
    # Tạo một tập hợp để kiểm tra cặp anh em
    seen = set()
    count = 0
    
    # Đếm cặp anh em
    for a in range(1, n + 1):
        b = divisors_sum[a]
        if b <= n and a != b and (b, a) not in seen and (a, b) not in seen:
            # Kiểm tra điều kiện a, b là anh em
            if divisors_sum[b] == a:
                count += 1
                seen.add((a, b))
    
    return count

# Đọc dữ liệu vào từ file
with open("CAU01.INP", "r") as infile:
    N = int(infile.readline().strip())

# Đếm cặp anh em
result = count_amicable_pairs(N)

# Ghi kết quả ra file
with open("CAU01.OUT", "w") as outfile:
    outfile.write(str(result) + '\n')
