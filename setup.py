#ARCHFLAGS="-arch x86_64" python3 setup.py build
from distutils.core import setup, Extension

module = Extension("hello", sources = ["hello.cpp"])

setup(name='hello-lib',
      version="1",
      description="custom",
      ext_modules=[module])