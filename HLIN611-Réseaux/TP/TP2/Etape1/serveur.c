#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("utilisation : %s numero_port\n", argv[0]);
    exit(1);
  }
  
  /* Etape 1 : créer une socket (la socket qui permettra de recevoir
     les demandes de connexion. */
  int ds = socket(PF_INET, SOCK_STREAM, 0);
  if (ds == -1) {
    perror("Serveur : probleme creation socket");
    exit(1);
  }
  
  printf("Serveur : creation de la socket : ok\n");

  /* Etape 2 : nommer la socket. Elle aura une ou des IP de la machine
     sur laquelle le programme sera exécuté et le numéro de port passé
     en paramètre */
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(atoi(argv[1]));
  
  if (bind(ds, (struct sockaddr*) &server, sizeof(server)) < 0) {
    perror("Serveur : erreur bind");
    close(ds);
    exit(1);
  }

  printf("Serveur : nommage : ok\n");

  /* Etape 3 : mise en ecoute de la socket nommée. Cette opération
     dédie la socket à la réception des demandes de connexion. Pour
     cet exercice, limiter la file des demandes de connexions à 5. */
  int ecoute = listen(ds, 5);
  if (ecoute < 0) {
    printf("Serveur : je suis sourd(e)\n");
    close(ds);
    exit(1);
  } 
 
  printf("Serveur : mise en écoute : ok\n");
 
  /* etape 4 : attendre et traiter une demande de connexion d'un
     client. Rappel : lorsque le serveur accepte une demande de
     connexion, il crée une nouvelle socket. Cette dernière est
     connectée à celle du client et elle est à utiliser pour
     communiquer avec lui.*/
  printf("Serveur : j'attends la demande d'un client (accept) \n"); 
  
  struct sockaddr_in adCv;
  socklen_t lgCv = sizeof (struct sockaddr_in);

  int dsCv = accept(ds, (struct sockaddr*) &adCv, &lgCv);
  if (dsCv < 0) {
    perror("Serveur : probleme accept :");
    close(ds);
    exit(1);
  }
  printf("Serveur : le client %s:%d est connecté  \n", inet_ntoa(adCv.sin_addr),  adCv.sin_port);

  printf("Serveur : Arrêt de test, rentrez quelque chose : ");
  char stop[1500]; 
  fgets(stop, sizeof(stop), stdin);
  printf("Serveur : Vous avez saisi : %s", stop);
  
  /* Etape 5 : réception d'un message de type chaîne de caractères */
  char buffer[4000];
  int rcv1 = recv(dsCv, buffer, sizeof(buffer), 0) ;

  if (rcv1 <= 0) {
    printf("Serveur : je suis sourd(e)\n");
    close(rcv1);
    exit(1);
  } 

  /* Afficher le nombre d'octets EFFECTIVEMENT reçus. : /!\ Faire la
     différence entre le nombre d'octets qu'on demande à extraire
     depuis le buffer de réception d'une socket et le nombre d'octets
     qu'on a effectivement réussi à extraire.*/
  
  printf("Serveur : j'ai recu %d octets \n", rcv1);
  printf("Serveur : contenu du message : %s \n", buffer);

  // Je peux tester l'exécution de cette étape avant de passer à la suite.
  
  /* Etape 6 : répondre au client en lui envoyant le nombre d'octets
     effectivement reçus à l'étape 5. Pour cet exercice, faire un seul
     appel de la fonction send.*/ 
  int snd = send(dsCv, &rcv1,sizeof(int), 0);
  
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */

  if(snd <= 0){
    perror("Error :");
    close(snd);
    exit(1);
  }

    
  /* Etape 7 : fermeture de la socket du client */ 
  printf("Serveur : fin du dialogue avec le client\n");
  close (dsCv);
  
  // Etape 8 : pour cet exercice, je ne traite qu'un client, donc, je termine proprement.
  close (ds);
  printf("Serveur : je termine\n");
}
