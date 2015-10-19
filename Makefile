run:
	clang++ -std=c++14 -L "lib" -o a.out ${NUM}/main.cpp && ./a.out

copy:
	cp -r _template ${NUM}

test:
	clang++ -isystem ${GTEST_DIR}/include -pthread ${NUM}/test.cpp ${GTEST_DIR}/libgtest.a -o ./test.out && ./test.out
