# CMake generated Testfile for 
# Source directory: C:/Users/ASUS'/CLionProjects/sorts
# Build directory: C:/Users/ASUS'/CLionProjects/sorts/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[SortingTests]=] "C:/Users/ASUS'/CLionProjects/sorts/build/Debug/test_sorts.exe")
  set_tests_properties([=[SortingTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;16;add_test;C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[SortingTests]=] "C:/Users/ASUS'/CLionProjects/sorts/build/Release/test_sorts.exe")
  set_tests_properties([=[SortingTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;16;add_test;C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[SortingTests]=] "C:/Users/ASUS'/CLionProjects/sorts/build/MinSizeRel/test_sorts.exe")
  set_tests_properties([=[SortingTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;16;add_test;C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[SortingTests]=] "C:/Users/ASUS'/CLionProjects/sorts/build/RelWithDebInfo/test_sorts.exe")
  set_tests_properties([=[SortingTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;16;add_test;C:/Users/ASUS'/CLionProjects/sorts/CMakeLists.txt;0;")
else()
  add_test([=[SortingTests]=] NOT_AVAILABLE)
endif()
