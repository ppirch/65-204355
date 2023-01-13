board = [[0]*9 for i in range(9)]
rp, rc = -1, -1
rst = set()


def reset_board() -> None:
    for i in range(1, 9):
        for j in range(1, 9):
            board[i][j] = 0


def is_safe(r, c) -> bool:
    if board[r][c]:
        return False
    # check row
    for i in range(1, 9):
        if board[r][i]:
            return False
    # check column
    for i in range(1, 9):
        if board[i][c]:
            return False
    # check diagonal
    for i in range(1, 9):
        for j in range(1, 9):
            if i + j == r + c and board[i][j]:
                return False
            if i - j == r - c and board[i][j]:
                return False
    return True


def print_board() -> None:
    s = ''
    for j in range(1, 9):
        for i in range(1, 9):
            if board[i][j]:
                s += str(i) + ' '
    rst.add(s)


def solve(r, c):
    if r == 9:
        print_board()
        return

    for i in range(1, 9):
        if is_safe(r, i):
            board[r][i] = 1
            solve(r+1, i)
            board[r][i] = 0
        elif r == rp:
            solve(r+1, i)


if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        reset_board()
        rp = int(input())
        rc = int(input())
        board[rp][rc] = 1
        solve(1, 1)
        for sol in sorted(list(rst)):
            print(sol)
