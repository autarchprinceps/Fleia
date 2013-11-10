CC = clang
CXX = clang++
LIBDIR = lib/
OBJDIR = obj/

phony: $(LIBDIR) $(OBJDIR) $(LIBDIR)libgmpxx.so

$(LIBDIR):
	mkdir -p $@
$(OBJDIR):
	mkdir -p $@

test: test.cxx
	$(CXX) -Llib/ -lgmpxx -O3 -o $@ $+ 

$(OBJDIR)BigInt.o: BigInt.cxx
	$(CXX) -fPIC -O3 -o $@ -c $+
	
$(LIBDIR)libgmpxx.so: $(OBJDIR)BigInt.o
	$(CXX) -shared -lgmp -O3 -o $@ $+


clean:
	rm -rf $(OBJDIR) $(LIBDIR)	
