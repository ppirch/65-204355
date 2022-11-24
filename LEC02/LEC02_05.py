def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return gcd(b, a % b)


if __name__ == "__main__":
    n = int(input())
    rst = 0
    for i in range(1, n):
        for j in range(i+1, n+1):
            rst += gcd(i, j)
    print(rst)
