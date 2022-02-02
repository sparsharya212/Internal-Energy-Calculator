//SRC Code
int val;
int tempPin = 1;
void setup()
{
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000;
float cel = mv/10;
float farh = (cel*9)/5 + 32;
Serial.print("TEMPERATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);
/* uncomment this to get temperature in farenhite
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();
*/
}
//C# Code for printing the change in the internal energy in every 5 seconds
const int lm35_pin = A1; /* LM35 O/P pin */
int vol =0;
int count=0;
int initial=0;
int delt=0;
float temp_adc_val;
float temp_val=0;
float internalE=0;
float check=0;
void setup() {
Serial.begin(9600);
Serial.println("Enter your volume of sample taken in ml: ");
while (Serial.available()==0)
{ //Wait for user input
}
vol=Serial.readString().toInt();
}
void loop() {
temp_adc_val = analogRead(lm35_pin);
while(temp_adc_val!=0)
{
if(count==5)
{
initial=temp_adc_val*4.88/10;
}
count++;
/* Read Temperature */
if(count%5==0)
{
delt=(temp_adc_val*4.88/10)-initial;
check=temp_adc_val*4.88/10;
internalE=delt*vol*4.18;
Serial.println("The internal energy change after 5 seconds is ");
Serial.println(internalE);
}
temp_adc_val=0;
}
Serial.println(check);
delay(1000);
}