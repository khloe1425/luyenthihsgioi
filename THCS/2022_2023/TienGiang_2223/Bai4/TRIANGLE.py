import math

def read_input(file_path):
    with open(file_path, 'r') as infile:
        n = int(infile.readline().strip())
        lengths = list(map(int, infile.readline().strip().split()))
    return n, lengths

def is_triangle(a, b, c):
    return (a + b > c) and (a + c > b) and (b + c > a)

def triangle_area(a, b, c):
    p = (a + b + c) / 2  # Nửa chu vi
    return math.sqrt(p * (p - a) * (p - b) * (p - c))

def count_triangles_and_max_area(n, lengths):
    triangle_count = 0
    max_area = -1.0  # Khởi tạo max_area với giá trị không hợp lệ
    # Duyệt qua tất cả các bộ ba que tính
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                a = lengths[i]
                b = lengths[j]
                c = lengths[k]
                if is_triangle(a, b, c):
                    triangle_count += 1
                    area = triangle_area(a, b, c)
                    if area > max_area:
                        max_area = area
    return triangle_count, max_area

def write_output(file_path, triangle_count, max_area):
    with open(file_path, 'w') as outfile:
        outfile.write(f"{triangle_count}\n")
        if triangle_count > 0:
            outfile.write(f"{max_area:.2f}\n")
        else:
            outfile.write("-1\n")

def main():
    input_file = "TRIANGLE.INP"
    output_file = "TRIANGLE.OUT"

    n, lengths = read_input(input_file)
    triangle_count, max_area = count_triangles_and_max_area(n, lengths)
    write_output(output_file, triangle_count, max_area)

if __name__ == "__main__":
    main()
