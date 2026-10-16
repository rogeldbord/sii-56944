#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char **argv) {
    int fd;
    char buffer[1024];

    // borrar FIFO por si existiera previamente
    unlink("tenis_fifo");

    /* crear el FIFO */
    if (mkfifo("tenis_fifo", 0666)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO en solo lectura*/
  if ((fd = open("tenis_fifo", O_RDONLY)) < 0) {
        perror("No puede abrirse el FIFO");
        unlink("tenis_fifo");   // limpiar el FIFO que ya creamos
        return(1);
    }
    /* Leer de la FIFO */
    while (read(fd, buffer, sizeof(buffer)) > 0) {
        // Imprimir el texto en la pantalla
        printf("%s\n", buffer);
    }
    close(fd);
    unlink("tenis_fifo");
    return(0);
}
