# comments begin with #



# Define variables $(OBJS) #

OBJS = tokenizer.o history.o



# Default rule for creation of Objects #

CFLAGS = -g -O3



# Target built by default #

all: main_token mainui



# Target (main_token) depends on Object files #

main_token: $(OBJS) main_token.c

	cc $(CFLAGS) main_token.c $(OBJS) -o main_token



# Target (mainui) depends on Object files #

mainui: $(OBJS) mainui.c

	cc $(CFLAGS) mainui.c $(OBJS) -o mainui


# Rules #

tokenizer.o: tokenizer.c tokenizer.h

	cc $(CFLAGS) -c tokenizer.c


history.o: history.c history.h tokenizer.h

	cc $(CFLAGS) -c history.c



#tester.o: tester.c tokenizer.h

	#cc $(CFLAGS) -c tester.c



# Clean files #

clean:

	rm -f *.o main_token mainui



# Run #

run: main_token

	./main_token


run: mainui

	./mainui
