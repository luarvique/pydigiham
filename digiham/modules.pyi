from pycsdr.modules import Module, Writer
from digiham.ambe import Mode

version: str = ...
digiham_version: str = ...


class DcBlock(Module):
    def __init__(self):
        ...


class FskDemodulator(Module):
    def __init__(self, samplesPerSymbol: int = 40, invert: bool = False):
        ...


class DigitalVoiceFilter(Module):
    def __init__(self):
        ...


class WideRrcFilter(Module):
    def __init__(self):
        ...


class NarrowRrcFilter(Module):
    def __init__(self):
        ...


class MbeSynthesizer(Module):
    @staticmethod
    def hasAmbe(server: str = "") -> bool:
        ...

    def __init__(self, mode: Mode, server: str = ""):
        ...


class GfskDemodulator(Module):
    def __init__(self, samplesPerSymbol: int = 10):
        ...


class Decoder(Module):
    def setMetaWriter(self, metaWriter: Writer) -> None:
        ...


class DstarDecoder(Decoder):
    def __init__(self):
        ...


class NxdnDecoder(Decoder):
    def __init__(self):
        ...


class DmrDecoder(Decoder):
    def __init__(self):
        ...

    def setSlotFilter(self, filter: int) -> None:
        ...

class YsfDecoder(Decoder):
    def __init__(self):
        ...


class P25Decoder(Decoder):
    def __init__(self):
        ...


class PocsagDecoder(Decoder):
    def __init__(self):
        ...


class EasyPalDecoder(Module):
    """
    Decodes EasyPal ("digital SSTV") transmissions, which are HamDRM: a DRM mode in a ~2.4kHz audio channel
    that carries files, usually JPEG images.

    Input is mono audio at 12kHz, as Format.FLOAT. Output is Format.CHAR, with one record for every file that
    has been received completely:

        "EPAL"       4 bytes, magic
        length       4 bytes, little endian, size of the file
        nameLength   1 byte
        name         file name as announced by the sender (may be empty)
        callLength   1 byte
        callsign     callsign of the sender (may be empty)
        data         <length> bytes

    With raw=True, only the bytes of the files are written.
    """
    def __init__(self, raw: bool = False):
        ...
