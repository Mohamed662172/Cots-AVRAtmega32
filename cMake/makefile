build:test.c
	gcc test.c -o out.exe
	gcc -E -p test.c -o out.i
pre: test.c test_2.c test_3.c
	gcc -E -p test.c -o out.i 
	gcc -E -p test_2.c -o out2.i
	gcc -E -p test_3.c -o out3.i