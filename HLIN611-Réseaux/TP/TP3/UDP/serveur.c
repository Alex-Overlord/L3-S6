#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

/* Rôle du serveur :

   - en boucle (infinie) : 1) recevoir un message de type "long int" ;
   2) afficher l'adresse de la socket de l'éméteur, 3) comparer sa
   valeur avec la précédente reçue ; 3) si la valeur reçue est
   inférieure à la précédente, afficher une trace notifiant ce cas
   (arrivée de message dans le désorde); 4) dans tous les cas, afficher
   le nombre total d'octets reçus depuis le début et le nombre
   d'appels à la fonction recvfrom(...)

*/

int main(int argc, char *argv[])
{
	 
  // je passe en paramètre un numero de port pour la socket du serveur
  
  if (argc<2){
    printf("utilisation: %s numero_port\n", argv[0]);
    exit(1);
  }
  
  /* Créer une socket */
 
  int ds = socket(...);
  
  ...
  printf("Serveur: creation de la socket : ok\n");


  // Je peux déjà tester l'exécution de cette étape avant de passer à la suite.

  // nommage
 
  ...
  
 
  printf("Serveur: nommage : ok\n");

  // Je peux tester l'exécution de cette étape avant de passer à la suite.
 
  /* Réception des messages : chaque message est un long int */
 
  long int messagesRecus[2]; 


  unsigned int nbTotalOctetsRecus = 0;
  unsigned int nbAppelRecvfrom = 0;


  // variables utilisées pour récupérer l'adresse de l'expéditeur/ client.
  struct sockaddr_in addrC ;
  socklen_t lgAddrC = sizeof(struct sockaddr_in) ;
  
  // recevoir un premier message puis mettre en place la boucle de
  // réception de la suite.

  printf("Serveur: j'attends de recevoir un premier message\n");
  int rcv = recvfrom ( ...);
    
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation) */
  ...

  // qui a envoyé le message reçu ? 
  printf("Serveur: le client %s:%d m'a envoyé un message  \n", inet_ntoa(addrC.sin_addr),  ntohs(addrC.sin_port));
  
  nbTotalOctetsRecus = ...;
  nbAppelRecvfrom = ...;
  printf("Serveur : j'ai reçu au total %d octets avec %d appels à recvfrom \n", nbTotalOctetsRecus, nbAppelRecvfrom);

  /* ce code commenté sera utile en temps venu
  printf("Serveur : saisir un caractère avant de poursuivre \n");
  fgetc(stdin);
  */
  
  while(1){ // le serveur n'a pas connaissance du nombre de messages
    // qu'il recevra, d'où la boucle infinie.

    rcv = recvfrom (...);  

    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
    ...

    // qui a envoyé le message reçu ? 
    printf("Serveur: le client %s:%d m'a envoyé un message  \n", ...);
    
    if(messagesRecus[1] < messagesRecus[0]) // si la valeur reçue est inférieure à la précédente, alors désordre.
      printf("Serveur : reception dans le désordre : %ld reçu après %ld \n", messagesRecus[1], messagesRecus[0]);

    /* garder la valeur précédente pour la prochaine comparaison*/
    messagesRecus[0] = messagesRecus[1];
    nbTotalOctetsRecus = ..;
    nbAppelRecvfrom = ..;
    
    printf("Serveur : j'ai reçu au total %d octets avec %d appels à recvfrom \n", nbTotalOctetsRecus, nbAppelRecvfrom);
 
  }
  
  /* je termine proprement */ 
  ...
  printf("Serveur : je termine\n");
}








