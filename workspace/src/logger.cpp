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
    const char * ruta = "/tmp/tuberia_tenis";

    // borrar FIFO por si existiera previamente
    unlink(ruta);

    /* crear el FIFO */
    if (mkfifo(ruta,0666)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    if ((fd = open(ruta, O_RDONLY)) < 0) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while (read (fd,buffer,sizeof(buffer))>0) {
	// X5: Imprimir el texto en la pantalla
	printf("%s",buffer);
    }
    close(fd);
    unlink(ruta);
    return(0);
}
