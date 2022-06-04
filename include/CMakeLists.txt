file( GLOB_RECURSE HEADERS
        include/*.h
        include/CMakeLists.txt
        )
source_group( "include"
              PREFIX "Project Headers" 
              FILES ${HEADERS})

install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})