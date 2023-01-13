n = int(input())
sol = False
nums = set("0123456789")
for a in range(0, 100000):
    if a % n == 0:
        b = a // n
        if b < 10000:
            check = set(str(a) + str(b) + "0")
        if check == nums:
            print(f"{a} / {b:05d} = {n}")
            sol = True

if not sol:
    print("There are no solutions for N.")
