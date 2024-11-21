# -*- MakeFile -*-

CC = gcc # Compiler used
CFLAGS = -O2 -Wall -c # Flags used to create each .o file, with minimum optimization level (the optimal after trying all options)

TARGET = chacha20 # This is the final executable file
OBJS = chacha20.o quarter_round.o state_init.o permute_state.o encrypt.o run_test.o calculate_throughput.o decrypt.o run_decrypt_test.o # These are all the .o files required to generate the executable

# Using the previous variables, create the prompts
# For variable substituiton within the makefile put them inside $(here) 

# Create executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -O3 -Wall -o $(TARGET)

# Create all .o files
chacha20.o: chacha20.c
	$(CC) $(CFLAGS) chacha20.c

quarter_round.o: quarter_round.c
	$(CC) $(CFLAGS) quarter_round.c

state_init.o: state_init.c
	$(CC) $(CFLAGS) state_init.c

permute_state.O: state_init.c
	$(CC) $(CFLAGS) state_init.c

encrypt.O: encrypt.c
	$(CC) $(CFLAGS) encrypt.c

run_test.o: run_test.c
	$(CC) $(CFLAGS) run_test.c

calculate_throughput.o: calculate_throughput.c
	$(CC) $(CFLAGS) calculate_throughput.c

decrypt.o: decrypt.c
	$(CC) $(CFLAGS) decrypt.c

run_decrypt_test.o: run_decrypt_test.c
	$(CC) $(CFLAGS) run_decrypt_test.c

clean: # Used to remove all files generated by the build process.
	cmd /C del /Q $(TARGET) $(OBJS) chacha20.exe

.PHONY: clean # This tells make that clean is not a file, but a command.make 
