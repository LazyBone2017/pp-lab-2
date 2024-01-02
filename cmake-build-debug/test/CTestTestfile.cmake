# CMake generated Testfile for 
# Source directory: /home/jonas/Dokumente/Semester VII/SPP/lab2/test
# Build directory: /home/jonas/Dokumente/Semester VII/SPP/lab2/cmake-build-debug/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(SerialTests "/home/jonas/Dokumente/Semester VII/SPP/lab2/cmake-build-debug/bin/lab_test")
set_tests_properties(SerialTests PROPERTIES  _BACKTRACE_TRIPLES "/home/jonas/Dokumente/Semester VII/SPP/lab2/test/CMakeLists.txt;65;add_test;/home/jonas/Dokumente/Semester VII/SPP/lab2/test/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
