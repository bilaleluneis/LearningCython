from unittest import TestCase, main
from cy_array import IntArray
from cy_list import IntList


__author__ = "Bilal El Uneis"
__since__ = "May 2020"
__email__ = "bilaleluneis@gmail.com"


class ArrayTests(TestCase):

    def setUp(self) -> None:
        self._array = IntArray(10)

    def test_at_index_ops(self) -> None:
        self._array[0] = 10
        self.assertTrue(self._array[0] == 10)


class ListTests(TestCase):

    def setUp(self) -> None:
        self._list = IntList()

    def test_size(self) -> None:
        self.assertTrue(self._list.size == 0)

    def test_push(self) -> None:
        self._list.push(10)
        self.assertTrue(self._list.size == 1)

    def test_pop(self) -> None:
        self.assertTrue(self._list.size == 0)
        self._list.push(10)
        self.assertTrue(self._list.size == 1)
        poped_element, success = self._list.pop()
        self.assertTrue(poped_element == 10)
        self.assertTrue(self._list.size == 0)


if __name__ == '__main__':
    main()
