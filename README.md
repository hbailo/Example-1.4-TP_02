# Utilización de clases BusIn y PortIn

Los botones A, B, C y D  cumplen la misma funcionalidad de ingreso de datos por el usuario y tienen la misma configuración de modo de entrada, i.e. Pull down. Se puede justificarse su agrupación en un único objeto para simplificar la lectura de los datos.

Los pines utilizados para los botones se indican en la siguiente tabla:

| **Button** | **Pin name** | **STM32 port** | **STM32 pin** |
|:----------:|:------------:|:--------------:|:-------------:|
|      A     |      D4      |        F       |       14      |
|      B     |      D5      |        E       |       11      |
|      C     |      D6      |        E       |       9       |
|      D     |      D7      |        F       |       13      |

Como se utilizan dos puertos distintos entonces se utiliza la clase BusIn para agruparlos.

## Ventajas
* Lectura simultánea.
* Simplificación del códigos.
* Consistencia en los datos al leer todos los pines.

## Desventajas
* Se puede utilizar un máximo de 16 pines.
* Misma configuración de modo entrada para todos los pines.
* Solo aplica a pines digitales.
