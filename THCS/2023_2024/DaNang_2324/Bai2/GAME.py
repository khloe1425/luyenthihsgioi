input_path = "./GAME.INP"
output_path = "./GAME.OUT"

def count_candies(input_file, output_file):
    with open(input_file, 'r') as infile:
        results = infile.read().strip()

    # Khởi tạo số kẹo cho Đức và Nhi
    candies_Duc = 0
    candies_Nhi = 0

    # Đếm số kết quả
    for result in results:
        if result == 'D':
            candies_Duc += 1
        elif result == 'N':
            candies_Nhi += 1
        # 'H' không cần xử lý vì không ai thắng

    # Ghi kết quả vào tệp
    with open(output_file, 'w') as outfile:
        outfile.write(f"{candies_Duc} {candies_Nhi}\n")

count_candies(input_path, output_path)
