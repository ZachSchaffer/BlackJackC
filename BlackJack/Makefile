src = $(wildcard include/*.c) $(wildcard core/*.c)
obj = $(src:.c=.o)
out =  blackjack

myprog: $(obj) 
	gcc -std=c99 $(obj) -o $(out) -pthread

.PHONY: clean
clean:
	rm -f $(obj) myprog
