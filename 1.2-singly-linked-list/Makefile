app.out: testLinkedList.o linkedList.o
	gcc -o app.out testLinkedList.o linkedList.o

testLinkedList.o : testLinkedList.c
	gcc -c -o testLinkedList.o testLinkedList.c

linkedList.o: linkedList.h linkedList.c
	gcc -c -o linkedList.o linkedList.c

clean:
	rm *.o app.out