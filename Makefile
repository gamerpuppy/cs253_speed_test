export opts= -std=c++14 -Werror -Wfatal-errors
            
CXXFLAGS= -O3 -Wall $$opts

PROJECT_DIR= '/Users/keegan/CS253/cs253hw/hw9/'
LIB_PATH='/Users/keegan/CS253/cs253hw/hw9/hw8.a'

test: $(lib)
		$(CXX) $(CXXFLAGS) -I $(PROJECT_DIR) speed_test.cpp $(LIB_PATH) -o speed_test

clean:
		rm -f  *.o *.gch speed_test
