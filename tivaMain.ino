
// ************ Definition des prototypes de fonctions ************
void afficheur();
void affichage(int Motifi[]);
void capteur_cardiaque();
void mesureCardio();
boolean mesureChangement(int ancienne, int nouvelle);
void capteur_temperature();
void signal_carre(int duree, int demi_periode);
void capeur_sonore();
void visuelAttendu();
void visuelInattendu();
unsigned long tempsReactionVisuelAttendu(int pinVisuel);
unsigned long tempsReactionVisuelInattendu(int pinVisuel);
char  Conv_hexToAsc(char digH);              
void  Envoi_Trame(int valcapt, int typeCapt); 
boolean TrameRecue();

char  TrameEnvoi[20];   // buffer pour envoyer  une trame vers la passerelle
char  TrameRecep[20];   // buffer pour recevoir une trame venant de la passerelle
char  CheckSum;


// ************ Definition des variables pour l'afficheur ************ 
#define NB_COL  5
#define NB_LIG  7
int Col[] = {10,9,8,6,5};  // Numéro des broches connectées aux colonnes de l'afficheur
int Lig[] = {38,37,36,35,34,33,13};  // Numéro des broches connectées aux lignes de l'affficheur

int Motif3[] =   { 1,1,1,1,0,   // Définition d'une matrice binaire représentant le caractère 
                   0,0,0,0,1,   // à afficher
                   0,0,0,0,1,
                   0,1,1,1,0,
                   0,0,0,0,1,
                   0,0,0,0,1,
                   1,1,1,1,0};


int Motif2[] =   { 1,1,1,1,0,   // Définition d'une matrice binaire représentant le caractère 
                   0,0,0,0,1,   // à afficher
                   0,0,0,0,1,
                   0,1,1,1,0,
                   1,0,0,0,0,
                   1,0,0,0,0,
                   0,1,1,1,1};

int Motif1[] =   { 0,0,1,0,0,   // Définition d'une matrice binaire représentant le caractère 
                   0,1,1,0,0,   // à afficher
                   1,0,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   1,1,1,1,1};

int Motif4[] =   { 0,0,1,0,0,   // Définition d'une matrice binaire représentant le caractère 
                   0,1,1,0,0,   // à afficher
                   1,0,1,0,0,
                   1,1,1,1,1,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0};

int Motif5[] =   { 0,1,1,1,1,   // Définition d'une matrice binaire représentant le caractère 
                   1,0,0,0,0,   // à afficher
                   1,0,0,0,0,
                   0,1,1,1,0,
                   0,0,0,0,1,
                   0,0,0,0,1,
                   1,1,1,1,0};

int Motif6[] =   { 0,1,1,1,1,   // Définition d'une matrice binaire représentant le caractère 
                   1,0,0,0,0,   // à afficher
                   1,0,0,0,0,
                   0,1,1,1,1,
                   1,0,0,0,1,
                   1,0,0,0,1,
                   0,1,1,1,0};

int Motif7[] =   { 1,1,1,1,1,   // Définition d'une matrice binaire représentant le caractère 
                   0,0,0,0,1,   // à afficher
                   0,0,0,0,1,
                   0,0,0,1,0,
                   0,0,1,0,0,
                   0,1,0,0,0,
                   1,0,0,0,0};

                   
// ************ Definition des variables pour le capteur cardiaque ************
int pinCardio = 24; // PD_1


// ************ Definition des variables pour le capteur de température ************
int pinT = 23; //PD_0
double temp = 0.0;
int brut = 0;
double res = 0.0;


// ************ Definition des variables pour le capteur de frequence sonore ************
int pinCasque = 19;

// ************ Definition des variables pour capteur visuel attendu / innatendu ************
int pinVisuelRed = 8; // PA_5
int pinVisuelGreen = 9; // PA_6
int pinVisuelBlue = 10; // PA_7
int pinBouton = 6; // PE_5



void setup()
{
  Serial.begin(9600);
  // ************ Initialisation des ports de commande de l'afficheur en sortie ************
  int i;
  for (i=0;i<NB_COL;i++){
    pinMode(Col[i], OUTPUT);
  }
    
  for (i=0;i<NB_LIG;i++){
    pinMode(Lig[i], OUTPUT);
  }
  // ************ Initialisation du pin du capteur cardiaque ************
  pinMode(pinCardio, INPUT);
  
  // ************ Initialisation du pin du capteur de température ************
  pinMode(pinT, OUTPUT);


  // ************ Initialisation du pin des capteurs de reaction ************
  pinMode(pinVisuelRed, OUTPUT);
  pinMode(pinVisuelGreen, OUTPUT);
  pinMode(pinVisuelBlue, OUTPUT);
  pinMode(pinBouton, INPUT);
  
  digitalWrite(pinVisuelRed, LOW);
  digitalWrite(pinVisuelGreen, LOW);
  digitalWrite(pinVisuelBlue, LOW);
  boolean done = false;
}





// ************ Action réalisées en boucle par le micro-controleur ************ 

void loop() {
  boolean done = false;
  if(done==false){
    done = true;
    int choix = 2;
    Serial.println("Voici le main programme \n");
    Serial.println("Choisissez le test que vous souhaitez passer \n");
    Serial.println("1) Test de fréquence cardiaque \n");
    Serial.println("2) Test de température \n");
    Serial.println("3) Test de reconnaissance sonore \n");
    Serial.println("4) Test de reflexe visuel attendu \n");
    Serial.println("5) Test de reflexe visuel innattendu \n");
    
    if(choix==1){
      affichage(Motif1);//Affichage id test
      delay(2000);
      afficheur(); //Compte à rebours
      capteur_cardiaque(); //Test de fréquence cardiaque
      }
    else if(choix==2){
      affichage(Motif2);//Affichage id test
      delay(2000);
      afficheur();//Compte à rebours
      capteur_temperature();//Test de température
      delay(1000);
      }
    else if(choix==3){
      affichage(Motif3);//Affichage id test
      delay(2000);
      afficheur();//Compte à rebours
      capeur_sonore();//Test de reconnaissance sonore
      }
    else if(choix==4){
      affichage(Motif4);//Affichage id test
      delay(2000);
      afficheur();//Compte à rebours
      visuelAttendu();
      }
    else if(choix==5){
      affichage(Motif5);//Affichage id test
      delay(2000);
      afficheur();//Compte à rebours
      visuelInattendu();
      }
    else if(choix==6){
      affichage(Motif6);//Affichage id test
      delay(2000);
      afficheur();//Compte à rebours
      visuelAttendu();//Dans le noir
      }
    else if(choix==7){
      affichage(Motif7);//Affichage id test
      delay(2000);
      afficheur();//Compte à rebours
      visuelInattendu();//Dans le noir
      }
   }
}

// ************ Appelle les différentes fonctions pour faire fonctionner l'afficheur ************ 
void afficheur(){
  int i;
  for (i=0;i<3000;i++){
    affichage(Motif3); //Affichage 3
  }
  
  for (i=0;i<3000;i++){
    affichage(Motif2); //Affichage 2
  }
  
  for (i=0;i<3000;i++){
    affichage(Motif1); //Affichage 1
  }
}

#define TEMP  10
// ************ Affiche une fois le tableau en fonction de la matrice qu'on lui donne
void affichage(int Motifi[]){
  int i,j;
  for (i=0;i<NB_LIG;i++){
    digitalWrite(Lig[i],LOW);  // Activation de la ligne i (les autres sont éteintes
    for(j=0;j<NB_COL;j++){
      digitalWrite(Col[j],Motifi[i*NB_COL+j]);  // Selon le code défini par le motif allumage de la led 
      delayMicroseconds(TEMP);
      digitalWrite(Col[j],LOW);                // de la colonne j puis extinction
      }
    digitalWrite(Lig[i],HIGH); // désactivation de la ligne i avant passage à la ligne suivante
    } 
}

// ************ Appelle les différentes fonctions pour faire fonctionner le capteur cardiaque ************
void capteur_cardiaque(){
  boolean done = false;
  Serial.println("Attention ...");
  delay(3000);
  Serial.println("Go !");
  delay(50);
  if (!done) {
    mesureCardio();
    done = false;
  }
  delay(5000);  
}


// ************ Mesure la fréquence cardiaque de l'individu et affiche sa valeur moyenne (bpm) ************
void mesureCardio(){
  int ancienne = 0;
  int nouvelle = 0;
  unsigned long moyenne = 0;
  double count = 0;
  unsigned long dureeMesure = 10 * 1000; // En secondes
  unsigned long start = millis(); // Temps début execution fonction
  unsigned long temps = millis();
  unsigned long startMesure = 0;
  boolean dejaMesureStart = false;
  while ((temps - start) < dureeMesure){
    nouvelle = digitalRead(pinCardio);
    if (mesureChangement(ancienne, nouvelle)){
      temps = millis();
      if (!dejaMesureStart){
        dejaMesureStart = true;
        startMesure = temps;
      }
      else {
        moyenne = temps;
      }
      count += 1.0;
      Serial.println("Boum");
      delay(10);
    }
    ancienne = nouvelle;
    delay(10);
    temps = millis();
  }
  count -= 1.0;
  moyenne -= startMesure;
  Serial.println("Total :"); Serial.println(moyenne);
  Serial.println("Counts :"); Serial.println(count);
  moyenne /= count;
  double moyenneBpm = 60000.0 / moyenne;
  Serial.println("Moyenne :"); Serial.println(moyenne);
  Serial.println("BPM :"); Serial.println(moyenneBpm);
}


// ************ Mesure le changement dans le signal (variation de 0 à 1) qui correspond à 1 bpm ************
boolean mesureChangement(int ancienne, int nouvelle){ // Detecte une variation 0 à 1
  if (ancienne > nouvelle) {
    return true;
  } else {
    return false;
  }
}


// ************ Appelle la fonction faisant fonctionner le capteur cardiaque ************
void capteur_temperature(){
  res = 0.0;
  
  brut = analogRead(pinT);
  temp = brut * (3.3/4095.0) * 100;
  res += temp;
  delay(50);
  
  brut = analogRead(pinT);
  temp = brut * (3.3/4095.0) * 100;
  res += temp;
  delay(50);
  
  brut = analogRead(pinT);
  temp = brut * (3.3/4095.0) * 100;
  res += temp;
  delay(50);
  
  brut = analogRead(pinT);
  temp = brut * (3.3/4095.0) * 100;
  res += temp;
  
  res /= 4;
  Serial.println(res);
  delay(50);
}

// ************ Fonction qui emet un son dans le casque ************
void signal_carre(int duree, int demi_periode) {
  int boucle = 0;
  while (boucle < duree) {
    digitalWrite(pinCasque, HIGH); // on passe le pin à  +5V
    delayMicroseconds(demi_periode);
    digitalWrite(pinCasque, LOW); // on passe le pin à  0V
    delayMicroseconds(demi_periode);
    boucle = boucle + 1;
  }
}


// ************ Appelle la fonction faisant fonctionner le capteur sonore ************
void capeur_sonore(){
  signal_carre(2000, 1000);
  delay(10000);
  signal_carre(4000, 500);
  delay(10000);
  signal_carre(3000, 750);
}

// ************ Appelle la fonction faisant fonctionner le capteur de reflexe visuel attendu ************
void visuelAttendu(){
  Serial.println("Rouge");
  unsigned long chronoRed = tempsReactionVisuelAttendu(pinVisuelRed);
  delay(3000);
  Serial.println("Vert");
  unsigned long chronoGreen = tempsReactionVisuelAttendu(pinVisuelGreen);
  delay(3000);
  Serial.println("Bleu");
  unsigned long chronoBlue = tempsReactionVisuelAttendu(pinVisuelBlue);
  delay(3000);
  Serial.println("Blanc");
  unsigned long chronoWhite = tempsReactionVisuelAttendu(-1);
  delay(3000);
}


// ************ Appelle la fonction faisant fonctionner le capteur de reflexe visuel inattendu ************
void visuelInattendu(){
  Serial.println("Rouge");
  unsigned long chronoRed = tempsReactionVisuelInattendu(pinVisuelRed);
  delay(3000);
  Serial.println("Vert");
  unsigned long chronoGreen = tempsReactionVisuelInattendu(pinVisuelGreen);
  delay(3000);
  Serial.println("Bleu");
  unsigned long chronoBlue = tempsReactionVisuelInattendu(pinVisuelBlue);
  delay(3000);
  Serial.println("Blanc");
  unsigned long chronoWhite = tempsReactionVisuelInattendu(-1);
  delay(3000);
}


// ************ Calcule le temps de reaction au stimulus sonore attendu ************
unsigned long tempsReactionVisuelAttendu(int pinVisuel) {
  
  Serial.println(3);
  delay(1000);
  Serial.println(2);
  delay(1000);
  Serial.println(1);
  delay(1000);
  
  unsigned long chrono = millis();
  if(pinVisuel == -1){
    digitalWrite(pinVisuelRed, HIGH);
    digitalWrite(pinVisuelGreen, HIGH);
    digitalWrite(pinVisuelBlue, HIGH);
  } else {
    digitalWrite(pinVisuel, HIGH);
  }
  while(digitalRead(pinBouton)){
    delay(1);
  }
  chrono = millis() - chrono;
  if(pinVisuel == -1){
    digitalWrite(pinVisuelRed, LOW);
    digitalWrite(pinVisuelGreen, LOW);
    digitalWrite(pinVisuelBlue, LOW);
  } else {
    digitalWrite(pinVisuel, LOW);
  }
  Serial.println(chrono);
  delay(10);
  return chrono;
}



// ************ Calcule le temps de reaction au stimulus sonore inattendu ************
unsigned long tempsReactionVisuelInattendu(int pinVisuel) {
  
  Serial.println(3);
  delay(1000);
  Serial.println(2);
  delay(1000);
  Serial.println(1);
  delay(1000);

  long tempsAttente = random(1,2000);
  delay(tempsAttente);
  
  //
  unsigned long chrono = millis();
  if(pinVisuel == -1){
    digitalWrite(pinVisuelRed, HIGH);
    digitalWrite(pinVisuelGreen, HIGH);
    digitalWrite(pinVisuelBlue, HIGH);
  } else {
    digitalWrite(pinVisuel, HIGH);
  }
  while(digitalRead(pinBouton)){
    delay(1);
  }
  chrono = millis() - chrono;
  if(pinVisuel == -1){
    digitalWrite(pinVisuelRed, LOW);
    digitalWrite(pinVisuelGreen, LOW);
    digitalWrite(pinVisuelBlue, LOW);
  } else {
    digitalWrite(pinVisuel, LOW);
  }
  Serial.println(chrono);
  delay(10);
  return chrono;
}

void Envoi_Trame(int valcapt, int typeCapt) {

 int n;  char digH, digA;  // digit (4 bits) Hexa et Ascii

  TrameEnvoi[6] = typeCapt; // type capteur
  // convertir la valeur du capteur en 4 chiffres ASCII (poid fort en premier)
  TrameEnvoi[9] = Conv_hexToAsc((valcapt >> 12) & 0x0F); // conversion du 1er chiffre 
  TrameEnvoi[10] = Conv_hexToAsc((valcapt >> 8) & 0x0F); // conversion du 2e chiffre
  TrameEnvoi[11] = Conv_hexToAsc((valcapt >> 4) & 0x0F); // conversion du 3e chiffre
  TrameEnvoi[12] = Conv_hexToAsc(valcapt & 0x0F); // conversion du 4e chiffre

  CheckSum = 0;
  for (n = 0; n < 17; n++) { //  boucle pour envoyer une trame vers la passerelle : envoi des 'SIZE_ENVOI' premiers octets
    Serial1.print(TrameEnvoi[n]);
    CheckSum = CheckSum + TrameEnvoi[n];
  }
  digA = Conv_hexToAsc((CheckSum >> 4) & 0x0F);
  // envoi du premier chiffre du checksum
  Serial1.print(digA);
  digA = Conv_hexToAsc(CheckSum & 0x0F);
  // envoi du deuxieme chiffre du checksum
  Serial1.print(digA);
}

char  Conv_hexToAsc(char hexa){
  char ascii;
  hexa &= 0x0F;   // garder que les 4 bits de poid faible = 1 chiffre hexa (0 à 15)
  ascii = hexa + 0x30;
  if (hexa > 9)
    ascii += 0x07;
  return ascii;
}

boolean TrameRecue(){
  int check = 0;
  for (i = 0 ; i < 13 ; i++){
    if(TrameEnvoi[i]!=TrameRecep[i]){
      return false;
    }
    if (TrameEnvoi[i]=='A'){
      check+=10;
    }
    else if (TrameEnvoi[i]=='B'){
      check+=11;
    }
    else if (TrameEnvoi[i]=='C'){
      check+=12;
    }
    else if (TrameEnvoi[i]=='D'){
      check+=13;
    }
    else if (TrameEnvoi[i]=='E'){
      check+=14;
    }
    else if (TrameEnvoi[i]=='F'){
      check+=15;
    }
    else{
      check+=TrameEnvoi[i];
    }
  }
  digA = Conv_hexToAsc((CheckSum >> 4) & 0x0F);
  if (digA!=TrameRecep[13]){
    return false;
  }
  digA = Conv_hexToAsc(CheckSum & 0x0F);
  if (digA!=TrameRecep[14]){
    return false;
  }
  return true;
}
