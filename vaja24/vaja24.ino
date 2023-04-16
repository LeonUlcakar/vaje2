#define S1 2
#define S2 3
#define KEY 8

int counter = 0;
int currentStateS1;
int lastStateS1;
String currentDir ="";
unsigned long lastButtonPress = 0;

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
			currentDir ="Matematično pozitivna smer";
		} else {
			counter++;
			currentDir ="Smer urinega kazalca";
		}

		Serial.print("Smer: ");
		Serial.print(currentDir);
		Serial.print(" | Število obreatov: ");
		Serial.println(counter);
	}

	
	lastStateS1 = currentStateS1;

	
	int buttonState = digitalRead(KEY);

	
	if (buttonState == LOW) {
		if (millis() - lastButtonPress > 50) {
			Serial.println("Pritisnili ste gumb");
		}

		lastButtonPress = millis();
	}

	//delay(1);
}