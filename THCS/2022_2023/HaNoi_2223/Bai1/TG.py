def main():
    # Đọc dữ liệu từ tệp TG.INP
    with open("TG.INP", "r") as input_file:
        N = int(input_file.readline().strip())  # Số lượng thí sinh
        times = [int(input_file.readline().strip()) for _ in range(N)]  # Thời gian hoàn thành của từng thí sinh

    # Thời gian bắt đầu là 8 giờ 00 phút
    start_hour = 8
    start_minute = 0

    # Danh sách để lưu thời gian kết thúc
    end_times = []

    for Ti in times:
        # Tính thời gian kết thúc
        end_minute = start_minute + Ti  # Tính phút kết thúc
        end_hour = start_hour + end_minute // 60  # Tính giờ kết thúc
        end_minute = end_minute % 60  # Tính phút còn lại sau khi chia cho 60

        # Định dạng thời gian
        end_time = f"{end_hour:02}:{end_minute:02}"
        end_times.append(end_time)

    # Ghi kết quả ra tệp TG.OUT
    with open("TG.OUT", "w") as output_file:
        for end_time in end_times:
            output_file.write(end_time + "\n")

if __name__ == "__main__":
    main()
