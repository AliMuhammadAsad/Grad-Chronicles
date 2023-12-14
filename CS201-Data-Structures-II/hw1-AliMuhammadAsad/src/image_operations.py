from src.myimage import MyImage

def remove_channel(src: MyImage, red: bool = False, green: bool = False,
                   blue: bool = False) -> MyImage:
    """Returns a copy of src in which the indicated channels are suppressed.

    Suppresses the red channel if no channel is indicated. src is not modified.

    Args:
    - src: the image whose copy the indicated channels have to be suppressed.
    - red: suppress the red channel if this is True.
    - green: suppress the green channel if this is True.
    - blue: suppress the blue channel if this is True.

    Returns:
    a copy of src with the indicated channels suppressed.
    """
    src_copy = MyImage(src.size)
    rows = src.size[1]
    cols = src.size[0]
    for row in range(rows):
        for col in range(cols):
            src_copy.set(row, col, src.get(row, col))
    
    if red == False and green == False and blue == False:
        for row in range(rows):
            for col in range(cols):
                temp = list(src_copy.get(row, col)); temp[0] = 0
                src_copy.set(row, col, tuple(temp))
    else:
        for row in range(rows):
            for col in range(cols):
                temp = list(src_copy.get(row, col))
                if red == True: temp[0] = 0
                if green == True: temp[1] = 0
                if blue == True: temp[2] = 0
                src_copy.set(row, col, tuple(temp))
    return src_copy

def convert_to_matrix(lst, m, n): #converts a flattened representation into an mxn matrix such that m and n are known 
    mat = []
    for i in range(0, len(lst), n):
        mat.append(lst[i:i+n])
    return mat[:m]

def rotate_90(matrix): #Rotates a given m x n matrix 90 degress clockwise
    res = []
    for i in range(len(matrix[0])):
        lst = []
        for j in range(len(matrix)):
            lst.append(matrix[j][i])
        # Reversing the matrix for 90 degree
        lst.reverse()
        res.append(lst)
    return res

def rotations(src: MyImage) -> MyImage:
    """Returns an image containing the 4 rotations of src.

    The new image has twice the dimensions of src. src is not modified.

    Args:
    - src: the image whose rotations have to be stored and returned.

    Returns:
    an image twice the size of src and containing the 4 rotations of src.
    """
    rows = src.size[1]
    cols = src.size[0]
    src_copy = MyImage((cols * 2, rows * 2))
    rot_90_lst = []
    rot_180_lst = []
    rot_270_lst = []
    rot_360_lst = []
    temp = []
    
    for row in range(rows):
        for col in range(cols):
            temp.append(src.get(row, col))
    rot_360_lst = convert_to_matrix(temp, rows, cols) #Og image
    # 90 degree clockwise rotation
    rot_90_lst = rotate_90(rot_360_lst)
    #Image - 180
    rot_180_lst = rotate_90(rot_90_lst)
    #Image - 90 anticlockwise
    rot_270_lst = rotate_90(rot_180_lst) 
    src_copy_lst = []
    for i in range(rows * 2):
        if i < rows:
            for x in range(len(rot_270_lst[i])):
                src_copy_lst.append(rot_270_lst[i][x])
            for x in range(len(rot_360_lst[i])):
                src_copy_lst.append(rot_360_lst[i][x])
        else:
            for x in range(len(rot_180_lst[i % rows])):
                src_copy_lst.append(rot_180_lst[i % rows][x])
            for x in range(len(rot_90_lst[i % rows])):
                src_copy_lst.append(rot_90_lst[i % rows][x])
    lst1 = convert_to_matrix(src_copy_lst, rows*2, cols*2)
    for row in range(rows*2):
        for col in range(cols*2):
            src_copy.set(row, col, lst1[row][col])
    return src_copy

def resize(src: MyImage) -> MyImage:
    """Returns an image which has twice the dimensions of src.

    The new image has twice the dimensions of src. src is not modified.

    Args:
    - src: the image which needs to be resized. 

    Returns:
    an image twice the size of src.
    """
    rows = src.size[1]
    cols = src.size[0]
    src_copy = MyImage((cols * 2, rows * 2))
    for row in range(rows):
        for col in range(cols):
            src_copy.set(row*2, col*2, src.get(row, col))
    for row in range(cols*2):
        for col in range(rows * 2):
            if row % 2 == 0: #All even rows - not black rows
                if col % 2 == 1:
                    if col == (cols * 2) - 1: #The last column - edge case
                        pix = src_copy.get(row, col - 1)
                        src_copy.set(row, col, pix)
                    else:
                        pix1 = src_copy.get(row, col-1)
                        pix2 = src_copy.get(row, col+1)
                        pix = ((pix1[0] + pix2[0])//2, (pix1[1] + pix2[1])//2, (pix1[2] + pix2[2]) // 2)
                        src_copy.set(row, col, pix)
                else: pass
            if row % 2 == 1: #Black rows
                if col % 2 == 0: #Not completely black columns
                    if row == (rows * 2) - 1: #Last row - edge case
                        pix = src_copy.get(row - 1, col)
                        src_copy.set(row, col, pix)
                    else:
                        pix1 = src_copy.get(row - 1, col)
                        pix2 = src_copy.get(row + 1, col)
                        pix = ((pix1[0] + pix2[0]) // 2, (pix1[1] + pix2[1]) // 2, (pix1[2] + pix2[2]) // 2)
                        src_copy.set(row, col, pix)
                if col % 2 == 1:
                    if col == (cols * 2) - 1:
                        pix = src_copy.get(row, col - 1)
                        src_copy.set(row, col, pix)
                    else:
                        if row != (rows * 2) - 1:
                            pix1 = src_copy.get((row - 1), (col - 1))
                            pix2 = src_copy.get((row - 1), (col + 1))
                            pix3 = src_copy.get((row + 1), (col + 1))
                            pix4 = src_copy.get((row + 1), (col - 1))
                            pix = ((pix1[0] + pix2[0] + pix3[0] + pix4[0])//4, (pix1[1] + pix2[1] + pix3[1] + pix4[1]) // 4, (pix1[2] + pix2[2] + pix3[2] + pix4[2]) // 4) 
                            src_copy.set(row, col, pix)

    for row in range(rows * 2):
        for col in range(cols * 2):
            if row % 2 == 1 and col % 2 == 1:
                if col == (cols * 2) - 1: #Edge case - last col
                    pix = src_copy.get(row, col - 1)
                    src_copy.set(row, col, pix)
                elif row == (row * 2) - 1: #Edge case - last row
                    pix = src_copy.get(row - 1, col)
                    src_copy.set(row, col, pix)
                else:
                    if row != (rows * 2) - 1:
                        pix1 = src_copy.get((row - 1), (col - 1))
                        pix2 = src_copy.get((row - 1), (col + 1))
                        pix3 = src_copy.get((row + 1), (col + 1))
                        pix4 = src_copy.get((row + 1), (col - 1))
                        pix = ((pix1[0] + pix2[0] + pix3[0] + pix4[0])//4, (pix1[1] + pix2[1] + pix3[1] + pix4[1]) // 4, (pix1[2] + pix2[2] + pix3[2] + pix4[2]) // 4) 
                        src_copy.set(row, col, pix)
                    else:
                        pix1 = src_copy.get(row, col - 1)
                        pix2 = src_copy.get(row, col + 1)
                        pix = ((pix1[0] + pix2[0]) // 2, (pix1[1] + pix2[1]) // 2, (pix1[2] + pix2[2]) // 2)
                        src_copy.set(row, col, pix)
    return src_copy   

def maskreader(maskfile): #Reads the maskfile and returns a list with values of maskfile
    '''
    Returns a tuple of mask list and length. 
    This is a helper function that is used in apply_mask function to read
    the mask file and return a list of n by n.

    maskfile is a text file containing n by n mask. 

    Args:
    - maskfile: path to file specifying mask

    Returns:
    Tuple of lst of n by n and length
    '''
    f = open(maskfile, 'r'); 
    lst = []
    for i in f: 
        lst.append(int(i))
    mat_len = lst[0]; mask_lst = lst[1::]
    f.close()
    return (mask_lst, mat_len)

def apply_mask(src: MyImage, maskfile: str, average: bool = True) -> MyImage:
    """Returns an copy of src with the mask from maskfile applied to it.

    maskfile specifies a text file which contains an n by n mask. It has the
    following format:
    - the first line contains n
    - the next n^2 lines contain 1 element each of the flattened mask

    Args:
    - src: the image on which the mask is to be applied
    - maskfile: path to a file specifying the mask to be applied
    - average: if True, averaging should to done when applying the mask

    Returns:
    an image which the result of applying the specified mask to src.
    """
    rows = src.size[1]; cols = src.size[0]
    src_copy = MyImage(src.size)
    # for row in range(rows):
    #     for col in range(cols):
    #         src_copy.set(row, col, src.get(row, col))
    vals = maskreader(maskfile)
    mask_lst = vals[0]; n = vals[1]
    # print(f"Mask list: {mask_lst} \n length = {n} \n center at {center} with value {mask_lst[center]}")
    for i , pixels in enumerate(src):
        row, col = divmod(i,cols) #gives row index with corresponding column index to iterate over
        # print(row, col)
        val = 0; total = 0
        for x in range(n):
            for y in range(n):
                mask_row = x - (n // 2) #Computing row mask
                mask_col = y - (n // 2) #Computing col mask
                if row + mask_row >= 0 and row + mask_row < rows and col + mask_col >= 0 and col + mask_col < cols:
                    total += mask_lst[n * x + y]
                    pix = src.get(row + mask_row, col + mask_col)
                    # print(f"Row {row}  Col {col}  RowMask {mask_row}  ColMask {mask_col}  pixel {pix}")
                    val += ((pix[0] + pix[1] + pix[2])) // 3 * mask_lst[n * x + y]
        if average == True: val = val // total
        if val > 255: val = 255
        if val < 0: val = 0
        src_copy.set(row, col, (val,val,val))
    return src_copy

