from distutils.core import setup
from distutils.extension import Extension

from Cython.Build import cythonize

collection_module = [Extension("cy_array",  sources=["cy_array.pyx"], language="c"),
                     Extension("cy_list", sources=["cy_list.pyx"], language="c")]
setup(name="collection", ext_modules=cythonize(collection_module, language_level=3, annotate=True, gdb_debug=True))
