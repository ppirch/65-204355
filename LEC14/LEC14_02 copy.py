def tsp(pos,  bitmask) {
    # bitmask stores the visited coordinates
    if (bitmask == (1 << (n + 1)) - 1):
        return dist[pos][0]  # กลับไปที่เมืองเริ่มต้น
    if (memo[pos][bitmask] != -1):
        return memo[pos][bitmask]
    ans = 2000000000
    for (nxt in range(n+1)):  # O(n) here
        if (nxt != pos & & !(bitmask & (1 << nxt))):
            # if coordinate nxt is not visited yet
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)))
    return memo[pos][bitmask] = ans
}
