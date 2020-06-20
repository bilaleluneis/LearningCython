cdef extern from "list.h":

    ctypedef struct pop_result:
        int val
        bint success

    ctypedef struct List:
        pass

    List* init()
    void discard(List*)
    void push(int, List*)
    pop_result pop(List*)

cdef class CList:
    cdef List* _list
    cdef int _size


