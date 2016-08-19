#ifndef CAR_CONTROLLERS_PIN
#define CAR_CONTROLLERS_PIN
  //Wheel FL  
  #define FORWARD_LEFT_MOVE_FORWARD 5
  #define FORWARD_LEFT_MOVE_BACKWARD 4

  //Wheel FR
  #define FORWARD_RIGHT_MOVE_FORWARD 9
  #define FORWARD_RIGHT_MOVE_BACKWARD 8

  //Wheel BL
  #define BACKWARD_LEFT_MOVE_FORWARD 6  
  #define BACKWARD_LEFT_MOVE_BACKWARD 7

  //Wheel BR
  #define BACKWARD_RIGHT_MOVE_FORWARD 10
  #define BACKWARD_RIGHT_MOVE_BACKWARD 11

#endif

#define ONE_SECOND 1000
#define TEN_DEG 125


void car_forward()
{
  digitalWrite(FORWARD_LEFT_MOVE_FORWARD, HIGH);  
  digitalWrite(FORWARD_RIGHT_MOVE_FORWARD, HIGH); 
  digitalWrite(BACKWARD_LEFT_MOVE_FORWARD, HIGH); 
  digitalWrite(BACKWARD_RIGHT_MOVE_FORWARD, HIGH); 
}


void car_backward()
{
  digitalWrite(FORWARD_LEFT_MOVE_BACKWARD, HIGH);  
  digitalWrite(FORWARD_RIGHT_MOVE_BACKWARD, HIGH); 
  digitalWrite(BACKWARD_LEFT_MOVE_BACKWARD, HIGH); 
  digitalWrite(BACKWARD_RIGHT_MOVE_BACKWARD, HIGH); 
}


void car_stop_forward()
{
  //  disable forward wheels:
  digitalWrite(FORWARD_LEFT_MOVE_FORWARD, LOW);  
  digitalWrite(FORWARD_RIGHT_MOVE_FORWARD, LOW); 
  digitalWrite(BACKWARD_LEFT_MOVE_FORWARD, LOW); 
  digitalWrite(BACKWARD_RIGHT_MOVE_FORWARD, LOW);
}



void car_stop_backward()
{
  // disable backward wheels: 
  digitalWrite(FORWARD_LEFT_MOVE_BACKWARD, LOW);  
  digitalWrite(FORWARD_RIGHT_MOVE_BACKWARD, LOW); 
  digitalWrite(BACKWARD_LEFT_MOVE_BACKWARD, LOW); 
  digitalWrite(BACKWARD_RIGHT_MOVE_BACKWARD, LOW);
}

void car_turn_left()
{
  //turn left 
 digitalWrite(FORWARD_LEFT_MOVE_BACKWARD, HIGH);   
 digitalWrite(BACKWARD_LEFT_MOVE_BACKWARD, HIGH); 
 digitalWrite(FORWARD_RIGHT_MOVE_FORWARD, HIGH); 
 digitalWrite(BACKWARD_RIGHT_MOVE_FORWARD, HIGH);
}

void car_turn_right()
{
  digitalWrite(FORWARD_RIGHT_MOVE_BACKWARD, HIGH);
  digitalWrite(BACKWARD_RIGHT_MOVE_BACKWARD, HIGH);
  digitalWrite(FORWARD_LEFT_MOVE_FORWARD, HIGH);  
  digitalWrite(BACKWARD_LEFT_MOVE_FORWARD, HIGH);
}

void car_full_stop()
{
  car_stop_forward();
  car_stop_backward();
}

void car_turn_left_ten()
{
  car_turn_left();
  delay(TEN_DEG);
  car_full_stop();
}

void car_turn_right_ten()
{
  car_turn_right();
  delay(TEN_DEG);
  car_full_stop();
}

void car_turn_left_90()
{
  car_turn_left();
  delay(TEN_DEG*9);
  car_full_stop();
}

void car_turn_right_90()
{
  car_turn_right();
  delay(TEN_DEG*9);
  car_full_stop();
 }
void car_forward_step()
{
  car_forward();
  delay(ONE_SECOND);
  car_full_stop(); 
}

 void car_backward_step()
 {
  car_backward();
  delay(ONE_SECOND);
  car_full_stop();
 }



void setup() 
{ 
  pinMode(FORWARD_LEFT_MOVE_FORWARD, OUTPUT);
  pinMode(FORWARD_LEFT_MOVE_BACKWARD, OUTPUT);
  pinMode(FORWARD_RIGHT_MOVE_FORWARD, OUTPUT);
  pinMode(FORWARD_RIGHT_MOVE_BACKWARD, OUTPUT);
  pinMode(BACKWARD_LEFT_MOVE_FORWARD, OUTPUT);
  pinMode(BACKWARD_LEFT_MOVE_BACKWARD, OUTPUT);
  pinMode(BACKWARD_RIGHT_MOVE_FORWARD, OUTPUT);  
  pinMode(BACKWARD_RIGHT_MOVE_BACKWARD, OUTPUT);

  int baud_rate = 9600;  
  Serial.begin(baud_rate);
  
 }




void loop() 
{   
  while (Serial.available())
  { 
      char in_byte = Serial.read();
    
      if(in_byte == 'F' )
      {
        car_forward_step();
      }
       
      if (in_byte == 'B')
        {
          car_backward_step();
        }
         
       if(in_byte == '3')
          {
            car_full_stop();
          }
    
       if(in_byte == 'L')
        {
        car_turn_left_90();
        }
  
      if(in_byte == 'R')
        {
        car_turn_right_90();
        }
  }
}   
