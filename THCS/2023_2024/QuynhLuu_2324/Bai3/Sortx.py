def sort_strings(strings):
    # Tách các chuỗi số và chuỗi không phải số
    numeric_strings = [s for s in strings if s.isdigit()]
    non_numeric_strings = [s for s in strings if not s.isdigit()]
    
    # Sắp xếp các chuỗi số
    numeric_strings.sort(key=int)

    # Kết hợp lại danh sách theo thứ tự ban đầu
    result = []
    num_index = 0
    for s in strings:
        if s.isdigit():
            result.append(numeric_strings[num_index])
            num_index += 1
        else:
            result.append(s)
    
    return result

def main():
    # Đọc dữ liệu từ file Sortx.INP
    with open("Sortx.INP", "r") as infile:
        n = int(infile.readline().strip())  # Số lượng chuỗi
        strings = infile.readline().strip().split()  # Danh sách các chuỗi

    # Sắp xếp các chuỗi
    sorted_strings = sort_strings(strings)

    # Ghi kết quả ra file Sortx.OUT
    with open("Sortx.OUT", "w") as outfile:
        outfile.write(" ".join(sorted_strings) + "\n")

if __name__ == "__main__":
    main()
