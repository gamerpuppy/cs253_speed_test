export opts= -std=c++14 -Werror -Wfatal-errors
            
CXXFLAGS= -O3 -Wall $$opts

PROJECT_DIR= '/s/bach/e/under/millardk/Documents/cs253/hw9/'
LIB_PATH='/s/bach/e/under/millardk/Documents/cs253/hw9/hw8.a'


test: 
		$(CXX) $(CXXFLAGS) -I $(PROJECT_DIR) speed_test.cpp $(LIB_PATH) -o speed_test

clean:
		rm -f  *.o *.gch speed_test
