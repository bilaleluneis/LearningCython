from distutils.core import setup
from distutils.extension import Extension

from Cython.Build import cythonize

__author__ = "Bilal El Uneis"
__since__ = "June 2020"
__email__ = "bilaleluneis@gmail.com"

libDir = "../../c_collection/dist/Debug/GNU-Linux"
lib = "c_collection"
include = "../../c_collection"

list_module = [Extension("clist",
                         sources=["clist.pyx"],
                         include_dirs=[include],
                         library_dirs=[libDir],
                         libraries=[lib],
                         language="c")]

setup(name="collection", ext_modules=cythonize(list_module, language_level=3, annotate=True, gdb_debug=True))
