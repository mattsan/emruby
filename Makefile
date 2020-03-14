MRUBY_LIB_DIR=/usr/local/opt/mruby/lib
CFLAGS= -fPIC -shared -undefined dynamic_lookup -I$(ERL_EI_INCLUDE_DIR) -L$(MRUBY_LIB_DIR) -lmruby

TARGET=$(MIX_APP_PATH)/priv/mruby.so
SOURCES=c_src/mruby.cpp

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	 g++ $(CFLAGS) -o $(TARGET) $(SOURCES)

.PHONY: all clean
