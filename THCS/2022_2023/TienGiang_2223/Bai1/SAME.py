def max_frequency(input_file, output_file):
    with open(input_file, 'r') as infile:
        n = int(infile.readline().strip())  # Đọc số lượng cây
        heights = list(map(int, infile.readline().strip().split()))  # Đọc chiều cao của các cây

    frequency = {}

    # Đếm tần số xuất hiện của từng chiều cao
    for height in heights:
        if height in frequency:
            frequency[height] += 1
        else:
            frequency[height] = 1

    # Tìm tần số lớn nhất
    max_freq = max(frequency.values()) if frequency else 0

    # Ghi kết quả vào tệp
    with open(output_file, 'w') as outfile:
        outfile.write(str(max_freq) + '\n')

# Gọi hàm với tên tệp đầu vào và đầu ra
max_frequency("SAME.INP", "SAME.OUT")
