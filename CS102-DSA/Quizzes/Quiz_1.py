#Quiz 01 Code 

import ast
board = input()
board = ast.literal_eval(board)

def next_state(board):
    res = []
    for rows in range(len(board)):
        res.append([0] * len(board[0])) #places 0s of rows x columns in the resultant board
    for row in range(len(board)):
        for x in range(len(board[0])):
            temp = []
            count_one = 0
            if x < len(board[row]) - 1: #checks if there is a right element 
                r_elem = board[row][x + 1]
                temp.append(r_elem)
            if x > 0: #checks if there is a left element
                l_elem = board[row][x - 1]
                temp.append(l_elem)
            if row > 0: #checks if there is an upper row 
                u_elem = board[row - 1][x]   
                temp.append(u_elem) 
            if row < len(board) - 1: #checks if there is a lower row
                l_elem = board[row + 1][x] 
                temp.append(l_elem)
            if row > 0 and x < (len(board[row]) - 1): #checks if there is a right upper diagonal value
                r_u_diag = board[row - 1][x + 1]
                temp.append(r_u_diag)
            if row < len(board) - 1 and x < len(board[row]) - 1: #checks if there is a right lower diagonal value
                r_d_diag = board[row + 1][x + 1]
                temp.append(r_d_diag)
            if row > 0 and x > 0: #checks if there is a left upper diagonal value
                l_u_diag = board[row - 1][x - 1]
                temp.append(l_u_diag)
            if row < len(board) - 1 and x > 0: #checks if there is a left lower diagonal value
                l_d_diag = board[row + 1][x - 1]
                temp.append(l_d_diag)
            for i in temp:
                if i == 1:
                    count_one += 1
            if count_one == 3:
                res[row][x] = 1
            elif count_one < 2:
                res[row][x] = 0
            elif count_one > 3:
                res[row][x] == 0
            elif count_one == 2 and board[row][x] == 1:
                res[row][x] = 1
    return res

print(next_state(board))