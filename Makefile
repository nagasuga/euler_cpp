run:
	clang++ -L "lib" -o a.out ${NUM}/main.cpp && ./a.out

copy:
	cp -r _template ${NUM}
