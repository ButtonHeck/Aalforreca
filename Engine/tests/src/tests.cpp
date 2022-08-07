#include "Core/application.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

bool ok(bool flag)
{
    return true;
}

TEST_CASE("Test ok")
{
    CHECK(ok(true));
    CHECK(ok(false));
}
