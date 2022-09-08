#pragma once

namespace Aalforreca
{
    class Image
    {
    public:
        enum Channels
        {
            R = 1,
            RG,
            RGB,
            RGBA
        };

    public:
        Image(const char* filename, Channels desiredChannels, bool flipVertically = false);
        ~Image();

        int width() const;
        int height() const;
        int channels() const;
        unsigned char* pixels() const;

    private:
        int _width;
        int _height;
        Channels _channels;
        unsigned char* _pixels;
    };
}
