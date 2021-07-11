all:hello

hello: main.o admin.o customer.o bill.o
	g++ main.o admin.o customer.o bill.o -o hello

main.o: main.cpp
	g++ -c main.cpp

admin.o: admin.cpp
	g++ -c admin.cpp

customer.o: customer.cpp
	g++ -c customer.cpp

bill.o: bill.cpp
	g++ -c bill.cpp

clean:
	rm -rf *.o