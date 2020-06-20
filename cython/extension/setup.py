from distutils.core import setup
from distutils.extension import Extension

from Cython.Build import cythonize

__author__ = "Bilal El Uneis"
__since__ = "June 2020"
__email__ = "bilaleluneis@gmail.com"

grid_module = [Extension("grid", sources=["grid.pyx"], language="c")]

setup(name="grid", ext_modules=cythonize(grid_module, language_level=3, annotate=True, gdb_debug=True))
