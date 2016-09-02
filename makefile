all:
	g++ -o $(PROG) $(PROG).cpp
	./$(PROG)
run:
	./$(PROG)
rm:
	rm *.o