/*
Envoi d'une trame courante vers la passerelle
*/

// Numéros de Pin
#define   SIZE_ENVOI  17
#define   SIZE_RECEP  15

// variables globales
char  Conv_hexToAsc(char digH);               // définition de la fonction de conversion d'un chiffre hexa en code ASCII
void  Envoi_Trame(int valcapt, int typeCapt); // définition de la fonction d'envoi d'une trame
void  Recep_Trame(void);                      // définition de la fonction de réception d'une trame
void  Wait_CleSonore(void);                   // fonction qui attend la clé sonore

char  TrameEnvoi[20];   // buffer pour envoyer  une trame vers la passerelle
char  TrameRecep[20];   // buffer pour recevoir une trame venant de la passerelle
char  CheckSum;

void setupBluetooth() {
  Serial.println("Initialise Bluetooth");
  Serial1.begin(9600); // Initialisation de la sortie Bluetooth


  // Partie constante de la trame 
  TrameEnvoi[0] = '1';  // le champ TRA. choisir toujours "Trame courante = 1"
  // le champ OBJ (4 octets) = numero de groupe. ex 007A 007B ...
  TrameEnvoi[1] = 'G';  // mettre le chiffre du numero de groupe (G)
  TrameEnvoi[2] = '8';  // mettre le chiffre du numero de groupe (8)
  TrameEnvoi[3] = '-';  // mettre le chiffre du numero de groupe (-)
  TrameEnvoi[4] = 'C';  // mettre la lettre  du numero de groupe (A, B, ... E)
  TrameEnvoi[5] = '1';  // champ REQ. 1= Requete en ecriture
  TrameEnvoi[7] = '0';  // champ NUM (2 octets). Numero du capteur
  TrameEnvoi[8] = '1';  // On choisit par exemple le numero 01.
  TrameEnvoi[13] = 'B'; // Champ TIM (4 octets) = heure d'envoi de la trame
  TrameEnvoi[14] = 'A'; // Ce champ n'est pas utilisé par la passerelle; donc
  TrameEnvoi[15] = 'B'; // on peut mettre la valeur qu'on veut
  TrameEnvoi[16] = 'A';
}


//---------------------------------
void Envoi_Trame(int valcapt, int typeCapt) {
//---------------------------------
  /*
   * valcapt : entier compris entre 0 et 65 535
   */
 int n;  char digH, digA;  // digit (4 bits) Hexa et Ascii

  TrameEnvoi[6] = typeCapt; // type capteur
  // convertir la valeur du capteur en 4 chiffres ASCII (poid fort en premier)
  TrameEnvoi[9] = Conv_hexToAsc((valcapt >> 12) & 0x0F); // conversion du 1er chiffre (poid fort) (>> signifie décalage de 12 bits vers la droite)
  TrameEnvoi[10] = Conv_hexToAsc((valcapt >> 8) & 0x0F); // conversion du 2e chiffre (décalage de 8 bits vers la droite)
  TrameEnvoi[11] = Conv_hexToAsc((valcapt >> 4) & 0x0F); // conversion du 3e chiffre (décalage de 4 bits vers la droite)
  TrameEnvoi[12] = Conv_hexToAsc(valcapt & 0x0F); // conversion du 4e chiffre (poid faible) (pas besoin de décalage. garder juste le dernier digit)

  Serial.print("   (Trame ");
  CheckSum = 0;
  for (n = 0; n < SIZE_ENVOI; n++) { //  boucle pour envoyer une trame vers la passerelle : envoi des 'SIZE_ENVOI' premiers octets
    Serial.print(TrameEnvoi[n]);
    Serial1.print(TrameEnvoi[n]);
    CheckSum = CheckSum + TrameEnvoi[n];
  }
  digA = Conv_hexToAsc((CheckSum >> 4) & 0x0F); // poid fort du CheckSum
  Serial.print(digA);       // envoi du poid fort
  Serial1.print(digA);
  digA = Conv_hexToAsc(CheckSum & 0x0F); // poid faible du CheckSum
  Serial.print(digA);       // envoi du poid faible
  Serial1.print(digA);
  Serial.println(")");       // retour à la ligne
}

//---------------------------------
char  Conv_hexToAsc(char digH){
//---------------------------------
 char valAsc;

  digH &= 0x0F;   // garder que les 4 bits de poid faible = 1 chiffre hexa (0 à 15)
  valAsc = digH + 0x30;
  if (digH > 9)
    valAsc += 0x07;
  return valAsc;
}

void  Recep_Trame(void) {
//---------------------------------
//---------------------------------
  // boucle d'attente de  "SIZE_RECEP" octets dans le buffer TrameRecep[]
  // avant chaque lecture d'un octet, vérifier que le port de réception 
  // contient un octet en attente.
}


void  Wait_CleSonore(void) {
//---------------------------------
//---------------------------------
  // Copier ici le code de test de la clé sonore
}

/*
TrameEnvoi[6] = ;   // champ TYP. remplir dans la boucle (voir Doc)
TrameEnvoi[ 9] = 1;    // Champ VAL (4 octets) = valeur à envoyer au site web
TrameEnvoi[10] = 9;    // par exemple la valeur du capteur de lumiere
TrameEnvoi[11] = 9;
TrameEnvoi[12] = 9;
TrameEnvoi[17] = ;    // premier  chiffre (poid fort)   du checksum
TrameEnvoi[18] = ;    // deuxieme chiffre (poid faible) du checksum
 */
