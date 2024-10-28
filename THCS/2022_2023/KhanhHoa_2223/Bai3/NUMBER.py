def find_kth_digit(K):
    digit_length = 1  # Độ dài chữ số (1 cho 1-9, 2 cho 10-99, ...)
    count_of_numbers = 9  # Số lượng số có độ dài `digit_length`
    start_number = 1  # Số bắt đầu cho mỗi độ dài

    # Tìm khoảng độ dài chữ số cho K
    while K > digit_length * count_of_numbers:
        K -= digit_length * count_of_numbers
        digit_length += 1
        count_of_numbers *= 10
        start_number *= 10

    # Xác định số mà chữ số thứ K nằm trong đó
    number_index = (K - 1) // digit_length  # Tính chỉ số số
    digit_index = (K - 1) % digit_length  # Tính chỉ số chữ số trong số

    actual_number = start_number + number_index  # Số thực tế
    # Chuyển đổi số thành chuỗi để lấy chữ số cụ thể
    return str(actual_number)[digit_index]

# Đọc dữ liệu từ tệp NUMBER.INP
with open("NUMBER.INP", "r") as input_file:
    K = int(input_file.readline().strip())

# Tìm chữ số thứ K
result_digit = find_kth_digit(K)

# Ghi kết quả ra tệp NUMBER.OUT
with open("NUMBER.OUT", "w") as output_file:
    output_file.write(result_digit)
