import unittest
from cpplist import CppList


class ListTests(unittest.TestCase):

    def setUp(self):
        self._list = CppList()

    def test_push(self):
        self.assertEqual(self._list.size, 0)
        self._list.push(1)
        self.assertEqual(self._list.size, 1)

    def test_pop(self):
        self.assertEqual(self._list.size, 0)
        self.assertEqual(self._list.pop(), (0, False))
        self._list.push(10)
        self.assertEqual(self._list.size, 1)
        self.assertEqual(self._list.pop(), (10, True))
        self.assertEqual(self._list.size, 0)


if __name__ == '__main__':
    unittest.main()
