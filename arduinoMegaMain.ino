// Trucs à faire


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



// ************ Definition des variables pour l'afficheur ************ 
#define NB_COL  5
#define NB_LIG  7
int Col[] = {24, 26, 28, 30, 32}; // blanc = PA_7, PA_6, PA_5, PE_5, bleu = PE_4 // {10,9,8,6,5};  // Numéro des broches connectées aux colonnes de l'afficheur
int Lig[] = {46, 44, 42, 40, 38, 36, 34}; // rouge = PB_3, PC_4, PC_5, PC_6, PC_7, PD_6, noir = PA_4 // {38,37,36,35,34,33,13};  // Numéro des broches connectées aux lignes de l'afficheur

int Motif1[] =   { 1,1,1,1,0,   // Définition d'une matrice binaire représentant le caractère 
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

int Motif3[] =   { 0,0,1,0,0,   // Définition d'une matrice binaire représentant le caractère 
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
int pinCardio = 37;//11;//24; // PD_1


// ************ Definition des variables pour le capteur de température ************
int pinT = A0;//10;//23; //PD_0
double temp = 0.0;
int brut = 0;


// ************ Definition des variables pour le capteur de frequence sonore ************
int pinCasque = 33;//9;//19;
int pinMicro = A5;

// ************ Definition des variables pour capteur visuel attendu / innatendu ************
int pinVisuelRed = 31;//8; // PF_1
int pinVisuelGreen = 27;//7; // PF_2
int pinVisuelBlue = 25;//6; // PF_3
int pinBouton = 39;//12; // PA_5



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
  pinMode(pinT, INPUT);

  // ************ Initialisation des pins pour le capteur de frequence sonore ************
  pinMode(pinCasque, OUTPUT);
  pinMode(pinMicro, INPUT);


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
    int choix = 1;
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
      //afficheur(); //Compte à rebours
      capteur_cardiaque(); //Test de fréquence cardiaque
      }
    else if(choix==2){
      affichage(Motif2);//Affichage id test
      delay(2000);
      //afficheur();//Compte à rebours
      capteur_temperature();//Test de température
      delay(1000);
      }
    else if(choix==3){
      affichage(Motif3);//Affichage id test
      delay(2000);
      //afficheur();//Compte à rebours
      capeur_sonore();//Test de reconnaissance sonore
      }
    else if(choix==4){
      affichage(Motif4);//Affichage id test
      delay(2000);
      //afficheur();//Compte à rebours
      visuelAttendu();
      }
    else if(choix==5){
      affichage(Motif5);//Affichage id test
      delay(2000);
      //afficheur();//Compte à rebours
      visuelInattendu();
      }
    else if(choix==6){
      affichage(Motif6);//Affichage id test
      delay(2000);
      //afficheur();//Compte à rebours
      visuelAttendu();//Dans le noir
      }
    else if(choix==7){
      affichage(Motif7);//Affichage id test
      delay(2000);
      //afficheur();//Compte à rebours
      visuelInattendu();//Dans le noir
      }
   }
}

// ************ Appelle les différentes fonctions pour faire fonctionner l'afficheur ************ 
void afficheur(){
  int i;
  for (i=0;i<3000;i++){
    affichage(Motif1); //Affichage 3
  }
  delay(5);
  
  for (i=0;i<3000;i++){
    affichage(Motif2); //Affichage 2
  }
  delay(5);
  
  for (i=0;i<3000;i++){
    affichage(Motif3); //Affichage 1
  }
  delay(5);
}

#define TEMP  10
// ************ Affiche une fois le tableau en fonction de la matrice qu'on lui donne
void affichage(int Motifi[]){
  int i,j;
  for (i=0;i<NB_LIG;i++){
    digitalWrite(Lig[i],LOW); // Activation de la ligne i (les autres sont éteintes
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
  afficheur();
  delay(50);
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


// ************ Appelle la fonction faisant fonctionner le capteur de température ************
void capteur_temperature(){
  delay(50);
  Serial.println("Temperature");
  afficheur();
  delay(50);
  double res = 0.0;
  
  brut = analogRead(pinT);
  temp = brut * (5.0/1023.0) * 100;
  res += temp;
  delay(50);
  
  brut = analogRead(pinT);
  temp = brut * (5.0/1023.0) * 100;
  res += temp;
  delay(50);
  
  brut = analogRead(pinT);
  temp = brut * (5.0/1023.0) * 100;
  res += temp;
  delay(50);
  
  brut = analogRead(pinT);
  temp = brut * (5.0/1023.0) * 100;
  res += temp;
  
  res /= 4;
  Serial.println(res);
  delay(50);
  delay(4000);
}

// ************ Fonction qui emet un son dans le casque ************
void signal_carre(int duree, int demi_periode) {
  Serial.print("Signal ");
  Serial.print(1000000.0 / (2 * demi_periode));
  Serial.println("Hz");
  afficheur();
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
  delay(2000);
  signal_carre(2000, 1000);
  delay(7000);
  double score1 = mesureScoreMicro(1000);
  Serial.println(score1);
  
  delay(7000);
  signal_carre(4000, 500);
  delay(7000);
  double score2 = mesureScoreMicro(500);
  Serial.println(score2);
  
  delay(7000);
  signal_carre(3000, 750);
  delay(7000);
  double score3 = mesureScoreMicro(750);
  Serial.println(score3);
  delay(3000);
}

// ************ Appelle la fonction mesurant la justesse de l'utilisateur (micro) ************
double mesureScoreMicro(int demiPeriode){
  Serial.println("Mesure du micro");
  delay(2000);
  afficheur();
  double fRef = 1000000.0 / (2 * demiPeriode);
  unsigned long premiereDemiPeriode = 0;
  unsigned long secondeDemiPeriode = 0;
  unsigned long periode = 0;
  int count = 0;
  int alpha = 20;
  while(count < 20){
    premiereDemiPeriode = pulseIn(pinMicro, HIGH);
    secondeDemiPeriode = pulseIn(pinMicro, LOW);
    periode += premiereDemiPeriode + secondeDemiPeriode;
    count++;
  }
  count = 0;
  periode /= alpha;
  double fUser = 1000000.0 / periode;
  Serial.print(fRef);
  Serial.print(" ");
  Serial.println(fUser);
  double score = 100*exp(-0.5*pow(abs(log2(fRef) - log2(fUser)) / (log2(fRef)*0.015), 2.0));
  return score;
}

double log2 (double x){
  return log(x) / log(2);
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


// ************ Calcule le temps de reaction au stimulus visuel attendu ************
unsigned long tempsReactionVisuelAttendu(int pinVisuel) {
  
  afficheur();

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
  Serial.println(" ");
  delay(10);
  return chrono;
}


// ************ Calcule le temps de reaction au stimulus visuel inattendu ************
unsigned long tempsReactionVisuelInattendu(int pinVisuel) {
  
  afficheur();
  
  long tempsAttente = random(1,2000);
  delay(tempsAttente);
  
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
  Serial.println(" ");
  delay(10);
  return chrono;
}
