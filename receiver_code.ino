int sensorPin = A4; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor
int zaehler = 0;
int count = 0;
boolean empfang = false;
String ausgabe = "";
String entausgabe = "";
String morsezeichen="";
String ausgabe2 = "";
String zeichen = "";
char morse_a[] = ".-";
char morse_b[] = "-...";
char morse_c[] = "-.-.";
char morse_d[] = "-..";
char morse_e[] = ".";
char morse_f[] = "..-.";
char morse_g[] = "--.";
char morse_h[] = "....";
char morse_i[] = "..";
char morse_j[] = ".---";
char morse_k[] = "-.-";
char morse_l[] = ".-..";
char morse_m[] = "--";
char morse_n[] = "-.";
char morse_o[] = "---";
char morse_p[] = ".--.";
char morse_q[] = "--.-";
char morse_r[] = ".-.";
char morse_s[] = "...";
char morse_t[] = "-";
char morse_u[] = "..-";
char morse_v[] = "...-";
char morse_w[] = ".--";
char morse_x[] = "-..-";
char morse_y[] = "-.--";
char morse_z[] = "--..";
char morse_leer[] = "...--";

void setup() {
    Serial.begin(9600); //sets serial port for communication
    Serial.print("bereit fuer Nachricht...");
    zeichen = getDaten();
    entausgabe = morse2ascii(zeichen);

    Serial.println("Empfangene Nachricht: " +entausgabe);
}

String getDaten(){
  do{
 count=0;
  do{
   sensorValue = analogRead(sensorPin); 
// Serial.println(sensorValue);
   count++;
   delay(100);
   //Wenn der sensor Value größer als 910 is wird die Schleife verlassen
  }while(sensorValue > 910);

    // wird ausgegeben wenn eine Nachricht erkannt wird
  if( count > 1 && empfang == false){
    empfang=true;
    Serial.println("empfange Nachricht...");
  }
 
  if(count == 2){
    ausgabe2+='.';
    //Serial.print('.');
  }

  if(count == 3){
    ausgabe2+='-';
   // Serial.print('-');
  }

  if(count == 4){
    ausgabe2+='|';
   //    Serial.print('|');
  }
  }while(count<16);
    
  ausgabe2+='?';

  return ausgabe2;  
}



String morse2ascii (String Stringmorse){

Serial.println(Stringmorse);

   while(Stringmorse.charAt(zaehler)!='?'){
  morsezeichen="";
    
    while(Stringmorse.charAt(zaehler)!='|'){
      morsezeichen+=Stringmorse.charAt(zaehler);
     
      zaehler++;
    }
    zaehler++;

  if (morsezeichen== morse_a) { 
    ausgabe+="a"; 
  }
  if (morsezeichen == morse_b) { 
    ausgabe+="b"; 
  }
  if (morsezeichen == morse_c) { 
    ausgabe+="c"; 
  }
  if (morsezeichen == morse_d) {
    ausgabe+="d"; 
  }
  if (morsezeichen == morse_e) {
    ausgabe+="e"; 
  }
  if (morsezeichen == morse_f) {
    ausgabe+="f"; 
  }
  if (morsezeichen == morse_g) {
    ausgabe+="g"; 
  }
  if (morsezeichen == morse_h) {
    ausgabe+="h"; 
  }
  if (morsezeichen == morse_i) {
    ausgabe+="i"; 
  }
  if (morsezeichen == morse_j) {
    ausgabe+="j"; 
  }
  if (morsezeichen == morse_k) {
    ausgabe+="k"; 
  }
  if (morsezeichen == morse_l) {
    ausgabe+="l"; 
  }
  if (morsezeichen == morse_m) {
    ausgabe+="m"; 
  }
  if (morsezeichen == morse_n) {
    ausgabe+="n"; 
  }
  if (morsezeichen == morse_o) {
    ausgabe+="o"; 
  }
  if (morsezeichen == morse_p) {
    ausgabe+="p"; 
  }
  if (morsezeichen == morse_q) {
    ausgabe+="q"; 
  }
  if (morsezeichen == morse_r) {
    ausgabe+="r"; 
  }
  if (morsezeichen == morse_s) {
    ausgabe+="s"; 
  }
  if (morsezeichen == morse_t) {
    ausgabe+="t"; 
  }
  if (morsezeichen == morse_u) {
    ausgabe+="u"; 
  }
  if (morsezeichen == morse_v) {
    ausgabe+="v"; 
  }
  if (morsezeichen == morse_w) {
    ausgabe+="w"; 
  }
  if (morsezeichen == morse_x) {
    ausgabe+="x"; 
  }
  if (morsezeichen == morse_y) {
    ausgabe+="y"; 
  }
  if (morsezeichen == morse_z) {
    ausgabe+="z"; 
  }
  if (morsezeichen == morse_leer){
    ausgabe+=" "; 
  }
  
   }
   return ausgabe;
}








void loop() {
//  sensorValue = analogRead(sensorPin); 
  //Serial.println(sensorValue); 


}
