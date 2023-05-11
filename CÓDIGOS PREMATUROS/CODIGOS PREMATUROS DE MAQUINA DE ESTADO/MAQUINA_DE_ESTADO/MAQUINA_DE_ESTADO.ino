// ==============| LECTURA DE SERIAL |==============

// ------------| VARIABLES DE LECTURA |------------

String caracteres_leidos = "";
String temporal_caracteres = "";
String mensaje = "";

char bandera;

boolean NEW = false;
boolean STA = false;


// ----------------| DATOS DE SERIAL |----------------

void escucho(){
  
  leer(); // GUARDAR DATA DESDE EL SERIAL
  
  if (NEW == true){ // SI SE INDICA QUE HAY DATA
    
    mensaje = caracteres_leidos;
    caracteres_leidos = "";
    imprimir();       // IMPRIMIR RESULTADO

    string_to_ban();
        
    STA = true;
    NEW = false;      // REINICIAR BANDERA
  }
}


// ------------------| LEER SERIAL |------------------

void leer(){
  static boolean leyendo = false;
  static byte cant = 0;
  char ini = '<';
  char fin = '>';
  char lei;
  
  // SI HAY ALGO QUE NO SEA CERO
  while(Serial.available() > 0 && NEW == false){
  
    // CAPTURA EL CARACTER DEL SERIAL
    lei = (char)Serial.read();

    // SI ESTA EN MODO DE LECTURA
    if (leyendo == true){
      
      // SI NO SE LEE EL FINAL SE GUARDA EL VALOR EN LA MATRIZ Y AUMENTA EL ID
      if (lei != fin){
        caracteres_leidos += lei;
      }
      // REINICIAR EL MODO LECTURA SI SE LEE EL FINAL
      else{
        leyendo = false;
        NEW = true;
      }
    }

    // SI NO SE ENCUENTRA EN MODO LECTURA Y SE ENCUENTRA EL INICIO SE INICIA EL MODO LECTURA
    else if (lei == ini){
      leyendo = true;
    }
  }
}


// ------------------| CONVERTIR EN BANDERA |------------------

char string_to_ban(){

if (mensaje == "START"){Serial.println("LA BANDERA ES: S"); bandera = 'S';}
if (mensaje == "FASE_1"){Serial.println("LA BANDERA ES: 1"); bandera = '1';}
else if (mensaje == "LISTO"){Serial.println("LA BANDERA ES: L"); bandera = 'L';}
else if (mensaje == "RESET"){Serial.println("LA BANDERA ES: R"); bandera = 'R';}
else if (mensaje == "BACK"){Serial.println("LA BANDERA ES: B"); bandera = 'B';}
else if (mensaje == "FASE_2"){Serial.println("LA BANDERA ES: 2"); bandera = '2';}
else if (mensaje == "FASE_3"){Serial.println("LA BANDERA ES: 3"); bandera = '3';}
else if (mensaje == "FASE_4"){Serial.println("LA BANDERA ES: 4"); bandera = '4';}
else if (mensaje == "FASE_5"){Serial.println("LA BANDERA ES: 5"); bandera = '5';}
else {bandera = 'N';}
}


// ------------------| IMPRIMIR LO LEIDO |------------------

void imprimir(){
  
  Serial.print("ENTRADA: ");
  Serial.println(mensaje);
}

// ===============| MAQUINA DE ESTADO |===============

// ENUM NOS AYUDA A DECLARAR UN TIPO DE VARIABLE STATE QUE TENGA 5 POSIBLES VALORES (FASES)
//  The enumerator names are usually identifiers that behave as constants in the language.
// POSIBLES ESTADOS
enum STATE
{
  fase_0,
  fase_1,
  fase_2,
  fase_3,
  fase_4,
  fase_5
};

// CONDICIONALES DE CAMBIO
enum GO
{
  start,
  listo,
  to_1,
  to_2,
  to_3,
  to_4,
  to_5,
  reset,
  go_back
};

// DECLARACION DE UNA VARIABLE QUE INDICA EL ESTADO EN QUE SE ENCUENTRA
STATE actual = fase_0;

// DECLARACION DE UNA VARIABLE QUE INDICA INSTRUCCIONES PARA DECIDIR A CUAL ESTADO IRA SIGUIENTE
GO cambio = start;

// DECLARAR CONDICIONES DE CAMBIO
// :: SCOPE RESOLUTION OPERATOR

// ------------| CONDICIONES PARA FASE 0 |------------
void estado_f0()
{
  if (cambio == GO::listo || cambio == GO::go_back || cambio == GO::to_1 || cambio == GO::reset) transform(STATE::fase_1);
}

// ------------| CONDICIONES PARA FASE 1 |------------
void estado_f1()
{
  if (cambio == GO::to_2) transform(STATE::fase_2);
  else if (cambio == GO::to_3) transform(STATE::fase_3);
  else if (cambio == GO::to_4) transform(STATE::fase_4);
  else if (cambio == GO::to_5) transform(STATE::fase_5);
  else if (cambio == GO::start) transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 2 |------------
void estado_f2()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
/*  else if (cambio == GO::to_3) transform(STATE::fase_3);
  else if (cambio == GO::to_4) transform(STATE::fase_4);
  else if (cambio == GO::to_5) transform(STATE::fase_5);
*/  else if (cambio == GO::start) transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 3 |------------
void estado_f3()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
/*  else if (cambio == GO::to_2) transform(STATE::fase_2);
  else if (cambio == GO::to_4) transform(STATE::fase_4);
  else if (cambio == GO::to_5) transform(STATE::fase_5);
*/  else if (cambio == GO::start) transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 4 |------------
void estado_f4()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
/*  else if (cambio == GO::to_2) transform(STATE::fase_2);
  else if (cambio == GO::to_3) transform(STATE::fase_3);
*/  else if (cambio == GO::to_5) transform(STATE::fase_5);
  else if (cambio == GO::start) transform(STATE::fase_0);
}

// ------------| CONDICIONES PARA FASE 5 |------------
void estado_f5()
{
  if (cambio == GO::go_back || cambio == GO::reset || cambio == GO::to_1) transform(STATE::fase_1);
/*  else if (cambio == GO::to_2) transform(STATE::fase_2);
  else if (cambio == GO::to_3) transform(STATE::fase_3);
  else if (cambio == GO::to_4) transform(STATE::fase_4);
*/  else if (cambio == GO::start) transform(STATE::fase_0);
}


// FUNCIONAMIENTO DE LA FASE O SALIDA QUE GENERA ENTRAR EN UNA FASE

// ---------------| FUNCION DE FASE 0 |---------------
void funcion_f0()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("    O                    \n");
  
}

// ---------------| FUNCION DE FASE 1 |---------------
void funcion_f1()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("        O                \n");
}

// ---------------| FUNCION DE FASE 2 |---------------
void funcion_f2()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("            O            \n");
}

// ---------------| FUNCION DE FASE 3 |---------------
void funcion_f3()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                O        \n");
}

// ---------------| FUNCION DE FASE 4 |---------------
void funcion_f4()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                    O    \n");
}

// ---------------| FUNCION DE FASE 5 |---------------
void funcion_f5()
{
  Serial.println("F:  0   1   2   3   4   5");
  Serial.println("                        O\n");
}


// MAQUINA- FUNCION PARA DISPARAR LOS ESTADOS Y HACER EL CAMBIO
void machine()
{
  switch(actual)
  {
    case fase_0: estado_f0(); break;
    case fase_1: estado_f1(); break;
    case fase_2: estado_f2(); break;
    case fase_3: estado_f3(); break;
    case fase_4: estado_f4(); break;
    case fase_5: estado_f5(); break;
  }
}


// INTERPRETACION DE DATOS EN PUERTOS SERIES
void cual_fase()
{
  escucho();
  if(STA == true){
    cambio = GO::start;
    switch(bandera)
    {
      // UNA COMILLA ES EL VALOR EN ASCI DE UN CARACTER, DOS COMILLAS LO CONVIERTE EN TIPO CHAR
      case 'S': cambio = GO::start; break;
      case 'L': cambio = GO::listo; break;
      case 'R': cambio = GO::reset; break;
      case 'B': cambio = GO::go_back; break;
      case '1': cambio = GO::to_1; break;
      case '2': cambio = GO::to_2; break;
      case '3': cambio = GO::to_3; break;
      case '4': cambio = GO::to_4; break;
      case '5': cambio = GO::to_5; break;
      case 'N': Serial.println("NO ES UNA ORDEN VALIDA"); break;
      default: break;
    }
    STA = false;
  }
}

// TRANSFORMAR LA FUNCION EN LA QUE SE ENCUENTRA A LA FASE
void transform(int ir_a)
{
  actual = ir_a;

  switch(actual)
  {
    case STATE::fase_0:funcion_f0(); break;
    case STATE::fase_1:funcion_f1(); break;
    case STATE::fase_2:funcion_f2(); break;
    case STATE::fase_3:funcion_f3(); break;
    case STATE::fase_4:funcion_f4(); break;
    case STATE::fase_5:funcion_f5(); break;
    default: break; 
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  cual_fase();
  machine();
}
