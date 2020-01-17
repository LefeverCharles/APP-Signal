int sensor_val;
String trame;

 void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
 
}

void loop()
{
 
 sensor_val=(int)random(0, 50); // random number between 0 and 255
 Serial.print(sensor_val);
 Serial.println("°C");
 trame = "100011301";
 if(sensor_val < 16){ /*obligatoire si on veut avoir un trame de bonne taille*/
  trame += "000";
 }
 else{
  trame += "00";
 }
 String Thex = String(sensor_val,HEX);
 trame += Thex;
 trame += "0125";
 
 int CHK = 0;
 for(int i =0;i<trame.length();i++){
   char car = trame[i];
   if(car == '0'){
   CHK += 30;
   }
   else if(car == '1'){
  CHK += 31;
   }
   else if(car == '2'){
  CHK += 32;
   }
   else if(car == '3'){
  CHK += 33;
   }
   else if(car == '4'){
  CHK += 34;
   }
   else if(car == '5'){
  CHK += 35;
   }
   else if(car == '6'){
  CHK += 36;
   }
   else if(car == '7'){
  CHK += 37;
   }
   else if(car == '8'){
  CHK += 38;
   }
   else if(car == '9'){
  CHK += 39;
   }
   else if(car == 'a'){
  CHK += 41;
   }
   else if(car == 'b'){
  CHK += 42;
   }
   else if(car == 'c'){
  CHK += 43;
   }
   else if(car == 'd'){
  CHK += 44;
   }
   else if(car == 'e'){
  CHK += 45;
   }
   else if(car == 'f'){
  CHK += 46;
   }
   
 }
 
CHK = CHK %256;
String chk = String(CHK, HEX);
if(chk.length() == 1){/*obligatoire si on veut avoir un trame de bonne taille*/
  trame += "0";
  trame += chk;
}
else{
  trame += chk;

}

if(trame.length() != 19){ /*detection d'erreur*/
  Serial.println("ERREUR TAILLE");
  }
  
 else{
    Serial.println(trame);
    Serial1.print(trame);
  }
 
 delay(1000);
}
