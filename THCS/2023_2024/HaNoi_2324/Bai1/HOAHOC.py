def main():
    try:
        # Đọc dữ liệu từ tệp HOAHOC.INP
        with open('HOAHOC.INP', 'r') as infile:
            data = infile.read().strip()
            if not data:
                raise ValueError("Tệp HOAHOC.INP không có dữ liệu.")
            A, B = map(int, data.split())
        
        # Tính số mol của sản phẩm Fe3O4
        mol_Fe3O4_from_Fe = A // 3
        mol_Fe3O4_from_O2 = B // 2
        mol_Fe3O4 = min(mol_Fe3O4_from_Fe, mol_Fe3O4_from_O2)
        
        # Ghi kết quả vào tệp HOAHOC.OUT
        with open('HOAHOC.OUT', 'w') as outfile:
            outfile.write(str(mol_Fe3O4) + '\n')

    except FileNotFoundError:
        print("Tệp HOAHOC.INP không tồn tại.")
    except ValueError as ve:
        print(f"Lỗi: {ve}")

if __name__ == "__main__":
    main()
