def ff(arr, st_pos, color, old):
    x = st_pos[0]; y = st_pos[1]
    if x < 0 or x >= len(arr) or y < 0 or y >= len(arr[0]):
        return
    if arr[x][y] != old:
        return
    print(x, y, arr[x][y], old)
    arr[x][y] = color
    ff(arr, (x-1, y), color, old)
    ff(arr, (x+1, y), color, old)
    ff(arr, (x, y-1), color, old)
    ff(arr, (x, y+1), color, old)

grid = [
    [1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 1, 0, 0, 1],
    [1, 0, 0, 0, 1, 0, 1, 1],
    [1, 0, 0, 0, 1, 1, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1]
]

ff(grid, (1, 1), 2, 0)
for row in grid:
    print(row)