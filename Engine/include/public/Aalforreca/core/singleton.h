#pragma once

#include "Aalforreca/core/assert.h"

namespace Aalforreca
{
    template<typename T>
    class Singleton
    {
    private:
        Singleton(const Singleton<T>&);
        Singleton& operator=(const Singleton<T>&);

    public:
        Singleton()
        {
            ALRC_ASSERT(!_singleton, "There can only be one singleton of this type");
            _singleton = static_cast<T*>(this);
        }

        ~Singleton()
        {
            ALRC_ASSERT(_singleton);
            _singleton = nullptr;
        }

        static T& singleton()
        {
            ALRC_ASSERT(_singleton);
            return *_singleton;
        }

        static T* singletonPtr()
        {
            return _singleton;
        }

    protected:
        static T* _singleton;
    };
}

#define ALRC_SINGLETON(ClassName) template<> ClassName* Singleton<ClassName>::_singleton = nullptr;
