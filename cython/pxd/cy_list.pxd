from cy_array cimport IntArray

cdef class IntList:
    cdef IntArray arr
    cdef int arr_size
    cdef int current_index
    cpdef void push(self, int value)
    cpdef (int, bint) pop(self)