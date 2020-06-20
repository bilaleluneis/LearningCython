from libc.stdio cimport printf
from cy_array cimport IntArray

cdef class IntList:

    property size:
        def __get__(self):
            printf("\n\rList size.__get__")
            return self.arr_size - 1

    def __cinit__(self):
        self.arr = IntArray(1)
        self.arr_size = 1
        self.current_index = 0
        printf("\n\rList __cinit__")

    def __init__(self):
        printf("\n\rList __init__")

    def __del__(self):
        self.arr_size = 0
        self.arr.destroy()
        printf("\n\rList __del__")

    cpdef void push(self, int value):
        printf("\n\rList push()")
        cdef IntArray tmp_arr
        cdef int old_size = self.arr_size
        cdef int i = 0
        self.current_index += 1
        if self.current_index == self.arr_size:
            printf("\n\rList push() resize logic")
            self.arr_size += 1
            tmp_arr = IntArray(self.arr_size)
            for i in range(old_size):
                tmp_arr[i] = self.arr[i]
            self.arr.replace_with(tmp_arr)
            tmp_arr[self.current_index] = value
        else:
            printf("\n\rList push() no resize logic")
            self.arr[self.current_index] = value

    cpdef (int, bint) pop(self): # returns tuple of value and success
        cdef int result = 0 if self.size == 0 else self.arr[self.size]
        cdef IntArray tmp_arr = IntArray(1 if self.size == 0 else self.size)
        cdef int i = 0
        printf("\n\rList pop()")
        if self.size == 0:
            printf("\n\rList pop() list is empty nothing to pop")
            return 0, False
        else:
            printf("\n\rList pop() list is not empty poping")
            self.arr_size -= 1
            self.current_index -= 1
            for i in range (self.arr_size):
                tmp_arr[i] = self.arr[i]
            self.arr.replace_with(tmp_arr)
            return result, True



