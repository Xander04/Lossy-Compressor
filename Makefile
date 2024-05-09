CC = g++
CFLAGS = -std=c++17
LDFLAGS = -lmcpp

SRCDIR = src
OBJDIR = obj

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
	cp LossyCompressor /usr/local/bin/
	rm -f $(OBJDIR)/*.o $(TARGET)
remove:
	rm /usr/local/bin/LossyCompressor