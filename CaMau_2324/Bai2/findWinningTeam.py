input_path = './THCS/2024/CaMau/Bai2/trochoi.inp'
output_path = './THCS/2024/CaMau/Bai2/trochoi.out'

def find_winning_team(input_file, output_file):
    with open(input_file, 'r') as f:
        # Đọc m và n
        m, n = map(int, f.readline().strip().split())
        
        # Danh sách để lưu tổng điểm của từng đội
        scores = [0] * n
        
        # Đọc điểm của từng đội cho mỗi câu hỏi
        for _ in range(m):
            points = list(map(int, f.readline().strip().split()))
            for j in range(n):
                scores[j] += points[j]  # Cộng điểm cho từng đội

    # Tìm đội có tổng điểm cao nhất
    max_score = max(scores)
    winning_team_index = scores.index(max_score) + 1  # Thêm 1 để có thứ tự bắt đầu từ 1

    with open(output_file, 'w') as f:
        f.write(f"{winning_team_index} {max_score}\n")


find_winning_team(input_path, output_path)
