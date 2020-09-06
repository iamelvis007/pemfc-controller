#define TC_PIN A0          // set to ADC pin used
#define AREF 3.3           // set to AREF, typically board voltage like 3.3 or 5.0
#define ADC_RESOLUTION 10  // set to ADC bit resolution, 10 is default
int fan = 4;
int p = 6;
int pop = 13;
unsigned long startMillis;      //----------some global variables available
unsigned long currentMillis;    //----------time at a certian point for temp
unsigned long scMillis;          //----------time at certian point for short
unsigned long purgeMillis;      //----------time for purge
unsigned long pstartMillis;     //---------- global vaiable for the purge
unsigned long scstartMillis;    //----------global variable for short 
const unsigned long period =1000; //--------the value of the number of milliseconds
float reading, voltage, temperature;
 
float get_voltage(int raw_adc) {
  return raw_adc * (AREF / (pow(2, ADC_RESOLUTION)-1));  
}
 
float get_temperature(float voltage) {// get temperature from the module
  return ((voltage - 1.25) / 0.005)+90;// converts it into the proper temperature
}
 
void setup() {
 { Serial.begin(9600);
  pinMode(fan,OUTPUT);
  pinMode(p,OUTPUT);
  pinMode(pop,OUTPUT);}
  //----------------initial purge-----------
 { digitalWrite(p,LOW);
  delay(1000);
  digitalWrite(p,HIGH);
  delay(3000);}
  //----------------short circuit set-up-------
  {digitalWrite(pop,LOW);
  delay(200);
  digitalWrite(pop,HIGH);
  delay(100);               //-------first short
  digitalWrite(pop,LOW);
  delay(1000);
  digitalWrite(pop,HIGH);
  delay(100);               //-------second short
  digitalWrite(pop,LOW);
  delay(1000);
  digitalWrite(pop,HIGH);
  delay(100);               //-------third short
  digitalWrite(pop,LOW);
  delay(1000);
  digitalWrite(pop,HIGH);
  delay(100);               //-------fourth short
  digitalWrite(pop,LOW);
  delay(1000);
  digitalWrite(pop,HIGH);
  delay(100);               //-------fifth short
  digitalWrite(pop,LOW);
  }
  startMillis = millis();   //-------initial start temp time--------
  pstartMillis =millis();   //-------initial start purge time
  scstartMillis = millis(); //-------initial start short time--------

}
 
void loop() {
  {
  currentMillis = millis(); //--------get current time-----
  if (currentMillis - startMillis >= 300) //-----test weather the period is elapsed 
  {
  reading = analogRead(TC_PIN);
  voltage = get_voltage(reading);
  temperature = get_temperature(voltage);
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");
   startMillis = currentMillis;
 }}
   //---------------fan control--------------
 { if (temperature <25)       //--------this should change to 65C
  {
    digitalWrite(fan,LOW);    //--------turn fan off
  }
  else if(temperature >25)    //--------this should change to 65C
  {
    digitalWrite(fan, HIGH);  //--------turn fan on
  }}
  //---------------purge valve----------------
  purgeMillis = millis(); //------------get current time for purge
 {if (purgeMillis - pstartMillis >= 30000){//after 30 secs start procedure
  digitalWrite(p,HIGH);       //--------turn on
  delay(1000);                //--------1 second
  digitalWrite(p,LOW);        //--------turn off
  pstartMillis = purgeMillis;
 }if (p==HIGH)                //--------If purge is on
  {
    Serial.println("purge on"); //--------print "purge on"
  }}
  //---------------short circuit----------------
  {scMillis = millis();
  if (scMillis - scstartMillis >= 10000)//-after 10 seconds start procedure
  {
    digitalWrite(pop,HIGH);   //---------turn on short circuit
    delay(100);               //---------100ms
    digitalWrite(pop,LOW);    //---------turn off
    scstartMillis = scMillis; //---------restart timer
  }}
    
  }
