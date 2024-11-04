input_path = './demkitu.inp'
output_path = './demkitu.out'

def count_characters(input_file, output_file):
    # Đọc xâu từ tệp tin
    with open(input_file, 'r') as f:
        S = f.read().strip()  # Đọc xâu và loại bỏ ký tự trắng ở đầu/cuối

    # Mảng để đếm số lần xuất hiện của các ký tự
    count = [0] * 26  # 26 ký tự từ 'a' đến 'z'

    # Đếm số lần xuất hiện của mỗi ký tự
    for char in S:
        count[ord(char) - ord('a')] += 1

    # Ghi kết quả vào tệp tin
    with open(output_file, 'w') as f:
        for i in range(26):
            if count[i] > 0:  # Chỉ ghi các ký tự xuất hiện ít nhất 1 lần
                f.write(f"{chr(i + ord('a'))} {count[i]}\n")


count_characters(input_path, output_path)
