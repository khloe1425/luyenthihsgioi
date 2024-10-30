def find_best_team(N, K, scores):
    # Biến lưu tổng lớn nhất và chỉ số bắt đầu của đội
    max_sum = -1
    start_index = 0

    # Tính tổng của đội gồm K bạn liên tiếp đầu tiên
    current_sum = sum(scores[:K])
    max_sum = current_sum
    start_index = 0

    # Duyệt qua các đoạn con K phần tử tiếp theo
    for i in range(K, N):
        current_sum = current_sum - scores[i - K] + scores[i]
        if current_sum > max_sum or (current_sum == max_sum and i > start_index + K - 1):
            max_sum = current_sum
            start_index = i - K + 1

    # Trả về tổng lớn nhất và đội gồm K bạn
    return max_sum, [i + 1 for i in range(start_index, start_index + K)]

# Đọc dữ liệu từ file BAI4.INP
with open('BAI4.INP', 'r') as inp_file:
    # Dòng đầu tiên: N và K
    N, K = map(int, inp_file.readline().split())

    # Dòng thứ hai: số câu trả lời đúng của từng bạn đoàn viên
    scores = list(map(int, inp_file.readline().split()))

# Tìm đội có tổng số câu trả lời đúng nhiều nhất
max_sum, best_team = find_best_team(N, K, scores)

# Ghi kết quả vào file BAI4.OUT
with open('BAI4.OUT', 'w') as out_file:
    out_file.write(f"{max_sum}\n")
    out_file.write(" ".join(map(str, best_team)) + "\n")
