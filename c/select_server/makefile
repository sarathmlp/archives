CXX=g++ -g

all:server client

server:server_sock_def.o server_main.o socket_def.o
	$(CXX) $^ -o $@
client:client.o
	$(CXX) $^ -o $@
%.o:%.cpp
	$(CXX) -c $^ -o $@
clean:
	rm -rf *.o
