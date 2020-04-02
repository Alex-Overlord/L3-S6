#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

/* Rôle du serveur (attention, se serveur ne traite qu'un client !) :
 -  accepter la demande de connexion d'un client ;

 - en boucle (infinie) : 1) recevoir un message de type "long int" ;
   2) comparer sa valeur avec la précédente reçue ; 3) si la valeur
   reçue est inférieure à la précédente, afficher une trace notifiant
   ce cas; 4) dans tous les cas, afficher le nombre total d'octets
   reçus depuis le début et le nombre d'appels à la fonction recv(...)

 - termine apres départ du client.

*/


/* Réutiliser les fonctions de l'exercice 3 du TP précédent */
/* les deux derniers parametres sont les compteurs, auxquels doit s'ajouter le nombre d'octets
   lus depuis le buffer de réception et le nombre d'appels reussis à recv(..)
   (ils sont initialisés par l'appelant.*/
/* Si vous avez utilisé des variables globales, pas de souci. */
int recvTCP(int socket, char *buffer, size_t length, unsigned int *nbBytesReceved, unsigned int * nbCallRecv){

  // ce squelette est juste pour vous indiquer où et comment utiliser
  // les paramètres en plus. C'est à vous de savoir comment l'adapter à vote code.
	...
    while (....){
  
      received = recv(.....);

      if(received <= 0){
        return received;
      }
      
      ....
	
      (*nbBytesReceved)+=received;
      (*nbCallRecv)++;
    }
    return 1;
}


int main(int argc, char *argv[])
{
	 
  
  if (argc<2){
    printf("utilisation: %s numero_port\n", argv[0]);
    exit(1);
  }
  
  /*  Création de la socket d'écoute, nomage et mise en écoute.*/
 
  int ds = socket(...);


  ...


  // Penser à tester votre code progressivement.

  // Rappel un seul client est à traiter.
  printf("Serveur : j'attends la demande du client (accept) \n"); 
  
  ...

  int dsCv = accept(ds,...);

  ...
 
  printf("Serveur: le client %s:%d est connecté  \n", ...);

 
 
  /* Réception de messages, chaque message est un long int */
 
  long int messagesRecus[2];   // je defini ce tableau pour garder le
			       // message précédent (voir plus bas)


  unsigned int nbTotalOctetsRecus = 0;
  unsigned int nbAppelRecv = 0;

  // recevoir un premier message puis mettre en place la boucle de
  // réception de la suite.


  int rcv = recvTCP (dsCv, (char*)messagesRecus, sizeof(long int), &nbTotalOctetsRecus, &nbAppelRecv);  

    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
   ...
  
  
    printf("Serveur : j'ai reçu au total %d octets avec %d appels à recv \n", nbTotalOctetsRecus, nbAppelRecv);

    /* ce code commenté vous sera utile pour quelques tests. 
    printf("Serveur : saisir un caractère avant de poursuivre \n");
    fgetc(stdin);
    */
    
    while(1){ // le serveur n'a pas connaissance du nombre de messages
	      // qu'il recevra, donc, il boucle et la gestion des
	      // valeurs de retours de fonctions permettra de sortir
	      // de la boucle pour arrêter le serveur.
    
      rcv = recvTCP (dsCv, (char*)(messagesRecus+1) , sizeof(long int), &nbTotalOctetsRecus, &nbAppelRecv);  

    /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
   ...

    if(messagesRecus[1] < messagesRecus[0]) // si la valeur reçue est inférieure à la précédente, alors désordre.
      printf("Serveur : reception dans le désordre : %ld reçu après %ld \n", messagesRecus[1], messagesRecus[0]);

    /* garder la valeur précédente pour la prochaine comparaison*/
    messagesRecus[0] = messagesRecus[1];
  
   printf("Serveur : j'ai reçu au total %d octets avec %d appels à recv \n", nbTotalOctetsRecus, nbAppelRecv);
 
  }
  
    // terminer proprement votre programme
    ...
  printf("Serveur : fin du dialogue avec le client\n");
  

  ...
  printf("Serveur : je termine\n");
}








