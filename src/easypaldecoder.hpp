#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <pycsdr/module.hpp>

struct EasyPalDecoder: Module {};

extern PyType_Spec EasyPalDecoderSpec;