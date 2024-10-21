def can_divide_into_groups(n, acquaintance_matrix):
    group = [-1] * n  # -1: chưa được phân nhóm, 0: nhóm 1, 1: nhóm 2

    def dfs(person, current_group):
        group[person] = current_group
        next_group = 1 - current_group  # Chuyển sang nhóm khác

        for acquaintance in range(n):
            if acquaintance_matrix[person][acquaintance] == 1:
                if group[acquaintance] == -1:  # Nếu chưa được phân nhóm
                    if not dfs(acquaintance, next_group):
                        return False
                elif group[acquaintance] == current_group:  # Nếu cùng nhóm
                    return False
        return True

    for person in range(n):
        if group[person] == -1:  # Nếu chưa được phân nhóm
            if not dfs(person, 0):
                return False, []

    # Tạo danh sách cho từng nhóm
    group1 = [i + 1 for i in range(n) if group[i] == 0]
    group2 = [i + 1 for i in range(n) if group[i] == 1]

    return True, (group1, group2)


# Đọc dữ liệu từ file CHIANHOM.INP
with open("CHIANHOM.INP", "r") as infile:
    n = int(infile.readline().strip())
    acquaintance_matrix = [list(map(int, infile.readline().strip().split())) for _ in range(n)]

# Kiểm tra và lấy kết quả
can_divide, groups = can_divide_into_groups(n, acquaintance_matrix)

# Ghi kết quả ra file CHIANHOM.OUT
with open("CHIANHOM.OUT", "w") as outfile:
    if not can_divide:
        outfile.write("0\n")
    else:
        outfile.write(" ".join(map(str, groups[0])) + "\n")
        outfile.write(" ".join(map(str, groups[1])) + "\n")
