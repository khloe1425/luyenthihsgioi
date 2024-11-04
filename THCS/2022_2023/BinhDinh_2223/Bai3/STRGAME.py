def solve_string_game(N, K, s):
    # Sắp xếp xâu ký tự
    sorted_s = sorted(s)

    # Nếu K = 1, kết quả là toàn bộ xâu sau khi sắp xếp
    if K == 1:
        return ''.join(sorted_s)

    # Nếu ký tự đầu tiên sau khi sắp xếp khác ký tự K-th, kết quả là ký tự K-th
    if sorted_s[0] != sorted_s[K - 1]:
        return sorted_s[K - 1]
    
    # Nếu không, bắt đầu từ ký tự đầu tiên đến hết phần còn lại
    result = sorted_s[0]
    rest = sorted_s[K:]
    
    # Chia xâu còn lại thành các đoạn lớn nhất
    if len(set(rest)) == 1:
        # Nếu các ký tự còn lại đều giống nhau
        result += ''.join(rest[::K])
    else:
        result += ''.join(rest)
    
    return result

# Đọc dữ liệu từ file STRGAME.INP
with open('STRGAME.INP', 'r') as inp:
    N, K = map(int, inp.readline().split())
    s = inp.readline().strip()

# Giải bài toán
result = solve_string_game(N, K, s)

# Ghi kết quả ra file STRGAME.OUT
with open('STRGAME.OUT', 'w') as out:
    out.write(result + '\n')
