def main_diagonal_product(mat):
    sum = 1
    for i in range(len(mat)):
        sum = sum * mat[i][i]
    return sum