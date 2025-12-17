import sys

import numpy as np

def read_input(path):
    with open(path, 'r') as file:
        lines = file.read()

    return lines.split('\n')


def find_access(matrix, n: int, m: int)-> int:
    def check_square:

    def check_down:

    def check_up:

    def check_left:

    def check_right:

    rolls = 0

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == '@':
                if i == 0 and j == 0 or i == 0 and j == m-1 or i == n-1 and j == 0 or i == n-1 and j == m-1:
                    rolls += 1
                elif i == 0:
                    do something
                elif j == 0:
                    do something
                elif i == n-1:
                    do something
                elif j == m-1:
                    do something
                else:
                    do something



    return rolls

def main():
    input = read_input('.\\input')

    n = len(input)
    m = len(input[0])

    paper_grid = np.empty((n, m), dtype=object)

    for i in range(n):
        for j in range(m):
            paper_grid[i, j] = input[i][j]

    rolls = find_access(paper_grid, n, m)

    print(f"Amount of rolls: {rolls}")


if __name__ == '__main__':
    main()