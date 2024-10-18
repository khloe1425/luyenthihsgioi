input_path = "./THU.INP"
output_path = "./THU.OUT"

def decode_message(input_file, output_file):
    with open(input_file, 'r') as infile:
        n = int(infile.readline().strip())  # Đọc độ dài n
        coded_message = infile.readline().strip()  # Đọc nội dung mã hóa

    decoded_words = []
    i = 0
    
    while i < len(coded_message):
        if coded_message[i] in '12':  # Kiểm tra ký tự đầu tiên của từ
            number = coded_message[i]
            i += 1
            word_start = i
            
            # Tìm đến vị trí từ kết thúc
            while i < len(coded_message) and coded_message[i] not in '12':
                i += 1
            
            word = coded_message[word_start:i]  # Từ được mã hóa
            if number == '2':
                word = word[::-1]  # Đảo ngược từ nếu đầu là '2'
                
            decoded_words.append(word)  # Thêm từ vào danh sách

    with open(output_file, 'w') as outfile:
        outfile.write(' '.join(decoded_words) + '\n')

decode_message(input_path, output_path)
