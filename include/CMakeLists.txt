file( GLOB_RECURSE HEADERS
        include/*.h

        #This line is to make CMakeList.txt appear on the VS project tree.
        include/CMakeLists.txt
        )
source_group( "include"
              PREFIX "Project Headers" 
              FILES ${HEADERS})

install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})