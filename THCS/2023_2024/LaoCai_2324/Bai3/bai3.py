inp_file_name = "bai3"

def main():
    if inp_file_name != "":
        s = inp_file_name + ".inp"
        freopen_in = open(s, "r")
        s = inp_file_name + ".out"
        freopen_out = open(s, "w")

    # Đọc dòng đầu tiên chứa n và k
    n, k = map(int, freopen_in.readline().split())
    a = []

    # Đọc tiếp các số hạng từ file, lưu vào danh sách
    numbers = list(map(int, freopen_in.readline().split()))  # Đọc tất cả các số từ dòng này

    for i in range(n):
        a.append((numbers[i], i))  # Lưu giá trị và index vào danh sách

    ans = a[0][0]  # a[0][0] là giá trị của số hạng đầu tiên

    # a[i][1] = i, mục đích để giữ lại index ban đầu của số hạng
    a.sort(reverse=True, key=lambda x: x[0])  # Sắp xếp theo giá trị giảm dần

    i = 0
    while k > 0:
        if a[i][1] != 0:
            ans += a[i][0]  # Bỏ qua phần tử đầu tiên
        else:
            k += 1
        i += 1
        k -= 1

    while i < n:
        if a[i][1] != 0:
            ans -= a[i][0]  # Bỏ qua phần tử đầu tiên
        i += 1

    print(ans, file=freopen_out)

    # Đóng file sau khi hoàn thành
    freopen_in.close()
    freopen_out.close()

if __name__ == "__main__":
    main()
