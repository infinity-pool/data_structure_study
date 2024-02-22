app.out: testDoublyLinkedList.o doublyLinkedList.o
	gcc -o app.out testDoublyLinkedList.o doublyLinkedList.o

testLinkedList.o : testDoublyLinkedList.c
	gcc -c -o testDoublyLinkedList.o testDoublyLinkedList.c

linkedList.o: doublyLinkedList.h doublyLinkedList.c
	gcc -c -o doublyLinkedList.o doublyLinkedList.c

clean:
	rm *.o app.out