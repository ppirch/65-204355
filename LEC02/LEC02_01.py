if __name__ == "__main__":
    inp = int(input())
    mx = -1
    num = 1
    while True:
        if inp % 2 == 0:
            rst = int(inp ** (0.5))
        else:
            rst = int(inp ** (1.5))
        num += 1
        inp = rst
        mx = max(mx, rst)
        if inp == 1:
            break
    print(mx, num)
