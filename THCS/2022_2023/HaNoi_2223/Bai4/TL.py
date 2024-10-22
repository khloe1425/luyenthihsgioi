def max_profit(n, paintings):
    # Sắp xếp các bức tranh theo kích thước
    paintings.sort(key=lambda x: x[0])  # Sắp xếp theo kích thước

    max_H = float('-inf')  # Khởi tạo giá trị H lớn nhất
    left = 0  # Chỉ số bên trái
    current_sum = 0  # Tổng giá trị hiện tại

    for right in range(n):
        current_sum += paintings[right][1]  # Thêm giá trị của bức tranh bên phải
        
        # Kiểm tra tất cả các khoảng từ left đến right
        while left <= right:
            Amin = paintings[left][0]  # Kích thước nhỏ nhất
            Amax = paintings[right][0]  # Kích thước lớn nhất
            H = current_sum - (Amax - Amin)  # Tính lợi nhuận
            
            max_H = max(max_H, H)  # Cập nhật H lớn nhất
            
            # Nếu kích thước hiện tại đã đủ điều kiện, thì có thể tăng left
            if left < right:  
                current_sum -= paintings[left][1]  # Bớt giá trị bức tranh bên trái
                left += 1  # Di chuyển bên trái
            else:
                break  # Nếu left == right thì không thể tiếp tục

    return max_H

def main():
    # Đọc dữ liệu từ tệp
    with open("TL.INP", "r") as inp:
        n = int(inp.readline().strip())
        paintings = [tuple(map(int, inp.readline().strip().split())) for _ in range(n)]
    
    result = max_profit(n, paintings)

    # Ghi kết quả ra tệp
    with open("TL.OUT", "w") as out:
        out.write(str(result) + "\n")

if __name__ == "__main__":
    main()
