cdef class CppList:
    property size:
        def __get__(self) -> int:
            return self._size

    def __cinit__(self):
        self._list = new List[int]()

    def __dealloc__(self):
        del self._list
        self._list = NULL
        self._size = 0

    def __init__(self):
        self._size = 0

    def push(self, int val) -> None:
        self._list.push(val)
        self._size += 1

    def pop(self) -> (int, bint):
        if self._size == 0:
            return 0, False
        cdef pair[int, bint] result = self._list.pop()
        self._size -= 1
        return result