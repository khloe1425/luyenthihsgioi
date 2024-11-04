from itertools import permutations

def min_fraction_order(a, b, c, d):
    numbers = [a, b, c, d]
    best_order = None
    min_value = float('inf')

    # Duyệt qua tất cả các hoán vị
    for perm in permutations(numbers):
        x, y, z, w = perm
        
        # Tính tổng phân số
        total_value = (x / y) + (z / w)
        
        if total_value < min_value:
            min_value = total_value
            best_order = perm

    return best_order

if __name__ == "__main__":
    # Đọc dữ liệu từ tệp
    with open("frac.inp", "r") as file:
        a, b, c, d = map(int, file.readline().strip().split())

    # Tìm thứ tự tối ưu
    result = min_fraction_order(a, b, c, d)

    # Ghi kết quả ra tệp
    with open("frac.out", "w") as file:
        file.write(" ".join(map(str, result)) + "\n")
