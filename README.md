# Proyecto_Intrumentacion
Alumnos: Mario Yahir García Hernández, Oscar Correa Saenz, Victor Hugo Mejía Trejo

Descripción del Proyecto: Sistema de Control Automatizado para Invernadero

El proyecto consiste en el diseño e implementación de un sistema de control automatizado para un invernadero, que utiliza tecnologías de comunicación inalámbrica y dispositivos electrónicos para monitorear y controlar el ambiente interno del invernadero de manera eficiente y precisa.

Objetivo:
El objetivo principal del sistema es optimizar las condiciones ambientales dentro del invernadero para promover un crecimiento saludable de las plantas, asegurando un adecuado nivel de temperatura, humedad y luminosidad.

Componentes del Sistema:
ESP32 y ESP-NOW: El sistema utiliza microcontroladores ESP32 para la comunicación inalámbrica entre los diferentes dispositivos dentro del invernadero. La tecnología ESP-NOW permite la transmisión de datos de manera eficiente y confiable entre los nodos del sistema.

Sensores Ambientales: Se utilizan sensores de temperatura, humedad (SHT1x) y luminosidad (LM393) para monitorear las condiciones ambientales dentro del invernadero. Estos sensores proporcionan datos en tiempo real que son utilizados para tomar decisiones de control.

Actuadores: El sistema cuenta con actuadores para controlar diferentes dispositivos dentro del invernadero, como bombas de agua, ventiladores y servomotores. Estos actuadores son controlados de manera remota para ajustar las condiciones ambientales según sea necesario.

Controlador PID: Se implementa un controlador proporcional integral derivativo (PID) para regular la temperatura y la humedad dentro del invernadero. El PID ajusta automáticamente la salida de los actuadores para mantener las condiciones ambientales dentro de los valores deseados.

Funcionamiento del Sistema:
Monitoreo Continuo: Los sensores ambientales realizan mediciones periódicas de temperatura, humedad y luminosidad dentro del invernadero. Estos datos son enviados a través de la red ESP-NOW a un nodo central para su procesamiento.

Procesamiento y Control: El nodo central procesa los datos recibidos y utiliza un algoritmo de control PID para calcular la acción de control necesaria. Esta acción de control se envía a los actuadores correspondientes para ajustar las condiciones ambientales según sea necesario.

Comunicación Bidireccional: El sistema permite una comunicación bidireccional, lo que significa que no solo se reciben datos de los sensores, sino que también se pueden enviar comandos de control a los actuadores. Esto permite una respuesta rápida y efectiva ante cambios en las condiciones ambientales.

Optimización Automatizada: El sistema busca constantemente optimizar las condiciones ambientales dentro del invernadero para promover un crecimiento saludable de las plantas. Se realizan ajustes automáticos en tiempo real para mantener las condiciones dentro de los rangos óptimos predefinidos.

        
