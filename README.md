# Proyecto BioControl 360: Inteligencia Artificial y Automatización para la Agricultura y Entornos Sostenibles
Alumnos: Mario Yahir García Hernández, Oscar Correa Saenz, Victor Hugo Mejía Trejo

**Descripción del Proyecto: EcoAI - Sistema Inteligente de Gestión Automatizada para Invernaderos y Entornos Controlados**

El proyecto consiste en el diseño e implementación de un sistema de control automatizado para invernaderos, que integra tecnologías de comunicación inalámbrica, dispositivos electrónicos avanzados y una inteligencia artificial para monitorear y controlar de manera eficiente y precisa el ambiente interno del invernadero. Además de optimizar las condiciones ambientales, el sistema se adapta a otros entornos controlados, como hábitats de animales y peceras, lo que amplía su aplicabilidad y utilidad.

**Objetivos del Proyecto:**

1. **Optimización de Recursos en Invernaderos:** Desarrollar un sistema automatizado que ajuste continuamente los niveles de temperatura, humedad y luminosidad dentro del invernadero, utilizando controladores PID y sensores precisos, para asegurar condiciones óptimas para el crecimiento de las plantas y reducir el consumo de recursos.

2. **Implementación de Inteligencia Artificial para la Detección y Monitoreo:** Incorporar una inteligencia artificial capaz de analizar imágenes capturadas por una cámara, para identificar el tipo de planta, su estado de crecimiento, y la presencia de enfermedades o plagas. Basado en esta información, el sistema ajustará automáticamente los parámetros ambientales para maximizar la productividad y salud de las plantas.

3. **Escalabilidad y Adaptabilidad Multisectorial:** Extender la funcionalidad del sistema para su uso en diversos entornos controlados, como hábitats para animales, peceras, y entornos personalizados para humanos. Esto incluye la personalización de los algoritmos de control y la IA según las necesidades específicas de cada aplicación.

4. **Sustentabilidad Energética:** Implementar un modelo de control que minimice el uso de agua y energía, promoviendo una agricultura más sostenible y eficiente, así como un manejo optimizado de otros entornos controlados.

**Componentes del Sistema:**

- **ESP32 y ESP-NOW:** El sistema utiliza microcontroladores ESP32 para la comunicación inalámbrica entre los diferentes dispositivos dentro del invernadero o entorno controlado. La tecnología ESP-NOW permite la transmisión de datos de manera eficiente y confiable entre los nodos del sistema.

- **Sensores Ambientales:** Se emplean sensores de temperatura, humedad (SHT1x) y luminosidad (LM393) para monitorear las condiciones ambientales dentro del invernadero. Estos sensores proporcionan datos en tiempo real que son utilizados para tomar decisiones de control.

- **Actuadores:** El sistema cuenta con actuadores para controlar diferentes dispositivos dentro del invernadero, como bombas de agua, ventiladores y servomotores. Estos actuadores son controlados de manera remota para ajustar las condiciones ambientales según sea necesario.

- **Cámara y Algoritmos de IA:** Se utiliza una cámara para capturar imágenes de las plantas, las cuales son procesadas por algoritmos de inteligencia artificial. Esta IA analiza el tipo de planta, su estado de crecimiento y detecta posibles enfermedades o plagas, permitiendo ajustes precisos en los parámetros de control.

- **Controlador PID:** Se implementa un controlador proporcional integral derivativo (PID) para regular la temperatura y la humedad dentro del invernadero. El PID ajusta automáticamente la salida de los actuadores para mantener las condiciones ambientales dentro de los valores deseados.

**Funcionamiento del Sistema:**

- **Monitoreo Continuo:** Los sensores ambientales realizan mediciones periódicas de temperatura, humedad y luminosidad dentro del invernadero. Estos datos son enviados a través de la red ESP-NOW a un nodo central para su procesamiento.

- **Procesamiento y Control:** El nodo central procesa los datos recibidos y utiliza un algoritmo de control PID, junto con la inteligencia artificial, para calcular la acción de control necesaria. Esta acción de control se envía a los actuadores correspondientes para ajustar las condiciones ambientales según sea necesario.

- **Comunicación Bidireccional:** El sistema permite una comunicación bidireccional, lo que significa que no solo se reciben datos de los sensores, sino que también se pueden enviar comandos de control a los actuadores. Esto permite una respuesta rápida y efectiva ante cambios en las condiciones ambientales.

- **Optimización Automatizada:** El sistema busca constantemente optimizar las condiciones ambientales dentro del invernadero y otros entornos controlados para promover un crecimiento saludable de las plantas, animales u otros seres vivos. Se realizan ajustes automáticos en tiempo real para mantener las condiciones dentro de los rangos óptimos predefinidos.

        
