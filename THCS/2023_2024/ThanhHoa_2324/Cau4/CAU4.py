def count_parallel_lines(filename_input, filename_output):
    with open(filename_input, 'r') as f:
        n = int(f.readline().strip())
        slopes_count = {}
        
        for _ in range(n):
            b, a = map(int, f.readline().strip().split())
            print(f"Slope a_i: {a}")  # In ra hệ số góc
            if a in slopes_count:
                slopes_count[a] += 1
            else:
                slopes_count[a] = 1

    total_pairs = 0
    for count in slopes_count.values():
        if count > 1:
            total_pairs += (count * (count - 1)) // 2

    with open(filename_output, 'w') as f:
        f.write(str(total_pairs) + '\n')

# Sử dụng hàm
count_parallel_lines('CAU4.INP', 'CAU4.OUT')
