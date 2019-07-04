CC = clang
CC_FLAGS = -O3 -Wall

build/ :
	mkdir $@
build/%.o : src/%.cpp include/%.hpp | build/
	$(CC) $(CC_FLAGS) -I include/ -c $< -o $@
objects : $(patsubst include/%.hpp, build/%.o, $(wildcard include/*.hpp))

clean :
	rm -rf build
