# Makefile
# assume project header and cpp are same name

PROJECT = carLists
MAIN = main.cpp

debug: $(MAIN) $(PROJECT).cpp $(PROJECT).h
	g++ -g -Wall $(MAIN) $(PROJECT).cpp -o debug

$(PROJECT): $(MAIN) $(PROJECT).cpp $(PROJECT).h
	g++ -g -Wall $(MAIN) $(PROJECT).cpp -o output

clean:
	rm debug
	rm output
