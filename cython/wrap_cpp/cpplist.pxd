from libcpp.utility cimport pair

cdef extern from "list.h":
    cdef cppclass List[T]:
        List()
        void push(T value)
        pair[T, bint] pop()
        int size()

cdef class CppList:
    cdef List[int] *_list
    cdef int _size


