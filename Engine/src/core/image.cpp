#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/image.h"
#include "Aalforreca/core/log.h"

#include <stb_image.h>

namespace Aalforreca
{
    Image::Image(const char* filename, int desiredChannels, bool flipVertically)
        : _width(0)
        , _height(0)
        , _channels(desiredChannels)
        , _pixels(nullptr)
    {
        stbi_set_flip_vertically_on_load(flipVertically);
        _pixels = stbi_load(filename, &_width, &_height, nullptr, desiredChannels);
        if (!_pixels)
            ALRC_CORE_ERROR("Image \"{}\" loading error", filename);
    }

    Image::~Image()
    {
        if (_pixels)
            stbi_image_free(_pixels);
    }

    int Image::width() const
    {
        return _width;
    }

    int Image::height() const
    {
        return _height;
    }

    int Image::channels() const
    {
        return _channels;
    }

    unsigned char* Image::pixels() const
    {
        return _pixels;
    }
}
