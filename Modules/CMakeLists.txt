INCLUDE(${PROJECT_SOURCE_DIR}/CMakeCommon)

AUX_SOURCE_DIRECTORY(. QEDIS_MODULE_SRC)

LINK_DIRECTORIES(../../leveldb)

SET(LIBRARY_OUTPUT_PATH ../../bin)
SET(QEDIS_MODULE qedismodule)

ADD_LIBRARY(${QEDIS_MODULE} SHARED ${QEDIS_MODULE_SRC})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/QedisCore)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/QBase)

ADD_DEPENDENCIES(${QEDIS_MODULE} qediscore leveldb)
# clang needs below, not necessary for gcc
TARGET_LINK_LIBRARIES(${QEDIS_MODULE} qbaselib; qediscore; leveldb)

SET_TARGET_PROPERTIES(${QEDIS_MODULE} PROPERTIES LINKER_LANGUAGE CXX)
