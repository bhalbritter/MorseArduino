int Laser = 10;
String ausgabe = "";
String morsecodeEncorded;
String morseCode;
int count = 0;
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



void setup() {
  pinMode(Laser, OUTPUT);
  Serial.begin (9600);
   Serial.println("Bitte Nachricht eingeben:");
  while (Serial.available() == 0) {

  }
  Serial.println("Nachricht in Morse-Zeichen:");
  morseCode = Serial.readString();
  Serial.println(morseCode);
  morsecodeEncorded = printmorse (morseCode);
  Serial.println(morsecodeEncorded);
  Serial.println("Nachricht wird gesendet...");
  sendmorse (morsecodeEncorded);
  
}


void sendmorse(String s){
    digitalWrite(Laser,LOW);
    for(int i = 0; i < s.length();i++){
      if(s.charAt(i) == '/'){
          digitalWrite(Laser,HIGH);
        delay(300);
          digitalWrite(Laser,LOW);
      }
      if(s.charAt(i) == '.'){
          digitalWrite(Laser,HIGH);
        delay(100);
          digitalWrite(Laser,LOW);
      }
      if(s.charAt(i) == '-'){

         digitalWrite(Laser,HIGH);
      delay(200);
         digitalWrite(Laser,LOW);
        
      }
      if(s.charAt(i) == '?'){

         digitalWrite(Laser,HIGH);
      delay(1800);
         digitalWrite(Laser,LOW);
        
      }
        delay(100);
    }
}


String printmorse(String s) {

  

  for (int i = 0; i < s.length()-1; i++) { // goes through each character one at a time
    if (s.charAt(i) == ' ') {  
      ausgabe+="/...--/"; 
    }
    else {
      ausgabe+=ascii2morse(s.charAt(i)); // print out the translation from the ascii to morse
      if (i == s.length() - 1) { // if we have arrived at out last character in the string we don't want anymore slashes
      }
      else if (s.charAt(i + 1) == ' ') { // if the next character is a space don't print a slash
        ;
      } else {
        ausgabe+='/'; // print the slash to divide each morse
      }
    }
  }
  ausgabe+='?';
  return ausgabe;
}

char *  ascii2morse(char c) {
  c = tolower (c); // Lowers the letters to be read by the code
  switch (c) {
    case 'a': return morse_a;
    case 'b': return morse_b;
    case 'c': return morse_c; 
    case 'd': return morse_d;
    case 'e': return morse_e;
    case 'f': return morse_f;
    case 'g': return morse_g;
    case 'h': return morse_h;
    case 'i': return morse_i;
    case 'j': return morse_j;
    case 'k': return morse_k;
    case 'l': return morse_l;
    case 'm': return morse_m;
    case 'n': return morse_n;
    case 'o': return morse_o;
    case 'p': return morse_p;
    case 'q': return morse_q;
    case 'r': return morse_r;
    case 's': return morse_s;
    case 't': return morse_t;
    case 'u': return morse_u;
    case 'v': return morse_v;
    case 'w': return morse_w;
    case 'x': return morse_x;
    case 'y': return morse_y;
    case 'z': return morse_z;
}
}


void loop() {


}
