if __name__ == "__main__":
    n = int(input())
    rst = 0.5 * (((n * (n+1) * (2*n + 1))//6) + ((n*(n+1))//2))
    print(int(rst))
