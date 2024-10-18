def calculate_strength(s):
    # Tạo một từ điển để đếm số lần xuất hiện của từng ký tự
    count_dict = {}
    for char in s:
        if char in count_dict:
            count_dict[char] += 1
        else:
            count_dict[char] = 1

    # Số ký tự phân biệt
    distinct_count = len(count_dict)
    # Số lần xuất hiện nhiều nhất của một ký tự
    max_count = max(count_dict.values())

    # Tính độ mạnh
    strength = distinct_count * max_count
    return strength

def main():
    # Đọc dữ liệu từ tệp
    with open("STRONG.INP", "r") as input_file:
        s = input_file.readline().strip()  # Đọc xâu từ tệp

    strength = calculate_strength(s)  # Tính độ mạnh của xâu

    # Ghi kết quả vào tệp
    with open("STRONG.OUT", "w") as output_file:
        output_file.write(str(strength) + "\n")

if __name__ == "__main__":
    main()
