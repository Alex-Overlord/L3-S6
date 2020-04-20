#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_BUFFER_SIZE 16000  // taille du buffer temporaire pour la lecture de fichier. Vous pouvez définir une autre valeur.

int main(int argc, char *argv[]) {
  
  if (argc != 4) {
    printf("utilisation : client ip_serveur port_serveur nom_fichier\n");
    exit(0);
  }

  // céer une socket  
  int ds = socket(PF_INET, SOCK_STREAM, 0);
  
  if (ds == -1) {
    perror("Client : pb creation socket\n");
    exit(1);
  }
  printf("Client : creation de la socket : ok \n");
  
  // demander une connexion au serveur
  struct sockaddr_in adrServ;
  adrServ.sin_addr.s_addr = INADDR_ANY ;
  adrServ.sin_family = AF_INET;
  adrServ.sin_port = htons(atoi(argv[2]));

  int lgAdr = sizeof(struct sockaddr_in);
  
  int co = connect(ds, (struct sockaddr*) &adrServ, lgAdr);

  if (co < 0) {
    perror("Client : probleme au connect :");
    close(ds);
    exit(1);
  }
  printf("Client : demande de connexion reussie \n");

  // envoyer le nom de fichier (réfléchir aux données à envoyer pour que le nom soit corectement reçu)
  int name_size = strlen(argv[3]) + 1;
  int sent = 0;
  
  sent = send(ds, name_size, sizeof(name_size), 0);
  if (sent < 0) {
    perror("Client : probleme au send (envoie de la taille du nom du fichier) :");
    close(ds);
    exit(1);
  }
  printf("Client :  taille du nom du fichier envoye \n");
  
  sent = send(ds, argv[3], name_size, 0);
  if (sent < 0) {
    perror("Client : probleme au send (envoie du nom du fichier) :");
    close(ds);
    exit(1);
  }
  printf("Client : nom du fichier envoye \n");
  
  // je construis le nom complet (chemin) du fichier que je dois lire
  char* filepath = malloc(strlen(argv[3]) + 16); // ./emission/+nom fichier +\0
  filepath[0] = '\0';
  strcat(filepath, "./emission/");
  strcat(filepath, argv[3]);

  printf("Client : je vais envoyer %s\n", filepath);

  // je récupère la taille du fichier. Pourquoi ?
  // -> pour que le client sache qu'il a reçu entièrement le fichier
  struct stat attributes;
  if (stat(filepath, &attributes) == -1) {
    perror("Client : erreur stat");
    free(filepath);
    close(ds);
    exit(1);
  }

  int file_size = attributes.st_size;  // c'est bon, j'ai obtenu la taille du fichier. Refléchir ce que je dois en fair.
  
  // envoyer la taille du fichier
  int file_size = strlen(argv[3]) + 1;
  sent = send(ds, file_size, sizeof(filz_size), 0);
  if (sent < 0) {
    perror("Client : probleme au send (envoie de la taille du fichier) :");
    close(ds);
    exit(1);
  }
  
  // pour envoyer le contenu, je dois lire le fichier :
  FILE* file = fopen(filepath, "rb"); // ouverture en lecture
  if (file == NULL) {
    perror("Client : erreur ouverture fichier \n");
    free(filepath);
    close(ds);
    exit(1);   
  }
  free(filepath); // je n'ai plus besoin de ce tableau dans la suite.

  // je fait une lecture par bloc.
  // je continue à lire tant que je n'ai pas lus le fichier en entier.
  int nbRead = 0
    
  while (nbRead < file_size) {
    
    char buffer[MAX_BUFFER_SIZE];
    size_t read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file);
    
    // je viens de tenter de lire un bloc d'au maximum MAX_BUFFER_SIZE octets
    if (read == 0) {
      if (ferror(file) != 0) {
	perror("Client : erreur lors de la lecture du fichier \n");
	fclose(file);
	close(ds); // on faire la socket
	exit(1);
      } // fin du fichier
      break; // plus rien à lire
    }
    // ici j'ai un bloc de read octets lus et stoqués dans buffer. Que faire de ce bloc d'octets ?
  
    //...
    
    //nbRead += ...;
  }

  // fermeture du fichier
  int resc = fclose(file);
  //...
 
  //printf("Client : j'ai envoye au total : %d octets,  envoyes en %d appels a send \n", ..., ...);  
  close(ds);
  printf("Client : je termine\n");
}
