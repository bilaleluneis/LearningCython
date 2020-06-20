cdef class CList:

    property size:
        def __get__(self) -> int:
            return self._size

    def __cinit__(self):
        self._list = init()

    def __dealloc__(self):
        discard(self._list)
        self._list = NULL
        self._size = 0

    def __init__(self):
        self._size = 0

    def push(self, int val) -> None:
        push(val, self._list)
        self._size += 1

    def pop(self) -> (int, bool):
        if self._size == 0:
            return 0, False
        cdef pop_result result = pop(self._list)
        self._size -= 1
        return result.val, result.success
