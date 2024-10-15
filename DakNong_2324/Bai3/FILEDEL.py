def main():
    with open("FILEDEL.INP", "r") as inputFile:
        # Đọc số lượng tệp tin và số thao tác xóa
        n, q = map(int, inputFile.readline().split())
        
        # Đọc tên các tệp tin
        files = [inputFile.readline().strip() for _ in range(n)]
        
        # Đọc các ký tự để xóa
        delete_chars = [inputFile.readline().strip() for _ in range(q)]
    
    deleted_chars = set()
    remaining_files = []
    
    # Xử lý từng thao tác xóa
    for delete_char in delete_chars:
        deleted_chars.add(delete_char)
        count = 0
        
        # Kiểm tra từng tệp tin
        for file in files:
            to_delete = False
            
            # Kiểm tra xem có ký tự nào trong tệp tin thuộc tập deleted_chars
            for ch in file:
                if ch in deleted_chars:
                    to_delete = True
                    break
            
            # Nếu tệp tin không chứa ký tự nào cần xóa, đếm lại
            if not to_delete:
                count += 1
        
        # Lưu số lượng tệp tin còn lại sau mỗi thao tác xóa
        remaining_files.append(count)
    
    # Ghi kết quả vào file
    with open("FILEDEL.OUT", "w") as outputFile:
        for count in remaining_files:
            outputFile.write(f"{count}\n")

if __name__ == "__main__":
    main()