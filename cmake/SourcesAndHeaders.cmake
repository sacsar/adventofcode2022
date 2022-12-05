set(sources
        src/tmp.cpp
        src/day1.cpp
        src/day2.cpp
        )

set(exe_sources
        src/main.cpp
        ${sources}
        )

set(headers
        include/adventofcode/tmp.hpp
        include/adventofcode/day1.hpp
        include/adventofcode/day2.hpp
        )

set(test_sources
        src/tmp_test.cpp
        )
