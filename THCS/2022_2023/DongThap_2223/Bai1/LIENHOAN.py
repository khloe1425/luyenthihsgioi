import math

def main():
    # Đọc dữ liệu từ tệp LIENHOAN.INP
    with open("LIENHOAN.INP", "r") as f:
        n, k = map(int, f.readline().strip().split())

    # Tính số mặt cần chiên
    total_faces = 2 * n

    # Tính số lần chiên cần thiết
    batches = math.ceil(total_faces / k)

    # Thời gian tối thiểu
    min_time = batches * 3  # Mỗi lần chiên tốn 3 phút

    # Ghi kết quả vào tệp LIENHOAN.OUT
    with open("LIENHOAN.OUT", "w") as f:
        f.write(str(min_time) + "\n")

if __name__ == "__main__":
    main()
