CC = g++
CFLAGS = -std=c++17 -Wall
LDFLAGS = -lmcpp

SRCDIR = src
OBJDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

TARGET = LossyCompressor

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

install:
	rm -r /usr/local/bin/LCsrc
	mkdir /usr/local/bin/LCsrc/
	cp LossyCompressor /usr/local/bin/
	cp src/pzwrfo3jbxc01.png /usr/local/bin/LCsrc/