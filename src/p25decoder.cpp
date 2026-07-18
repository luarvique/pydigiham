#include "p25decoder.hpp"
#include "types.hpp"

#include <digiham/p25_decoder.hpp>
#include <digiham/meta.hpp>

static int P25Decoder_init(P25Decoder* self, PyObject* args, PyObject* kwds) {
    self->inputFormat = FORMAT_CHAR;
    self->outputFormat = FORMAT_CHAR;
    self->setModule(new Digiham::P25::Decoder());

    return 0;
}

static PyType_Slot P25DecoderSlots[] = {
    {Py_tp_init, (void*) P25Decoder_init},
    {0, 0}
};

PyType_Spec P25DecoderSpec = {
    "digiham.modules.P25Decoder",
    sizeof(P25Decoder),
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_FINALIZE,
    P25DecoderSlots
};
