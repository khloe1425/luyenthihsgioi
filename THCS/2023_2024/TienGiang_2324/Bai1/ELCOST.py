def calculate_electricity_cost(kWh):
    if kWh <= 100:
        return kWh * 2500
    elif kWh <= 200:
        return 100 * 2500 + (kWh - 100) * 3000
    else:
        return 100 * 2500 + 100 * 3000 + (kWh - 200) * 3500

def main():
    # Đọc dữ liệu từ tệp
    with open("ELCOST.INP", "r") as input_file:
        n = int(input_file.readline().strip())  # Số lượng hộ gia đình
        kWh_list = list(map(int, input_file.readline().strip().split()))  # Số Kwh sử dụng

    total_cost = sum(calculate_electricity_cost(kWh) for kWh in kWh_list)  # Tính tổng chi phí

    # Ghi kết quả vào tệp
    with open("ELCOST.OUT", "w") as output_file:
        output_file.write(str(total_cost) + "\n")

if __name__ == "__main__":
    main()
