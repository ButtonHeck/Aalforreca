#pragma once

namespace Aalforreca
{
    class Image
    {
    public:
        Image(const char* filename, int desiredChannels, bool flipVertically = false);
        ~Image();

        int width() const;
        int height() const;
        int channels() const;
        unsigned char* pixels() const;

    private:
        int _width;
        int _height;
        int _channels;
        unsigned char* _pixels;
    };
}
