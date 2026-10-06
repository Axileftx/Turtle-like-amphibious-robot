#define BLINKER_BLE

#include <Blinker.h>
#include <SoftwareSerial.h>
#include <string.h> 

SoftwareSerial mySerial(12, 13); // RX, TX
SoftwareSerial mySerial2(10, 11); // RX, TX
#include <Arduino.h>

#define Angle_turn  30
#define Delay_time  200
#define IN1 16
#define IN2 17
#define IN3 18
#define IN4 19
#define IN5 8
#define IN6 9
#define IN7 14
#define IN8 15

BlinkerButton Button1("btn-1");
BlinkerButton Button2("btn-2");
BlinkerButton Button3("btn-3");
BlinkerButton Button4("btn-4");
BlinkerButton Button5("btn-5");
BlinkerButton Button6("btn-6");
BlinkerButton Button7("btn-7");
BlinkerButton Button8("btn-8");
BlinkerButton Button9("btn-9");
BlinkerButton Button10("btn-10");
void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);

}

int task = 0;
void button1_callback(const String & state)
{
  task = 1;
}
void button2_callback(const String & state)
{
  task = 2;
}
void button3_callback(const String & state)
{
  task = 3;
}
void button4_callback(const String & state)
{
  task = 4;
}
void button5_callback(const String & state)
{
  task = 5;
}
void button6_callback(const String & state)
{
  task = 6;
}
void button7_callback(const String & state)
{
  task = 7;
}
void button8_callback(const String & state)
{
  task = 8;
}
void button9_callback(const String & state)
{
  task = 9;
}
void button10_callback(const String & state)
{
  task = 10;
}

bool UARTWrite1(unsigned char reg_addr,unsigned char date)
{
  unsigned char date1 = 0;
  unsigned char date2 = 0;
  unsigned char date3 = 0;
  reg_addr = 64 + reg_addr;
  date1 = date/100 + 48;
  date2 = (date%100)/10 + 48;
  date3 = date%10 + 48;
  mySerial.write(0x24);
  mySerial.write(reg_addr);
  mySerial.write(date1);
  mySerial.write(date2);
  mySerial.write(date3);
  mySerial.write(0x23);
//  delay(50);
  return true;  
}
bool UARTWrite2(unsigned char reg_addr,unsigned char date)
{
  unsigned char date1 = 0;
  unsigned char date2 = 0;
  unsigned char date3 = 0;
  reg_addr = 64 + reg_addr;
  date1 = date/100 + 48;
  date2 = (date%100)/10 + 48;
  date3 = date%10 + 48;
  mySerial2.write(0x24);
  mySerial2.write(reg_addr);
  mySerial2.write(date1);
  mySerial2.write(date2);
  mySerial2.write(date3);
  mySerial2.write(0x23);
//  delay(50);
  return true;  
}

//FLOAT UP
void TurtleSwimUP()   
{

  // Stand with motor on
    UARTWrite1(1, 35);
    UARTWrite1(2, 100);
    UARTWrite1(3, 75);
    UARTWrite1(9, 45);
    UARTWrite1(10,80);
    UARTWrite1(11,80); //20   80
    UARTWrite2(1, 110);
    UARTWrite2(2, 60);
    UARTWrite2(3, 95); //40   90
    UARTWrite2(9, 40); //50
    UARTWrite2(10,35);
    UARTWrite2(11,75);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}

// Float DOWN
void TurtleSwimDOWN()  {

  // Stand with motor on
    UARTWrite1(1, 35);
    UARTWrite1(2, 100);
    UARTWrite1(3, 75);
    UARTWrite1(9, 45);
    UARTWrite1(10,80);
    UARTWrite1(11,80); //20   80
    UARTWrite2(1, 110);
    UARTWrite2(2, 60);
    UARTWrite2(3, 95); //40   90
    UARTWrite2(9, 40); //50
    UARTWrite2(10,35);
    UARTWrite2(11,75);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

//Swim Forward
void TurtleSwimForward()
{
  
  UARTWrite1(1, 80);    // Left Forward
  UARTWrite1(2, 100);
  UARTWrite1(3, 0);

  UARTWrite2(9, 15);    // Left Back
  UARTWrite2(10,35);
  UARTWrite2(11,20);

  UARTWrite1(9, 15);    // Right Forward
  UARTWrite1(10,80);
  UARTWrite1(11,30);    

  UARTWrite2(1, 135);   // Right Back
  UARTWrite2(2, 60);
  UARTWrite2(3, 5);

  digitalWrite(IN1, LOW);     // Motor Right Forward
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);    // Motor Right Back
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, HIGH);    // Motor Left Back
  digitalWrite(IN6, LOW);

  digitalWrite(IN7, LOW);     // Motor Left Forward
  digitalWrite(IN8, HIGH);

}

// SwimLeft
void TurtleSwimLeft() 
{

  UARTWrite1(1, 0);     // Left Forward
  UARTWrite1(2, 100);
  UARTWrite1(3, 0);

  UARTWrite2(9, 65);    // Left Back
  UARTWrite2(10,35);
  UARTWrite2(11,20);

  UARTWrite1(9, 70);    // Right Forward
  UARTWrite1(10,80);
  UARTWrite1(11,30);    

  UARTWrite2(1, 80);    // Right Back
  UARTWrite2(2, 60);
  UARTWrite2(3, 5);

  digitalWrite(IN1, HIGH);     // Motor Right Forward
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);     // Motor Right Back
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);      // Motor Left Back
  digitalWrite(IN6, HIGH);

  digitalWrite(IN7, LOW);      // Motor Left Forward
  digitalWrite(IN8, HIGH);

}

void stand()
{
    UARTWrite1(1,35);
    UARTWrite1(2,50);
    UARTWrite1(3,75);
    UARTWrite1(9,45);
    UARTWrite1(10,80);
    UARTWrite1(11,80);//20   80
    UARTWrite2(1,110);
    UARTWrite2(2,60);
    UARTWrite2(3,95);//40   90
    UARTWrite2(9,40);//50
    UARTWrite2(10,15);
    UARTWrite2(11,75);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);

  delay(10);
  }
  
void TurtleForward()
{
  // 左后腿前进到平
  UARTWrite1(10,70);    // 抬起左后腿 (并通过右前弯曲抬高重心)
  UARTWrite2(10,20);
  delay(50);
  UARTWrite2(11,100);   // 抬爪子
  UARTWrite2(9, 70);    // 左后腿前进
  delay(100);
  UARTWrite1(10,80);    // (左后右前恢复，乌龟四脚落地)
  UARTWrite2(10,35);
  UARTWrite2(11,80);    // 抬爪子
  delay(50);
  
  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 左前腿前进20度
  UARTWrite2(2, 50);    // 抬起左前腿 (并通过右后弯曲抬高重心)
  UARTWrite1(2, 90);
  delay(50);
  UARTWrite1(3, 95);    // 抬爪子
  UARTWrite1(1, 65);    // 左前腿前进
  delay(100);
  UARTWrite2(2, 60);    // (左前右后恢复，乌龟四脚落地)
  UARTWrite1(2, 100);
  UARTWrite1(3, 75);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 左前左后同时恢复且右前摆平
  UARTWrite1(1, 35);    // 左前 左后 恢复
  UARTWrite2(9, 35);
  UARTWrite1(9, 70);    // 右前摆动到平
  delay(100);
    
  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右后腿前进到平
  UARTWrite1(2, 90);    // 抬起右后腿 (通过左前弯曲抬高重心)
  UARTWrite2(2, 50);
  delay(50);
  UARTWrite2(3, 115);   // 抬爪子
  UARTWrite2(1, 80);    // 右后腿前进
  delay(100);
  UARTWrite1(2, 100);   // (右后左前恢复，乌龟四脚落地)
  UARTWrite2(2, 60);
  UARTWrite2(3, 95);   // 抬爪子
  delay(50);
    
  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右前往前到30度
  UARTWrite2(10,20);    // 抬起右前腿 (并通过左后弯曲抬高重心)
  UARTWrite1(10,65);
  delay(50);
  UARTWrite1(11,100);   // 抬爪子
  UARTWrite1(9, 25);
  delay(100);
  UARTWrite2(10,35);    // (右前左后恢复，乌龟四脚落地)
  UARTWrite1(10,80);
  UARTWrite1(11,80);   // 抬爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右前右后同时恢复且左前摆平
  UARTWrite1(9, 45);
  UARTWrite2(1, 110);
  UARTWrite1(1, 0);
  delay(100);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);
    }
    
void TurtleBackward()   {

  // 右前腿后退到平
  UARTWrite2(10,20);    // 抬起右前腿 (并通过左后弯曲抬高重心)
  UARTWrite1(10,65);
  delay(50);
  UARTWrite1(11,100);   // 抬爪子
  UARTWrite1(9, 70);    // 右前腿后退到平
  delay(100);
  UARTWrite2(10,35);    // (右前左后恢复，乌龟四脚落地)
  UARTWrite1(10,80);
  UARTWrite1(11,80);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右后腿后退30度
  UARTWrite1(2, 90);    // 抬起右后腿 (通过左前弯曲抬高重心)
  UARTWrite2(2, 50);
  delay(50);
  UARTWrite2(3, 115);   // 抬爪子
  UARTWrite2(1, 125);   // 右后腿后退
  delay(100);
  UARTWrite1(2, 100);   // (右后左前恢复，乌龟四脚落地)
  UARTWrite2(2, 60);
  UARTWrite2(3, 95);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右前右后同时恢复且左后往前摆平
  UARTWrite1(9, 45);
  UARTWrite2(1, 110);
  UARTWrite2(9, 70);
  delay(100);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 左前腿往后到放平
  UARTWrite2(2, 50);    // 抬起左前腿 (并通过右后弯曲抬高重心)
  UARTWrite1(2, 90);
  delay(50);
  UARTWrite1(3, 95);    // 抬爪子
  UARTWrite1(1, 5);     // 左前腿往后到平
  delay(100);
  UARTWrite2(2, 60);    // (左前右后恢复，乌龟四脚落地)
  UARTWrite1(2, 100);
  UARTWrite1(3, 75);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 左后腿往后到30度
  UARTWrite1(10,70);    // 抬起左后腿 (并通过右前弯曲抬高重心)
  UARTWrite2(10,20);
  delay(50);
  UARTWrite2(11,100);   // 抬爪子
  UARTWrite2(9, 20);    // 左后腿后退
  delay(100);
  UARTWrite1(10,80);    // 抬起左后腿 (并通过右前弯曲抬高重心)
  UARTWrite2(10,35);
  UARTWrite2(11,80);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 左前左后同时恢复右边后放平
  UARTWrite1(1, 35);    // 左前 左后 恢复
  UARTWrite2(9, 35);
  UARTWrite2(1, 80);
  delay(100);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

}

void TurtleSpinCW()
{
  // 右前向后20度
  UARTWrite2(10,20);    // 抬起右前腿 (并通过左后弯曲抬高重心)
  UARTWrite1(10,65);
  delay(50);
  UARTWrite1(11,100);   // 抬爪子
  UARTWrite1(9, 65);    
  delay(100);
  UARTWrite2(10,35);    // (右前左后恢复，乌龟四脚落地)
  UARTWrite1(10,80);
  UARTWrite1(11,80);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右后向后20度
  UARTWrite1(2, 90);    // 抬起右后腿 (通过左前弯曲抬高重心)
  UARTWrite2(2, 50);
  delay(50);
  UARTWrite2(3, 115);   // 抬爪子
  UARTWrite2(1, 130);   // 右后腿后退
  delay(100);
  UARTWrite1(2, 100);   // (右后左前恢复，乌龟四脚落地)
  UARTWrite2(2, 60);
  UARTWrite2(3, 95);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 左后向前20度
  UARTWrite1(10,70);    // 抬起左后腿 (并通过右前弯曲抬高重心)
  UARTWrite2(10,20);
  delay(50);
  UARTWrite2(11,100);   // 抬爪子
  UARTWrite2(9, 55);    // 左后腿向前
  delay(100);
  UARTWrite1(10,80);    // 抬起左后腿 (并通过右前弯曲抬高重心)
  UARTWrite2(10,35);
  UARTWrite2(11,80);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 拧，集体拧20度
  UARTWrite1(9, 45);    // 65  >> 45
  UARTWrite2(1, 110);   // 130 >> 110
  UARTWrite2(9, 35);    // 55  >> 35
  UARTWrite1(1, 15);    // 左前往后20度
  delay(100);

  // 左前向前20度
  UARTWrite2(2, 50);    // 抬起左前腿 (并通过右后弯曲抬高重心)
  UARTWrite1(2, 90);
  delay(50);
  UARTWrite1(3, 95);    // 抬爪子
  UARTWrite1(1, 55);    // 左前腿前进
  delay(100);
  UARTWrite2(2, 60);    // (左前右后恢复，乌龟四脚落地)
  UARTWrite1(2, 100);
  UARTWrite1(3, 75);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);
  }
  
void TurtleSpinCCW()
{
  // 左前向后20度
  UARTWrite2(2, 50);    // 抬起左前腿 (并通过右后弯曲抬高重心)
  UARTWrite1(2, 90);
  delay(50);
  UARTWrite1(3, 95);    // 抬爪子
  UARTWrite1(1, 15);    // 左前腿前进
  delay(100);
  UARTWrite2(2, 60);    // (左前右后恢复，乌龟四脚落地)
  UARTWrite1(2, 100);
  UARTWrite1(3, 75);    // 收爪子
  delay(50);
  
  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);
  
  // 左后向后20度
  UARTWrite1(10,70);    // 抬起左后腿 (并通过右前弯曲抬高重心)
  UARTWrite2(10,20);
  delay(50);
  UARTWrite2(11,100);   // 抬爪子
  UARTWrite2(9, 15);    // 左后腿向后
  delay(100);
  UARTWrite1(10,80);    // 抬起左后腿 (并通过右前弯曲抬高重心)
  UARTWrite2(10,35);
  UARTWrite2(11,80);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右后向前20度
  UARTWrite1(2, 90);    // 抬起右后腿 (通过左前弯曲抬高重心)
  UARTWrite2(2, 50);
  delay(50);
  UARTWrite2(3, 115);   // 抬爪子
  UARTWrite2(1, 90);    // 右后腿向前
  delay(100);
  UARTWrite1(2, 100);   // (右后左前恢复，乌龟四脚落地)
  UARTWrite2(2, 60);
  UARTWrite2(3, 95);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 拧，集体拧20
  UARTWrite1(1, 35);
  UARTWrite2(9, 35);
  UARTWrite2(1, 110);
  UARTWrite1(9, 65);    // 右前向后20度 
  delay(100);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);

  // 右前恢复20度
  UARTWrite2(10,20);    // 抬起右前腿 (并通过左后弯曲抬高重心)
  UARTWrite1(10,65);
  delay(50);
  UARTWrite1(11,100);   // 抬爪子
  UARTWrite1(9, 45);    
  delay(100);
  UARTWrite2(10,35);    // (右前左后恢复，乌龟四脚落地)
  UARTWrite1(10,80);
  UARTWrite1(11,80);    // 收爪子
  delay(50);

  UARTWrite1(3, 75);
  UARTWrite2(11,75);
  UARTWrite1(11,80);
  UARTWrite2(3, 95);
  }

//void dataRead(const String & data)
//{
//    BLINKER_LOG("Blinker readString: ", data);
//} 
void setup()
{
  // 螺旋桨推进初始化及初值
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);

  //串口初始化
  Serial.begin(9600);
  
  mySerial.begin(9600);
  mySerial2.begin(9600);
  
  BLINKER_DEBUG.stream(Serial);
  Blinker.begin(2,3,9600);

  //连接Blinker
  Button1.attach(button1_callback);
  Button2.attach(button2_callback);
  Button3.attach(button3_callback);
  Button4.attach(button4_callback);
  Button5.attach(button5_callback);
  Button6.attach(button6_callback);
  Button7.attach(button7_callback);
  Button8.attach(button8_callback);
  Button9.attach(button9_callback);
  Button10.attach(button10_callback);
  Blinker.attachData(dataRead);

  // 位姿初始化
  delay(200);
  stand();
  delay(200);
}
int pin_flag=0,value_flag=0,pin,value;
void loop()
{   
  Blinker.run();

  // ON LAND
  if (task == 1)
  {
    TurtleForward();
  }
  if (task == 2)
  {
    TurtleBackward();
  }
  if (task == 9)
  {
    TurtleSpinCCW();
  }
  if (task == 8)
  {
    TurtleSpinCW();
  }
  if (task == 7)
  {
    stand();
  }

  // IN WATER
  if (task == 11)
  {
    TurtleSwimUP();
  }
  if (task == 12)
  {
    TurtleSwimDOWN();
  }
  if (task == 5)
  {
    TurtleSwimForward();
  }
  if (task == 3)
  {
    TurtleSwimLeft();
  }
  if (task == 10)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
     
  }
    
    if(Serial.available())
    {
      String str = Serial.readString();
      if (!pin_flag) 
        {pin_flag=1;pin = str.toInt();}
      else
         {value_flag=1;value = str.toInt();}
      if(pin_flag && value_flag)
      {
        UARTWrite2(pin,value);
        Serial.print("pin:");
        Serial.print(pin);
        Serial.print("  value:");
        Serial.println(value);
        pin_flag=0;
        value_flag=0;
        }
    }  
      
}
