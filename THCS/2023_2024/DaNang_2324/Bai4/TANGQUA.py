input_path = "./TANGQUA.INP"
output_path = "./TANGQUA.OUT"
def longest_increasing_subsequence(sequence):
    from bisect import bisect_left

    lis = []
    for value in sequence:
        pos = bisect_left(lis, value)
        if pos == len(lis):
            lis.append(value)
        else:
            lis[pos] = value
    return len(lis)

def main():
    with open(input_path, "r") as infile:
        n = int(infile.readline().strip())
        values = list(map(int, infile.readline().strip().split()))
    
    lis_length = longest_increasing_subsequence(values)
    result = n - lis_length
    
    with open(output_path, "w") as outfile:
        outfile.write(str(result) + "\n")

if __name__ == "__main__":
    main()
