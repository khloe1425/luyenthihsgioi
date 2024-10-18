def read_data(filename):
    try:
        with open(filename, 'r') as file:
            first_line = file.readline().strip()
            if not first_line:
                raise ValueError("Dòng đầu tiên rỗng, không đủ dữ liệu.")
            n, m, p = map(int, first_line.split())
            
            a = list(map(int, file.readline().strip().split()))
            b = list(map(int, file.readline().strip().split()))
            c = list(map(int, file.readline().strip().split()))
            
            return a, b, c
    except FileNotFoundError:
        print(f"Lỗi: Tệp {filename} không tìm thấy.")
        raise
    except ValueError as e:
        print(f"Lỗi dữ liệu: {e}")
        raise

def min_brightness_difference(a, b, c):
    a.sort()
    b.sort()
    c.sort()
    
    min_diff = float('inf')
    
    i, j, k = 0, 0, 0
    while i < len(a) and j < len(b) and k < len(c):
        ai = a[i]
        bj = b[j]
        ck = c[k]
        
        # Tính chênh lệch
        diff = (ai - bj) ** 2 + (bj - ck) ** 2 + (ck - ai) ** 2
        
        # Cập nhật min_diff
        min_diff = min(min_diff, diff)
        
        # Tìm viên bi có độ sáng thấp nhất để tăng lên
        if min(ai, bj, ck) == ai:
            i += 1
        elif min(ai, bj, ck) == bj:
            j += 1
        else:
            k += 1
            
    return min_diff

def write_result(filename, result):
    with open(filename, 'w') as file:
        file.write(str(result) + '\n')

# Hàm chính
def main():
    try:
        a, b, c = read_data('MARBLES.INP')
        result = min_brightness_difference(a, b, c)
        write_result('MARBLES.OUT', result)
    except Exception as e:
        print(f"Có lỗi xảy ra: {e}")

if __name__ == '__main__':
    main()