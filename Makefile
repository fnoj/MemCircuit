MEMCIRCUITDIR = ./
TARGET = MemCircuit
CXX = g++
CFLAGS = -c -Wall `root-config --cflags` -I./inc/
LFLAGS =  `root-config --glibs` -lXMLIO
INCDIR = $(MEMCIRCUITDIR)/inc
SRCDIR = $(MEMCIRCUITDIR)/src


LIBS = TCirDevice.o TVoltage.o TWire.o VSave.o
GUIOBJ = WCCapacitor.o WCInductor.o WCGraphs.o WCResistor.o WCMemristor.o WCMemcapacitor.o WCMeminductor.o WCProcessing.o WMainApp.o

HEADERS = $(INCDIR)/TCirDevice.h $(INCDIR)/TVoltage.h  $(INCDIR)/TWire.h  $(INCDIR)/VSave.h $(INCDIR)/WCCapacitor.h  $(INCDIR)/WCInductor.h  $(INCDIR)/WCGraphs.h  $(INCDIR)/WCResistor.h  $(INCDIR)/WCMemristor.h  $(INCDIR)/WCMemcapacitor.h  $(INCDIR)/WCMeminductor.h  $(INCDIR)/WCProcessing.h $(INCDIR)/WMainApp.h

all : $(TARGET)

$(TARGET) : $(LIBS) $(GUIOBJ) Dict.o MemCircuit.o
	$(CXX) -o $(TARGET) $^ $(LFLAGS)

MemCircuit.o : MemCircuit.cxx
	$(CXX) $(CFLAGS) -c $< -o $@

Dict.cxx : $(HEADERS)
	@rootcint -f Dict.cxx -c $^

Dict.o : Dict.cxx
	$(CXX) $(CFLAGS) -c $< -o $@

# Compilar cada clase
%.o : $(SRCDIR)/%.cxx $(INCDIR)/%.h
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f *.o Dict.cxx Dict.h

install: 
	cp MemCircuit ~/Desktop
