def decode_message(message, k):
    decoded = ""
    for char in message:
        if 'A' <= char <= 'Z':  # Xử lý chữ cái in hoa
            decoded += chr(((ord(char) - ord('A') - k) % 26) + ord('A'))
        elif 'a' <= char <= 'z':  # Xử lý chữ cái in thường
            decoded += chr(((ord(char) - ord('a') - k) % 26) + ord('a'))
        else:
            decoded += char  # Không thay đổi các ký tự không phải là chữ cái
    return decoded

def find_longest_message(s, k):
    messages = s.split('#')  # Tách chuỗi theo dấu #
    message_count = 0
    longest_message = ""
    
    for message in messages:
        # Chỉ tính các tin nhắn có ít nhất một ký tự chữ cái là một tin nhắn hợp lệ
        if any(char.isalpha() for char in message):
            message_count += 1
            # Tìm tin nhắn có độ dài lớn nhất
            if len(message) > len(longest_message):
                longest_message = message
    
    # Giải mã tin nhắn có độ dài lớn nhất
    decoded_message = decode_message(longest_message, k)
    
    return message_count, decoded_message

def main():
    # Nhập chuỗi và độ lệch k
    s = input("Nhập vào xâu S: ")
    k = int(input("Nhập vào số nguyên dương k: "))
    
    # Tìm tin nhắn dài nhất và giải mã
    message_count, decoded_message = find_longest_message(s, k)
    
    # Xuất kết quả
    print(message_count)
    print(decoded_message)

if __name__ == "__main__":
    main()
