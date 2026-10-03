#include "easypaldecoder.hpp"
#include "types.hpp"

#include <digiham/easypal_decoder.hpp>

static int EasyPalDecoder_init(EasyPalDecoder* self, PyObject* args, PyObject* kwds) {
    static char* kwlist[] = {(char*) "raw", NULL};

    int raw = false;
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|p", kwlist, &raw)) {
        return -1;
    }

    self->inputFormat = FORMAT_FLOAT;
    self->outputFormat = FORMAT_CHAR;
    self->setModule(new Digiham::EasyPal::Decoder(raw));

    return 0;
}

static PyType_Slot EasyPalDecoderSlots[] = {
    {Py_tp_init, (void*) EasyPalDecoder_init},
    {0, 0}
};

PyType_Spec EasyPalDecoderSpec = {
    "digiham.modules.EasyPalDecoder",
    sizeof(EasyPalDecoder),
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_FINALIZE,
    EasyPalDecoderSlots
};
