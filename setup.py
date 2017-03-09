#!/usr/bin/env python

from distutils.core import setup
from distutils.extension import Extension

# just see the links of README.md for how to fill in those blank.
module1 = Extension('example',
                    sources = ['wrap.c', 'example.c'])

setup(name = 'example',
      version = '1.0',
      description = 'description of example.',
      ext_modules = [module1])