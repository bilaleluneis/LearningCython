from libc.stdio cimport printf
from libc.stdlib cimport malloc, free
cimport cython

__author__ = "Bilal El Uneis"
__since__ = "June 2020"
__email__ = "bilaleluneis@gmail.com"

@cython.embedsignature(True)
cdef class IntGrid:
    cdef int ** data
    cdef int rows
    cdef int cols

    property dimension:
        def __get__(self) -> (int, int):
            return self.rows, self.cols

    def __cinit__(self, int rows, int cols):
        printf("\n\rinside __cinit__")
        cdef int row_counter = 0
        self.data = <int **> malloc(rows * sizeof(int *))
        for row_counter in range(rows):
            self.data[row_counter] = <int *> malloc(cols * sizeof(int))

    def __init__(self, int rows, int cols):
        printf("\n\rinside __init__")
        self.rows = rows
        self.cols = cols

    def __dealloc__(self):
        printf("\n\rinside __dealloc__")
        cdef int row_counter = 0
        for row_counter in range(self.rows):
            free(self.data[row_counter])
        free(self.data)

    def __setitem__(self, (int, int) index, int value) -> None:
        printf("\n\rinside __setitem__")
        cdef int row = index[0]
        cdef int col = index[1]
        self.data[row][col] = value

    def __getitem__(self, (int, int) index) -> int:
        printf("\n\rinside __getitem__")
        cdef int row = index[0]
        cdef int col = index[1]
        return self.data[row][col]
