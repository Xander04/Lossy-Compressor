CC = g++
CFLAGS = -std=c++17

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
	cp LossyCompressor /usr/local/bin/
	rm -f $(OBJDIR)/*.o $(TARGET)
	$(warning **WARNING THIS IS A MEME PROGRAM, IT WILL OVERWRITE THE TARGET FILE**)
remove:
	rm /usr/local/bin/LossyCompressor