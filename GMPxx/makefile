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
	$(CXX) -Llib/ -lgmpxx -o $@ $+ 

$(OBJDIR)BigInt.o: BigInt.cxx
	$(CXX) -fPIC -o $@ -c $+
	
$(LIBDIR)libgmpxx.so: $(OBJDIR)BigInt.o
	$(CXX) -shared -lgmp -o $@ $+


clean:
	rm -rf $(OBJDIR) $(LIBDIR)	
