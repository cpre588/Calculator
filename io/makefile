#
# Makefile: gps_test, alt_test, fuel_test
#

SCC = scrc

SCCOPT  = -vv -ww -g

all: gps_stim alt_stim fuel_stim

gps_stim: gps_stim.sc
	$(SCC) gps_stim $(SCCOPT)

alt_stim: alt_stim.sc
	$(SCC) alt_stim $(SCCOPT)

fuel_stim: fuel_stim.sc
	$(SCC) fuel_stim $(SCCOPT)

clean:
	-rm -f *~ *.o *.cc *.h
	-rm -f *.si
