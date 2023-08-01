/* Exercice pour lire la température 
   ainsi que le taux d'humidité relative
   pour ensuite afficher ces valeurs
   sur l'écran LCD */

// New comment

//Libraries
//#include <
#include <DHT.h>            // Ajout de la librairie pour le capteur Temperature et Humidité DHT22
#include <LiquidCrystal.h>  // Ajout de la librairie pour l'ecran LCD

//Constants
#define DHTPIN 10    // Definition de la pin qui recoit les données du capteur DHT22
#define DHTTYPE DHT22   // Definition du type de capteur DHT  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialise le capteur DHT pour l'utilisation au clock rate normal de 16mhz Arduino

const int rs = 12, en = 14, d4 = 5, d5 = 4, d6 = 0, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
	dht.begin();
  
  lcd.begin(16, 2);            // set up the LCD's number of columns and rows:
  
  //lcd.print("hello, world!");  // Print a message to the LCD.
}

void loop()
{
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");




  lcd.setCursor(0, 0);   // set the cursor to column 0, line 0
  lcd.print("Temp.: ");
  lcd.print(temp);
  lcd.print((char)176);
  lcd.print("C");
    
  
  lcd.setCursor(0, 1);  // set the cursor to column 0, line 1
  lcd.print("Hum.:  ");
  lcd.print(hum);
  lcd.print(" %");

    delay(1000); //Delay 2 sec.
}

   