def min_parking_spaces(arrival, departure):
    # Sắp xếp thời gian đến và thời gian rời bến
    arrival.sort()
    departure.sort()

    # Biến đếm số chỗ đỗ xe hiện tại và tối đa
    spaces_needed = 0
    max_spaces = 0

    # Chỉ số cho thời gian đến và đi
    i, j = 0, 0
    n = len(arrival)

    # Duyệt qua tất cả các xe
    while i < n and j < n:
        if arrival[i] < departure[j]:
            # Nếu có xe đến trước khi xe rời đi, tăng số chỗ đỗ cần thiết
            spaces_needed += 1
            max_spaces = max(max_spaces, spaces_needed)
            i += 1
        else:
            # Nếu có xe rời đi, giảm số chỗ đỗ cần thiết
            spaces_needed -= 1
            j += 1

    return max_spaces

def main():
    with open("MINPLACES.INP", "r") as input_file:
        # Đọc số bộ dữ liệu
        T = int(input_file.readline().strip())
        results = []

        for _ in range(T):
            # Đọc số xe trong bộ dữ liệu
            N = int(input_file.readline().strip())

            # Đọc danh sách thời gian đến và rời bến
            arrival = list(map(int, input_file.readline().strip().split()))
            departure = list(map(int, input_file.readline().strip().split()))

            # Tính số chỗ đỗ xe tối thiểu cho bộ dữ liệu này
            result = min_parking_spaces(arrival, departure)
            results.append(result)

    # Ghi kết quả ra file MINPLACES.OUT
    with open("MINPLACES.OUT", "w") as output_file:
        for result in results:
            output_file.write(f"{result}\n")

if __name__ == "__main__":
    main()
