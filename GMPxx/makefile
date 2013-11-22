CC = clang
CXX = clang++
LIBDIR = lib/
OBJDIR = obj/

phony: $(LIBDIR) $(OBJDIR) $(LIBDIR)libgmpxx.so

$(LIBDIR):
	mkdir -p $@
$(OBJDIR):
	mkdir -p $@

test: test.cxx $(LIBDIR)libgmpxx.so
	$(CXX) -Llib/ -lgmpxx -o $@ $+ 

primetest: primetest.cxx
	clang++ -o primetest -lgmp prime.cxx BigInt.cxx primetest.cxx

$(OBJDIR)BigInt.o: BigInt.cxx $(LIBDIR) $(OBJDIR)
	$(CXX) -fPIC -o $@ -c $+
	
$(LIBDIR)libgmpxx.so: $(OBJDIR)BigInt.o
	$(CXX) -shared -lgmp -o $@ $+

install: 
	cp $(LIBDIR)libgmpxx.so /usr/lib64/libgmpxx.so

clean:
	rm -rf $(OBJDIR) $(LIBDIR)	
