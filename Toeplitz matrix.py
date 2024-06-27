def isToeplitz(mat):
    #code here
    row=len(mat)
    col=len(mat[0])
    for i in range(row):
        for j in range(col):
            if(i<row-1 and j <col-1):
                if(mat[i][j]!=mat[i+1][j+1]):
                    return False
                    
    return True
                    
