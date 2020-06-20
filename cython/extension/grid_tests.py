from unittest import TestCase, main

from grid import IntGrid

__author__ = "Bilal El Uneis"
__since__ = "June 2020"
__email__ = "bilaleluneis@gmail.com"


class GridTests(TestCase):

    def setUp(self):
        self.__grid = IntGrid(10, 10)

    def test_dimension(self):
        self.assertEqual(self.__grid.dimension, (10, 10))

    def test_set_get_at_index(self):
        self.__grid[0, 0] = 10
        self.assertTrue(self.__grid[0, 0], 10)

    def tearDown(self):
        pass


if __name__ == '__main__':
    main()
