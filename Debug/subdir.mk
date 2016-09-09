################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../articulo.cpp \
../articulocontroller.cpp \
../articulodao.cpp \
../articulonode.cpp \
../articuloqueue.cpp \
../articuloviewer.cpp \
../cliente.cpp \
../clientecontroller.cpp \
../clientedao.cpp \
../clientenode.cpp \
../clientequeue.cpp \
../clienteviewer.cpp \
../main.cpp \
../menucontroller.cpp \
../menuviewer.cpp \
../myconnection.cpp \
../tipo.cpp \
../tipocontroller.cpp \
../tipodao.cpp \
../tiponode.cpp \
../tipoqueue.cpp \
../tipoviewer.cpp \
../venta.cpp \
../ventacontroller.cpp \
../ventadao.cpp \
../ventadetalle.cpp \
../ventadetalledao.cpp \
../ventadetallenode.cpp \
../ventadetallequeue.cpp \
../ventaviewer.cpp 

OBJS += \
./articulo.o \
./articulocontroller.o \
./articulodao.o \
./articulonode.o \
./articuloqueue.o \
./articuloviewer.o \
./cliente.o \
./clientecontroller.o \
./clientedao.o \
./clientenode.o \
./clientequeue.o \
./clienteviewer.o \
./main.o \
./menucontroller.o \
./menuviewer.o \
./myconnection.o \
./tipo.o \
./tipocontroller.o \
./tipodao.o \
./tiponode.o \
./tipoqueue.o \
./tipoviewer.o \
./venta.o \
./ventacontroller.o \
./ventadao.o \
./ventadetalle.o \
./ventadetalledao.o \
./ventadetallenode.o \
./ventadetallequeue.o \
./ventaviewer.o 

CPP_DEPS += \
./articulo.d \
./articulocontroller.d \
./articulodao.d \
./articulonode.d \
./articuloqueue.d \
./articuloviewer.d \
./cliente.d \
./clientecontroller.d \
./clientedao.d \
./clientenode.d \
./clientequeue.d \
./clienteviewer.d \
./main.d \
./menucontroller.d \
./menuviewer.d \
./myconnection.d \
./tipo.d \
./tipocontroller.d \
./tipodao.d \
./tiponode.d \
./tipoqueue.d \
./tipoviewer.d \
./venta.d \
./ventacontroller.d \
./ventadao.d \
./ventadetalle.d \
./ventadetalledao.d \
./ventadetallenode.d \
./ventadetallequeue.d \
./ventaviewer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


