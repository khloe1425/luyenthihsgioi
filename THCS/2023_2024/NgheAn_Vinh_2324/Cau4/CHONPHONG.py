def main():
    # Đọc dữ liệu từ file CHONPHONG.INP
    with open("CHONPHONG.INP", "r") as infile:
        N, K = map(int, infile.readline().split())
        S = infile.readline().strip()

    # Tìm vị trí các phòng trống
    empty_rooms = [i for i in range(N) if S[i] == '0']

    min_distance = N  # Khởi tạo khoảng cách nhỏ nhất có thể

    # Duyệt qua các nhóm phòng trống với kích thước K + 1
    for i in range(len(empty_rooms) - K):
        teacher_room = empty_rooms[i + K // 2]
        max_distance = max(teacher_room - empty_rooms[i], empty_rooms[i + K] - teacher_room)
        min_distance = min(min_distance, max_distance)

    # Ghi kết quả vào file CHONPHONG.OUT
    with open("CHONPHONG.OUT", "w") as outfile:
        outfile.write(f"{min_distance}\n")

if __name__ == "__main__":
    main()
