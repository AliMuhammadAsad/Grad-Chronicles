Matrix Addition

def matrix_addition(A,B):
    for x in range(len(A)):
        if len(A[x]) != len(B[x]):
            return("Matrices A and B don't have the same dimension required for matrix addition.")
        else:
            m_added = []
            for x in range(len(A)):
                temp = []
                for y in range(len(A[x])):
                    temp.append(A[x][y] + B[x][y])
                m_added.append(temp)
            return m_added
#For matrix subtraction, just replace + with -

--------------------------------------------------------------------------------------------------------------------------

Matrix Multiplication
#Will update once Lab 1 is visible as code doesn't check possibility, just multiplies

A, B = [], [] #Matrices to multiply
C = [] #Empty Matrix to store the multiplied values in
for i in range(len(A)):
    C.append([0] * len(B[0]))
    for j in range(len(B[0])):
        for k in range(len(B)):
            C[i][j] += A[i][k] * B[k][j]

print(C)

--------------------------------------------------------------------------------------------------------------------------

Matrix Transpose

A = [] #any matrix with n x m dimensions
def m_t(A):
    C = []
    for i in range(len(A[0])):
        C.append([0] * len(A)) #updates C with m x n dimensions with all 0 elements to be updated
    for i in range(len(A)):
        for j in range(len(A[0])):
            C[j][i] = A[i][j] #Transposed
    return C

print(m_t(A))

--------------------------------------------------------------------------------------------------------------------------

Sharpen Image - Checks neighbouring elements(up, down, left, right), multiplies by two, takes average, subtracts from main value

A = []

def sharpen_image(A):

    len1 = len(A) - 1
    len2 = len(A[0]) - 1
    new=[]
    newmat=[]
    for x in range(len(A)):
        for y in range(len(A[0])):
            A[x][y] = (A[x][y]) * 2
    
    
    for x in range(len(A)):
        for y in range(len(A[0])):
            sum = 0
            count = 0
            avg = 0
            #upper check
            if (x-1) >=0 and (x-1) <= len1:
                sum = sum + A[x-1][y]
                count = count + 1
    
            #lower check
            if (x+1) >=0 and (x+1) <= len1:
                sum = sum + A[x+1][y]
                count = count + 1
    
            #left check
            if (y-1) >= 0 and (y-1) <=len2:
                sum = sum + A[x][y-1]
                count = count + 1
                
            #right check
            if (y+1) >= 0 and (y+1) <= len2:
                sum = sum + A[x][y+1]
                count = count + 1
                
            
            avg = sum / count
            #print("org val : ",A[x][y])
            value = round(abs(A[x][y] - avg), 2)
            #print("new val : ", newmat[x][y])
            new.append(value)
        newmat.append(new)
        new = []  
    print(newmat)    
(sharpen_image(A))

