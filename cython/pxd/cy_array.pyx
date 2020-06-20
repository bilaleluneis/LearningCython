from libc.stdlib cimport malloc, free
from libc.stdio cimport printf

cdef class IntArray:

    def __cinit__(self, int arr_size):
        self.data = self.create(arr_size)
        printf("\n\rIntArray __cinit__")

    def __init__(self, int arr_size):
        self.arr_size = arr_size
        printf("\n\rIntArray __init__")

    def __dealloc__(self):
        self.destroy()
        printf("\n\rIntArray __dealloc__")

    def __setitem__(self, int index, int val) -> None:
        self.data[index] = val
        printf("\n\rIntArray __setitem__")

    def __getitem__(self, int index) -> int:
        printf("\n\rIntArray __getitem__")
        return self.data[index]

    cdef int* get(self):
        printf("\n\rIntArray get()")
        return self.data

    cdef int* create(self, int arr_size):
        printf("\n\rIntArray create()")
        self.arr_size = arr_size
        return <int *> malloc(arr_size * sizeof(int))

    cdef void destroy(self):
        self.arr_size = 0
        if self.data != NULL:
            free(self.data)
        printf("\n\rIntArray destroy")

    cdef void replace_with(self, IntArray other):
        cdef int i = 0
        self.destroy()
        self.create(other.arr_size)
        for i in range(self.arr_size):
            self[i] = other[i]

