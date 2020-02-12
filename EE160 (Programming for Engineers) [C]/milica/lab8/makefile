

ROMAN = /inst/ee/ee160/ee160/Code.lect/Roman
CHAP4 = /inst/ee/ee160/ee160/Code.text/Chap4

roman: driver.o roman.o romanutil.o
	cc driver.o roman.o romanutil.o -o roman

driver.o: roman.h

roman.o: roman.h romanutil.h

romanutil.o: roman.h romanutil.h tfdef.h chrutil.h

links:
	ln -s -f $(ROMAN)/roman.c .
	ln -s -f $(ROMAN)/roman.h .
	ln -s -f $(ROMAN)/romanutil.c .
	ln -s -f $(ROMAN)/romanutil.h .
	ln -s -f $(ROMAN)/driver.c .
	ln -s -f $(CHAP4)/chrutil.h .
	ln -s -f $(CHAP4)/tfdef.h .

clean: 
	rm *.o

real_clean: clean
	rm roman

