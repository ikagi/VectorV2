CXX = g++
CXXFLAGS = -std=c++17 -I/usr/include -I./include
LDFLAGS = 
SRCS = src/main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = bin/main
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:
	rm -f $(OBJS) $(EXEC)