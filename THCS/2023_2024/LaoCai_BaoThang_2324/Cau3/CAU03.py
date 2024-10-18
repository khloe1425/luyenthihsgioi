def can_win(your_army, enemy_army):
    # Sắp xếp sức mạnh của cả hai đội quân
    your_army.sort()
    enemy_army.sort()

    # Kiểm tra điều kiện thắng
    for i in range(len(your_army)):
        if your_army[i] <= enemy_army[i]:
            return False
    return True

def main():
    with open("CAU03.INP", "r") as infile:
        N = int(infile.readline().strip())  # Đọc số chiến binh

        your_army = list(map(int, infile.readline().strip().split()))  # Đọc sức mạnh quân đội bạn
        enemy_army = list(map(int, infile.readline().strip().split()))  # Đọc sức mạnh quân đội đối phương

    # Kiểm tra khả năng thắng
    result = "Yes" if can_win(your_army, enemy_army) else "No"

    # Ghi kết quả ra tệp
    with open("CAU03.OUT", "w") as outfile:
        outfile.write(result + "\n")

if __name__ == "__main__":
    main()
