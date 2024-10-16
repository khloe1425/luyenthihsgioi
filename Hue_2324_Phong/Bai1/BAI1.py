def chia_het_hoan_toan(num):
    num_str = str(num)
    for digit in num_str:
        if digit == '0' or num % int(digit) != 0:
            return False
    return True

def dem_so_chia_het_hoan_toan(arr):
    ket_qua = [num for num in arr if chia_het_hoan_toan(num)]
    return len(ket_qua), ket_qua

# Đọc dữ liệu từ file
with open('SOCHIAHET.INP', 'r') as f:
    n = int(f.readline().strip())
    arr = list(map(int, f.readline().strip().split()))

# Tính toán
count, result_list = dem_so_chia_het_hoan_toan(arr)

# Ghi kết quả ra file
with open('SOCHIAHET.OUT', 'w') as f:
    f.write(f"{count}\n")
    f.write(" ".join(map(str, result_list)))
