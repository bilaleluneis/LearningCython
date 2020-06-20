cdef class IntArray:
    cdef int arr_size
    cdef int *data
    cdef int* create(self, int arr_size)
    cdef int* get(self)
    cdef void destroy(self)
    cdef void replace_with(self, IntArray other)
