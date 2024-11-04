import math

inp_file_name = "CAU01"

def main():
    if inp_file_name != "":
        s = inp_file_name + ".INP"
        freopen_in = open(s, "r")
        s = inp_file_name + ".OUT"
        freopen_out = open(s, "w")

    # Đọc input từ file
    n = int(freopen_in.readline().strip())
    a = [0] * (n + 1) 

    # Tính toán t giá trị
    for i in range(1, n + 1):
        t = 1
        c = int(math.sqrt(i))
        for j in range(2, c + 1):
            if i % j == 0:
                t += j
                if j != i // j:
                    t += i // j
        if i > 1:
            t += i
        a[i] = t

    # Đếm số cặp
    d = 0
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            if (a[i] == j) or (a[j] == i):
                d += 1

    # In kết quả ra file .out
    print(d, file=freopen_out)

    # Đóng file sau khi hoàn thành
    freopen_in.close()
    freopen_out.close()

if __name__ == "__main__":
    main()
