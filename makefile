#
# Makefile: Final Project
#

SCC = scrc

SCCOPT  = -vv -ww -g

all: tb

tb: tb.sc io/*.sc communication/*.sc sensors/*.sc processing/*.sc
	$(SCC) tb $(SCCOPT)

clean:
	-rm -f *~ *.o *.cc *.h
	-rm -f *.si
