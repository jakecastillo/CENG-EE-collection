all: bin/b.out bin/a.out

bin/a.out: src/main.c src/BankAccount.c
	gcc src/main.c src/BankAccount.c -o ./bin/a.out

bin/b.out: src/fixed-badly-written-bank-account.c
	gcc src/fixed-badly-written-bank-account.c -o ./bin/b.out

test: bin/a.out bin/b.out
	./bin/a.out < ./tst/input.txt > ./tst/output_a.txt
	./bin/b.out < ./tst/input.txt > ./tst/output_b.txt
	diff ./tst/output_a.txt ./tst/output_b.txt -u
	
clean:
	rm ./bin/a.out ./bin/b.out ./tst/output_a.txt ./tst/output_b.txt
