#ifndef GRBAPIXEL_H
#define GRBAPIXEL_H
#include <cstdint>
using std::uint8_t;
class RGBAPixel {

    public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;

    RGBAPixel();
    RGBAPixel(uint8_t _r, uint8_t _g, uint8_t _b);

};
#endif

