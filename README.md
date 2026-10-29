# Sistemas Informáticos Industriales

![UPM](https://img.shields.io/badge/UPM-ETSIDI-red)
![Curso](https://img.shields.io/badge/Curso-2026--2027-blue)
![Lenguaje](https://img.shields.io/badge/C-Programming-00599C?logo=c)
![Linux](https://img.shields.io/badge/Linux-Ubuntu-E95420?logo=ubuntu)
![Git](https://img.shields.io/badge/Git-Version%20Control-F05032?logo=git)

Material docente de la asignatura **Sistemas Informáticos Industriales** de la **Escuela Técnica Superior de Ingeniería y Diseño Industrial (ETSIDI)** de la **Universidad Politécnica de Madrid (UPM)**.

---

## 📖 Descripción

Este repositorio contiene el material utilizado en las prácticas de la asignatura **Sistemas Informáticos Industriales**, incluyendo los guiones y el código de inicio.

El objetivo de la asignatura es introducir en el desarrollo de aplicaciones para sistemas informáticos industriales, haciendo especial énfasis en el uso del lenguaje C y del sistema operativo Linux.

---

## 📚 Wiki

La documentación detallada de cada una de las prácticas se encuentra en la Wiki del repositorio.

➡️ **Acceso a la Wiki:**  
https://github.com/raquelcedazo/sistemas-informaticos-industriales/wiki

---

## 🎓 Profesorado

Asignatura impartida por el **Departamento de Ingeniería Eléctrica, Electrónica, Automática y Física Aplicada** de la **Universidad Politécnica de Madrid**:

- **Raquel Cedazo** *(coordinadora de las prácticas)*
- **David Álvarez**
- **Imanol Izcara**

---

## 🤝 Contribuciones

Este repositorio tiene finalidad exclusivamente docente.

Si detectas algún error o tienes alguna sugerencia de mejora, puedes comunicarlo al profesorado de la asignatura.


**Practica 1**: Entorno de desarrollo Linux
Esta practica consiste en configurar el entorno de desarrollo en Linux, utilizar Git para controlar las versiones, compilar y ejecutar un programa en C++
Modificaremos el codigo del ./tenis y le daremos movimiento a las raquetas y la esfera.


**Practica 2** 
Comunicación mediante tuberías con nombre (FIFO)
Esta practica usamos dos procesos mediante una tubería con nombre (FIFO).
Se ha añadido un nuevo programa, ./logger, que crea la tubería "tenis_fifo", la abre en modo lectura y muestra por pantalla los mensajes que recibe. Cada vez que un jugador marca un punto, el programa ./tenis envía por la tubería el jugador que ha marcado y el total de puntos que lleva.
La partida termina cuando uno de los jugadores alcanza 3 puntos: ./tenis cierra la tubería y finaliza, y ./logger detecta el cierre, borra la tubería y también finaliza.
Si se crease mal la tuberia o se abriese antes ./tenis que ./logger, da un error. 
Para ejecutarlo, hay que lanzar primero el logger y después el tenis, ambos desde la carpeta build:
    ./logger
    ./tenis
    
    
**Practica 3**
Comunicación mediante ficheros proyectados en memoria
En esta práctica se añade un tercer proceso, ./bot, que controla de forma automática la raqueta del jugador 1. La comunicación entre ./tenis y ./bot se realiza mediante un fichero proyectado en memoria (mmap).
Se ha creado la clase DatosMemCompartida (include/DatosMemCompartida.h), que contiene la esfera, la raqueta1 y la acción a realizar (1 arriba, 0 nada, -1 abajo). El programa ./tenis crea el fichero /tmp/datosBot.txt, lo proyecta en memoria y, en cada ciclo, escribe en él la posición de la pelota y de la raqueta1. El programa ./bot abre ese mismo fichero, lo proyecta y cada 25 ms compara la altura de la pelota con el centro de la raqueta para decidir la acción. ./tenis lee la acción y mueve la raqueta1 en consecuencia.
Cuando ./tenis termina, elimina la proyección y borra el fichero. El ./bot no finaliza solo: hay que pararlo con Ctrl+C.
Si se lanza ./bot antes que ./tenis da un error, porque el fichero todavía no existe.
Para ejecutarlo, hay que lanzar primero el logger, después el tenis y por último el bot, desde la carpeta build:
    ./logger
    ./tenis
    ./bot
