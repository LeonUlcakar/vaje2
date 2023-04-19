#define S1 2
#define S2 3
#define KEY 8

int counter = 65;
int currentStateS1;
int lastStateS1;
String currentDir ="";
String wordBla ="";
unsigned long lastButtonPress = 0;
char text[101] = "";
int index = 0;
//char alfa[] = " abcčdefghijklmnoprsštuvzžABCČDEFGHIJKLMNOPRSŠTUVZŽ";
//just use ascii
void setup() {
        
	pinMode(S1,INPUT);
	pinMode(S2,INPUT);
	pinMode(KEY, INPUT_PULLUP);

	Serial.begin(9600);

	lastStateS1 = digitalRead(S1);
}

void loop() {
        

	currentStateS1 = digitalRead(S1);


	if (currentStateS1 != lastStateS1  && currentStateS1 == 1){

		if (digitalRead(S2) != currentStateS1) {
			counter--;
      if (counter < 65){
        counter = 90;
      }
			//currentDir ="Matematično pozitivna smer";
		} else {
			counter++;
      if (counter > 90){
        counter = 65;
      }
			//currentDir ="Smer urinega kazalca";
		}

      Serial.print("Število obreatov: ");
      Serial.print(counter);
      Serial.println((char)counter);
	}

	
	lastStateS1 = currentStateS1;

	
	int buttonState = digitalRead(KEY);

	
	if (buttonState == LOW) {
		if (millis() - lastButtonPress > 50) {
			//Serial.println("Pritisnili ste gumb");
      //wordBla += (char)counter;
      enterChar(text, (char)counter, index);
      Serial.print("Beseda: ");
      //Serial.print(wordBla);
      Serial.println(text);
      index++;
		}

		lastButtonPress = millis();
	}

	delay(10);
}


void enterChar(char text[], char symbol, int index){
  if (index == 99){
    text[99] = symbol;
    text[index + 1] = '/0';
    Serial.print("You have reached the end\n");
  }
  else if(index == 100){
    Serial.print("Are you sure about that?\n");
  }
  else {
    text[index] = symbol;
  }
  

  /*
  char *pointer = &text[0];
  for (int i = 0; i < sizeof(text); i++){
    if (text[i] == NULL || text[i] == '\0'){
      *pointer = symbol;
      pointer++;
      *pointer = '\0';
      break;
    }
    pointer++;
  }
  */
}




