def check_triangle_type(a, b, c):
    # Kiểm tra tổng ba góc có bằng 180 không và các góc có lớn hơn 0 không
    if a + b + c != 180 or a <= 0 or b <= 0 or c <= 0:
        return 0  # Không phải là số đo của tam giác
    else:
        # Xác định loại tam giác
        if a < 90 and b < 90 and c < 90:
            return "NHON"  # Tam giác nhọn
        elif a == 90 or b == 90 or c == 90:
            return "VUONG"  # Tam giác vuông
        else:
            return "TU"  # Tam giác tù

def main():
    # Đọc dữ liệu từ file
    with open("TAMGIAC.INP", "r") as infile:
        T = int(infile.readline().strip())  # Số bộ test

        results = []
        for _ in range(T):
            a, b, c = map(int, infile.readline().strip().split())  # Đọc ba số góc
            result = check_triangle_type(a, b, c)
            results.append(result)

    # Ghi kết quả vào file
    with open("TAMGIAC.OUT", "w") as outfile:
        for result in results:
            outfile.write(str(result) + "\n")

if __name__ == "__main__":
    main()
