CXX = g++

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS = main.o articulo.o articulocontroller.o articulodao.o articulonode.o articuloqueue.o articuloviewer.o cliente.o clientecontroller.o clientedao.o clientenode.o clientequeue.o clienteviewer.o menucontroller.o menuviewer.o myconnection.o tipo.o tipocontroller.o tipodao.o tiponode.o tipoqueue.o tipoviewer.o venta.o ventacontroller.o ventadao.o ventadetalle.o ventadetalledao.o ventadetallenode.o ventadetallequeue.o ventaviewer.o

LIBS =

TARGET = kiosco

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
