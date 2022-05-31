file( GLOB_RECURSE SOURCEFILES
        src/*.cpp

        #This line is to make CMakeList.txt appear on the VS project tree.
        src/CMakeLists.txt
        )
source_group( "src" FILES ${SOURCEFILES})