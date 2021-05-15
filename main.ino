#include <Servo.h>


/*----Servo object----*/
Servo servo;  

/*----PIN----*/
const int X_DIR = 5;
const int X_STEP = 4;

const int Y_DIR = 3;
const int Y_STEP = 2;

const int RELE_PIN = 8;
const int BUZZER_PIN = 7;

const int SERVO_PIN = 6;

const int LED_R_PIN = 9;
const int LED_B_PIN = 10;
const int LED_G_PIN = 11;

const int Y_ENDSTOP = A1;
const int X_ENDSTOP = A0;

const int SHOOT_PIN = A2;
const int SHUTDOWN_PIN = A3;
const int RESET_PIN = A4;

/*----DELAY STPPER PULSE----*/ 
const int STEP_DELAY = 600;//560;

/*----step totali per una massima escursione di movimento----*/
int x_total_steps=1646;
int y_total_steps=1400;

/*----Servo DELAY for each piece----*/
const int DELAY_P = 1420;
const int DELAY_K = 1170;
const int DELAY_Q = 1180;
const int DELAY_R = 1300;
const int DELAY_B = 1260;
const int DELAY_N = 1290;


/*=======================-STEPS for each square-=======================*/

/*----Step margin X axis from left to right----*/
int X1 = 1615;
int X2 = 1330;
int X3 = 250;

/*----Step margin Y axis at the top----*/
int Y1 = 160;

/*----X and Y squares Steps for one square----*/
int Xsquare = 123;
int Ysquare = 127;

/*----STEPS for each square----*/
int steps[3][8][8][2] = {
  /*----LEFT----*/
  {
    {{X1-(Xsquare*0), Y1+(Ysquare*1)},   {X1-(Xsquare*1), Y1+(Ysquare*1)}},
    {{X1-(Xsquare*0), Y1+(Ysquare*2)},   {X1-(Xsquare*1), Y1+(Ysquare*2)}},
    {{X1-(Xsquare*0), Y1+(Ysquare*3)},   {X1-(Xsquare*1), Y1+(Ysquare*3)}},
    {{X1-(Xsquare*0), Y1+(Ysquare*4)},   {X1-(Xsquare*1), Y1+(Ysquare*4)}},
    {{X1-(Xsquare*0), Y1+(Ysquare*5)},   {X1-(Xsquare*1), Y1+(Ysquare*5)}},
    {{X1-(Xsquare*0), Y1+(Ysquare*6)},   {X1-(Xsquare*1), Y1+(Ysquare*6)}},
    {{X1-(Xsquare*0), Y1+(Ysquare*7)},   {X1-(Xsquare*1), Y1+(Ysquare*7)}},
    {{X1-(Xsquare*0), Y1+(Ysquare*8)},   {X1-(Xsquare*1), Y1+(Ysquare*8)}}
  },
  /*----GRID----*/
  {
    { {X2-(Xsquare*0), Y1+(Ysquare*1)}, {X2-(Xsquare*1), Y1+(Ysquare*1)},   {X2-(Xsquare*2), Y1+(Ysquare*1)},   {X2-(Xsquare*3), Y1+(Ysquare*1)},   {X2-(Xsquare*4), Y1+(Ysquare*1)},   {X2-(Xsquare*5), Y1+(Ysquare*1)},   {X2-(Xsquare*6), Y1+(Ysquare*1)},   {X2-(Xsquare*7), Y1+(Ysquare*1)},  },
    { {X2-(Xsquare*0), Y1+(Ysquare*2)}, {X2-(Xsquare*1), Y1+(Ysquare*2)},   {X2-(Xsquare*2), Y1+(Ysquare*2)},   {X2-(Xsquare*3), Y1+(Ysquare*2)},   {X2-(Xsquare*4), Y1+(Ysquare*2)},   {X2-(Xsquare*5), Y1+(Ysquare*2)},   {X2-(Xsquare*6), Y1+(Ysquare*2)},   {X2-(Xsquare*7), Y1+(Ysquare*2)},  },
    { {X2-(Xsquare*0), Y1+(Ysquare*3)}, {X2-(Xsquare*1), Y1+(Ysquare*3)},   {X2-(Xsquare*2), Y1+(Ysquare*3)},   {X2-(Xsquare*3), Y1+(Ysquare*3)},   {X2-(Xsquare*4), Y1+(Ysquare*3)},   {X2-(Xsquare*5), Y1+(Ysquare*3)},   {X2-(Xsquare*6), Y1+(Ysquare*3)},   {X2-(Xsquare*7), Y1+(Ysquare*3)},  },
    { {X2-(Xsquare*0), Y1+(Ysquare*4)}, {X2-(Xsquare*1), Y1+(Ysquare*4)},   {X2-(Xsquare*2), Y1+(Ysquare*4)},   {X2-(Xsquare*3), Y1+(Ysquare*4)},   {X2-(Xsquare*4), Y1+(Ysquare*4)},   {X2-(Xsquare*5), Y1+(Ysquare*4)},   {X2-(Xsquare*6), Y1+(Ysquare*4)},   {X2-(Xsquare*7), Y1+(Ysquare*4)},  },
    { {X2-(Xsquare*0), Y1+(Ysquare*5)}, {X2-(Xsquare*1), Y1+(Ysquare*5)},   {X2-(Xsquare*2), Y1+(Ysquare*5)},   {X2-(Xsquare*3), Y1+(Ysquare*5)},   {X2-(Xsquare*4), Y1+(Ysquare*5)},   {X2-(Xsquare*5), Y1+(Ysquare*5)},   {X2-(Xsquare*6), Y1+(Ysquare*5)},   {X2-(Xsquare*7), Y1+(Ysquare*5)},  },
    { {X2-(Xsquare*0), Y1+(Ysquare*6)}, {X2-(Xsquare*1), Y1+(Ysquare*6)},   {X2-(Xsquare*2), Y1+(Ysquare*6)},   {X2-(Xsquare*3), Y1+(Ysquare*6)},   {X2-(Xsquare*4), Y1+(Ysquare*6)},   {X2-(Xsquare*5), Y1+(Ysquare*6)},   {X2-(Xsquare*6), Y1+(Ysquare*6)},   {X2-(Xsquare*7), Y1+(Ysquare*6)},  },
    { {X2-(Xsquare*0), Y1+(Ysquare*7)}, {X2-(Xsquare*1), Y1+(Ysquare*7)},   {X2-(Xsquare*2), Y1+(Ysquare*7)},   {X2-(Xsquare*3), Y1+(Ysquare*7)},   {X2-(Xsquare*4), Y1+(Ysquare*7)},   {X2-(Xsquare*5), Y1+(Ysquare*7)},   {X2-(Xsquare*6), Y1+(Ysquare*7)},   {X2-(Xsquare*7), Y1+(Ysquare*7)},  },
    { {X2-(Xsquare*0), Y1+(Ysquare*8)}, {X2-(Xsquare*1), Y1+(Ysquare*8)},   {X2-(Xsquare*2), Y1+(Ysquare*8)},   {X2-(Xsquare*3), Y1+(Ysquare*8)},   {X2-(Xsquare*4), Y1+(Ysquare*8)},   {X2-(Xsquare*5), Y1+(Ysquare*8)},   {X2-(Xsquare*6), Y1+(Ysquare*8)},   {X2-(Xsquare*7), Y1+(Ysquare*8)},  }
  },
  /*----RIGHT----*/
  {
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*1)}},
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*2)}},
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*3)}},
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*4)}},
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*5)}},
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*6)}},
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*7)}},
    {{X3-(Xsquare*0), Y1+(Ysquare*1)},   {X3-(Xsquare*1), Y1+(Ysquare*8)}}
  }
};
/*=====================================================================*/

/*----fa muovere il braccio in x ed y contemporaneamente, con una determinata direzione e numero di step per asse----*/
void step(bool x_dir, bool y_dir, int x_step, int y_step){
  /*
  Direction:
    False: destra, avanti //verso il finecorsa
    True: sinistra, dietro //lontano dal finecorsa
  */
  digitalWrite(X_DIR,x_dir);
  digitalWrite(Y_DIR,y_dir);
  delay(STEP_DELAY);

  bool is_x_step_max=false;
  if(x_step>y_step)
    is_x_step_max=true;
    
  if(is_x_step_max){
    for(int i=0; i<x_step; i++){
      if(i<y_step){
        digitalWrite(X_STEP,HIGH);
        delayMicroseconds(STEP_DELAY/2);

        digitalWrite(Y_STEP,HIGH);
        delayMicroseconds(STEP_DELAY/2);
        
        digitalWrite(X_STEP,LOW); 
        delayMicroseconds(STEP_DELAY/2);
        
        digitalWrite(Y_STEP,LOW); 
        delayMicroseconds(STEP_DELAY/2);
      }else{
        digitalWrite(X_STEP,HIGH);
        delayMicroseconds(STEP_DELAY);
        digitalWrite(X_STEP,LOW); 
        delayMicroseconds(STEP_DELAY);
      }
    }
  }else{
    for(int i=0; i<y_step; i++){
      if(i<x_step){
        digitalWrite(X_STEP,HIGH);
        delayMicroseconds(STEP_DELAY/2);

        digitalWrite(Y_STEP,HIGH);
        delayMicroseconds(STEP_DELAY/2);
        
        digitalWrite(X_STEP,LOW); 
        delayMicroseconds(STEP_DELAY/2);
        
        digitalWrite(Y_STEP,LOW); 
        delayMicroseconds(STEP_DELAY/2);
      }else{
        digitalWrite(Y_STEP,HIGH);
        delayMicroseconds(STEP_DELAY);
        digitalWrite(Y_STEP,LOW); 
        delayMicroseconds(STEP_DELAY);
      }
    }
  }
}

/*----fa abbassare e salire il grip e prendere o rilasicare una pedina----*/
void grip(bool pick, char piece, int type){
  //0 scendi, 1 sali
  int delay_piece;
  if(piece == 'P')
    delay_piece = DELAY_P;
  else if(piece == 'K')
    delay_piece = DELAY_K;
  else if(piece == 'Q')
    delay_piece = DELAY_Q;
  else if(piece == 'R')
    delay_piece = DELAY_R;
  else if(piece == 'B')
    delay_piece = DELAY_B;
  else if(piece == 'N')
    delay_piece = DELAY_N;
    
  int errore_scendi_1 = 0;
  int errore_sali_1 = 50;//20;
  
  int errore_scendi_2 = -45;//-15;
  int errore_sali_2 = 60;//30;

  servo.write(0);
  if(pick)
    delay(delay_piece+errore_scendi_1);
  else
    delay(delay_piece+errore_scendi_2);
  servo.write(90);
  delay(200);
  digitalWrite(8,pick);
  digitalWrite(8,pick);
  digitalWrite(8,pick);
  digitalWrite(8,pick);
  delay(2000);

  servo.write(180);
  if(pick)
    delay(delay_piece+errore_sali_1);
  else
    delay(delay_piece+errore_sali_2);
  servo.write(90);
  delay(2000);
  
}

/*----fa compiere una mossa completa al braccio----*/
void move(int start_type, int start_row, int start_column, int end_type, int end_row, int end_column, char piece){
  int start_stps_x = steps[start_type][start_row][start_column][0]; 
  int start_stps_y = steps[start_type][start_row][start_column][1]; 

  int end_total_stps_x = steps[end_type][end_row][end_column][0]; 
  int end_total_stps_y = steps[end_type][end_row][end_column][1]; 

  int end_stps_x = start_stps_x - end_total_stps_x;
  int end_stps_y = start_stps_y - end_total_stps_y; 

  step(false, false, start_stps_x, start_stps_y);

  delay(500);

  grip(true,piece,start_type);


  delay(500);

  if((end_stps_x<0) && (end_stps_y<0)){
    step(false, false, end_stps_x*-1, end_stps_y*-1);
  }else if(end_stps_x<0){
    step(false, true, end_stps_x*-1, end_stps_y);
  }else if(end_stps_y<0){
    step(true, false, end_stps_x, end_stps_y*-1);
  }else {
    step(true, true, end_stps_x, end_stps_y);
  }
  
  delay(500);
  
  grip(false,piece,end_type);

  delay(500);

  step(true, true, end_total_stps_x, end_total_stps_y);
  
  delay(1000);
  
}

/*----controlla la mossa disponibile sul buffer seriale e la fa compiere al braccio----*/
void check_and_move(){
  delay(50);
  Serial.read();//skip the '-'
  
  int start_type = Serial.read() - '0';
  int start_row = Serial.read() - '0';
  int start_column = Serial.read() - '0';

  Serial.read();//skip the '-'
  
  int end_type = Serial.read() - '0';
  int end_row = Serial.read() - '0';
  int end_column = Serial.read() - '0';

  Serial.read();//skip the '-'

  char piece = Serial.read();

  move(start_type,start_row,start_column, end_type,end_row,end_column, piece);

}

/*----Inizializza il braccio alla sua posizione iniziale----*/
void init_(){
  digitalWrite(X_DIR,false);
  digitalWrite(Y_DIR,false);
  
  while(digitalRead(X_ENDSTOP)){
    digitalWrite(X_STEP,HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(X_STEP,LOW); 
    delayMicroseconds(STEP_DELAY);
  }
  while(digitalRead(Y_ENDSTOP)){
    digitalWrite(Y_STEP,HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(Y_STEP,LOW); 
    delayMicroseconds(STEP_DELAY);
  }
  delay(800);
  step(true,true,x_total_steps,y_total_steps);
  
}

/*----ricava i valori di step totali per X e Y e li visualizza sul monitor seriale----*/
void calibrate(){
  /*Questa funzione è stata utilizzata inizialmente per potersi ricavare i valori di step necessari per una massima escursione del braccio nei suoi due assi*/
  x_total_steps=0;
  y_total_steps=0;
  digitalWrite(X_DIR,false);
  digitalWrite(Y_DIR,false);
  
  while(digitalRead(X_ENDSTOP)){
    digitalWrite(X_STEP,HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(X_STEP,LOW); 
    delayMicroseconds(STEP_DELAY);
    x_total_steps++;
  }
  while(digitalRead(Y_ENDSTOP)){
    digitalWrite(Y_STEP,HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(Y_STEP,LOW); 
    delayMicroseconds(STEP_DELAY);
    y_total_steps++;
  }
  Serial.print("x_total_steps: ");
  Serial.println(x_total_steps);
  Serial.print("y_total_steps: ");
  Serial.println(y_total_steps);
}

/*----fa suonare il buzzer----*/
void beep(int frequency=2000, int duration=100){
  tone(BUZZER_PIN,frequency,duration);
  delay(100);
}

/*----gestisce i task da eseguire alla pressione di dei pulsanti----*/
void button_controller(){
  if(digitalRead(SHOOT_PIN)==HIGH){
    beep();
    Serial.write("SHOOT");
    delay(1000);
  }
  if(digitalRead(SHUTDOWN_PIN)==HIGH){
    beep();
    Serial.write("SHUTDOWN");
    delay(1000);
  }
  if(digitalRead(RESET_PIN)==HIGH){
    beep();
    delay(1000);
    init_();
    delay(1000);
  }
  if(digitalRead(X_ENDSTOP)==LOW){
    beep();
  }
  if(digitalRead(Y_ENDSTOP)==LOW){
    beep();
  }
}

/*----imposta il colore del led RGB e emette un beep----*/
void led_RGB(int r, int g, int b){
  digitalWrite(LED_R_PIN, r);
  digitalWrite(LED_G_PIN, g);
  digitalWrite(LED_B_PIN, b);
  beep();
}

/*----gesttisce i task da eseguire in base al primo valore ricevuto dal buffer Seriale----*/
void serial_controller(int start_byte){
  if(start_byte == 'M'){
    check_and_move();
  }else if(start_byte == 'B'){
    beep();
    int next_byte = Serial.read();
    if(next_byte == 'B'){
      beep(2000,200);
    }    
  }else if(start_byte == 'Z'){
    beep(100,200);
  }else if(start_byte == 'T'){
    led_RGB(255,0,255);
  }else if(start_byte == 'F'){
    led_RGB(0,255,255);
  }
}

/*----SETUP----*/
void setup() {
  /*----OUTPUT----*/
  pinMode(X_DIR,OUTPUT); pinMode(X_STEP,OUTPUT);
  pinMode(Y_DIR,OUTPUT); pinMode(Y_STEP,OUTPUT);

  pinMode(RELE_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(SERVO_PIN,OUTPUT);

  pinMode(LED_R_PIN,OUTPUT);pinMode(LED_G_PIN,OUTPUT);pinMode(LED_B_PIN,OUTPUT);

  /*----INPUT----*/
  pinMode(X_ENDSTOP,INPUT); pinMode(Y_ENDSTOP,INPUT);
  pinMode(SHOOT_PIN,INPUT);
  pinMode(SHUTDOWN_PIN,INPUT);
  pinMode(RESET_PIN,INPUT);

  /*----SERVO INIT----*/
  servo.attach(6);
  /*----SERIAL INIT----*/
  Serial.begin(9600);
  /*----LED RGB RED DEFAULT VALUE----*/
  led_RGB(0,255,255);

  //calibrate();
  delay(4000);
  /*----STEPPER INIT----*/
  init_();
}

/*----LOOP----*/
void loop() {
  button_controller();
  int start_byte = Serial.read();
  serial_controller(start_byte);
}












































































// int x_temp = 0;
// int y_temp = 0; 

// int x_value=0;
// int y_value=0;

// void muovi_manualmente(){
//   x_value = map(analogRead(A3), 0, 1023, 0,x_total_steps);
//   y_value = map(analogRead(A2), 0, 1023, 0,y_total_steps);  

//   int x_step = x_value-x_temp;
//   int y_step = y_value-y_temp;

//   if((x_step<0)&&(y_step<0)){
//     step(true,true,x_step*-1,y_step*-1);
//   }else if(x_step<0){
//     step(true,false,x_step*-1,y_step);
//   }else if(y_step<0){
//     step(false,true,x_step,y_step*-1);
//   }else{
//     step(false,false,x_step,y_step);
//   }
  
//   Serial.print("x:");
//   Serial.print(x_value);
//   Serial.print("\ty:");
//   Serial.print(y_value); 
//   Serial.print("\ttemp:");
//   Serial.println(x_temp); 

//   x_temp = x_value;
//   y_temp = y_value;
// }
