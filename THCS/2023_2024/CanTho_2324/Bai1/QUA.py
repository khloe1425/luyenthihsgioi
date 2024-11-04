input_path = "./QUA.INP"
output_path = "./QUA.OUT"

def select_gifts(input_file, output_file):
    with open(input_file, 'r') as infile:
        # Đọc n và k
        n, k = map(int, infile.readline().strip().split())

        # Đọc giá trị của từng phần quà
        values = list(map(int, infile.readline().strip().split()))

    # Sắp xếp giá trị quà theo thứ tự giảm dần
    values.sort(reverse=True)

    # Tính tổng giá trị lớn nhất của k phần quà
    max_value = sum(values[:k])

    # Ghi kết quả vào tệp
    with open(output_file, 'w') as outfile:
        outfile.write(f"{max_value}\n")

select_gifts(input_path, output_path)
