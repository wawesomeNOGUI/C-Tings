#include <wingdi.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void MouseClick ()
{
  //double fScreenWidth    = ::GetSystemMetrics( SM_CXSCREEN )-1;
  //double fScreenHeight  = ::GetSystemMetrics( SM_CYSCREEN )-1;
  //double fx = x*(65535.0f/fScreenWidth);
  //double fy = y*(65535.0f/fScreenHeight);
  INPUT  Input={0};
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1,&Input,sizeof(INPUT));
}

void MouseUp () {
  INPUT  Input={0};
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  ::SendInput(1,&Input,sizeof(INPUT));
}



int main(){
  int where = 0;
  int counter = 0;
  int speed = 0;

    cout << "How Fast? (Type 0 for default)";
    cin >> speed;
    if(speed == 0){ speed = 6;};

  int seconds;
  seconds = time (NULL);
  //printf ("%ld seconds since January 1, 1970", seconds);
  cout << "press k to start clicking";
  goto stop;

  start:
    /*if((time(NULL) - seconds) >= 1 && counter == 0){
    //  cout << counter;
      MouseClick();
      seconds = time(NULL);
      counter = 1;
      cout << seconds;
    }
*/
      //cout << time(NULL) - seconds;
      //cout << time(NULL);
      if((time(NULL) - seconds) >= 1 ){
      //  cout << counter;
        for(int i = 0; i<=speed; i++){
          MouseClick();
          MouseUp();
        }
        seconds = time(NULL);
        //counter = 0;
        //cout << seconds;
      }



      if(GetAsyncKeyState(75) < 0)   //75 = 'k'
        {
          //cout << "stop";
          goto inBetween;
        }else{
          goto start;
        }


        inBetween:
          if(GetAsyncKeyState(75) == 0){
            counter = 0;
            MouseUp();
            if(where == 0){
              //MouseClick();
              where = 1;
              goto stop;
            }else{
              //MouseUp();
              where = 0;
              goto start;
            }

          }
        goto inBetween;




  stop:
    counter = 0;
    if(GetAsyncKeyState(75) < 0)
      {
        //cout << "start";
        goto inBetween;
      }else{
        goto stop;
      }





}
