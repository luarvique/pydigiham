#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "decoder.hpp"

struct P25Decoder: Decoder {};

extern PyType_Spec P25DecoderSpec;
