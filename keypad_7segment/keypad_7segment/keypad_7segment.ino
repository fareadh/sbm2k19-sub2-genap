/*this keypad tutorial number one by omar tarek 29-06-2014 */
/* Modified by : Faishal Reza A., Raka Andinan P., Resha Dwika Hefni Al-Fahsi, Vicko Pranowo. 11 March 2019 */

byte h=0,v=0;    //variables used in for loops
const unsigned long period=50;  //little period used to prevent error


unsigned long kdelay=0;        // variable used in non-blocking delay 


const byte rows=4;             //number of rows of keypad
const byte columns=4;            //number of columnss of keypad
const byte Output[rows]={16,17,18,19}; //array of pins used as output for rows of keypad
const byte Input[columns]={9,8,6,5}; //array of pins used as input for columnss of keypad

const byte sevenseg[8]={10,7,27,26,25,11,1,4};


byte keypad() // function used to detect which button is used 
{
 static bool no_press_flag=0;  //static flag used to ensure no button is pressed 
  for(byte x=0;x<columns;x++)   // for loop used to read all inputs of keypad to ensure no button is pressed 
  {
     if (digitalRead(Input[x])==HIGH);   //read evry input if high continue else break;
     else
     break;
     if(x==(columns-1))   //if no button is pressed 
     {
      no_press_flag=1;
      h=0;
      v=0;
     }
  }
  if(no_press_flag==1) //if no button is pressed 
  {
    for(byte r=0;r<rows;r++) //for loop used to make all output as low
    digitalWrite(Output[r],LOW);
    for(h=0;h<columns;h++)  // for loop to check if one of inputs is low
    {
      if(digitalRead(Input[h])==HIGH) //if specific input is remain high (no press on it) continue
      continue;
      else    //if one of inputs is low
      {
          for (v=0;v<rows;v++)   //for loop used to specify the number of row
          {
          digitalWrite(Output[v],HIGH);   //make specified output as HIGH
          if(digitalRead(Input[h])==HIGH)  //if the input that selected from first sor loop is change to high
          {
            no_press_flag=0;                //reset the no press flag;
            for(byte w=0;w<rows;w++) // make all outputs as low
            digitalWrite(Output[w],LOW);
            return v*4+h;  //return number of button 
          }
          }
      }
    }
  }
 return 50;
}
void setup() 
{
  for(byte i=0;i<rows;i++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(Output[i],OUTPUT);
  }

  
  for(byte j=0;j<=7;j++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(sevenseg[j],OUTPUT);
  }
  
  for(byte s=0;s<columns;s++)  //for loop used to makk pin mode of inputs as inputpullup
  {
    pinMode(Input[s],INPUT_PULLUP);
  }
  Serial.begin(9600); //to use serial monitor we set the buad rate
}

void clrall()
{
  for(int i=0;i<=7;i++)
  digitalWrite(sevenseg[i],LOW);
}

void ledon()
{

  for(int i=0;i<=7;i++)
  digitalWrite(sevenseg[i],HIGH);
  
}



void loop()
{
  if(millis()-kdelay>period) //used to make non-blocking delay
  {
    kdelay=millis();  //capture time from millis function
    
    clrall();
    switch (keypad())  //switch used to specify which button
    {
              
              case 0:
              {
                Serial.println(1);
                digitalWrite(sevenseg[1],HIGH);
                digitalWrite(sevenseg[2],HIGH);
                delay(1000);
                break;
              }  
              case 1:
              {         
                Serial.println(2);
                ledon();
                digitalWrite(sevenseg[2],LOW);
                digitalWrite(sevenseg[5],LOW);
                delay(1000);
                break;
              }
              case 2:
              {
                Serial.println(3);
                ledon();
                digitalWrite(sevenseg[4],LOW);
                digitalWrite(sevenseg[5],LOW);
                delay(1000);
                break;
              }
              case 4:
              {
                Serial.println(4);
                ledon();
                digitalWrite(sevenseg[0],LOW);
                digitalWrite(sevenseg[3],LOW);
                digitalWrite(sevenseg[4],LOW);
                delay(1000);
                break;
              }
              case 5:
              {
                Serial.println(5);
                ledon();
                digitalWrite(sevenseg[1],LOW);
                digitalWrite(sevenseg[4],LOW);
                delay(1000);
                break;
              }
              case 6:
              {
                Serial.println(6);
                ledon();
                digitalWrite(sevenseg[1],LOW);
                delay(1000);
                break;
              }
              case 8:
              {
                Serial.println(7);
                digitalWrite(sevenseg[0],HIGH);
                digitalWrite(sevenseg[1],HIGH);
                digitalWrite(sevenseg[2],HIGH);
                delay(1000);
                break;
              }
              case 9:
              {
                Serial.println(8);
                ledon();
                delay(1000);
                break;
              }
              case 10:
              {
                Serial.println(9);
                ledon();
                digitalWrite(sevenseg[4],LOW);
                delay(1000);
                break;
              }
              case 3:
              {
                Serial.println("A");
                ledon();
                digitalWrite(sevenseg[3],LOW);
                delay(1000);
                break;
              }
              case 7:
              {
                Serial.println("B");
                for(int i=2;i<=6;i++)
                {
                  digitalWrite(sevenseg[i],HIGH);
                }
                delay(1000);
                break;
              }
              
              case 11:
              {
                Serial.println("C");
                ledon();
                digitalWrite(sevenseg[1],LOW);
                digitalWrite(sevenseg[2],LOW);
                digitalWrite(sevenseg[6],LOW);
                digitalWrite(sevenseg[7],LOW);
                delay(1000);
                break;
              }

              case 13:
              {
                Serial.println(0);
                ledon();
                digitalWrite(sevenseg[6],LOW);
                delay(1000);

                break;
              }
              
              case 15:
              {
                Serial.println("d");
                for(int i=1;i<=4;i++)
                {
                  digitalWrite(sevenseg[i],HIGH);
                }
                digitalWrite(sevenseg[6],HIGH);
                delay(1000);
                break;
              }

              default:
              {
                digitalWrite(sevenseg[6],HIGH);
              }
              
          
        }
  }
}
