//#include <wingdi.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>


//using namespace std;

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
  int where = 1;
  int speed = 0;

    std::cout << "How Fast in milliseconds? (Type 0 for default)";
    std::cin >> speed;
    if(speed == 0){ speed = 100;};


  std::cout << "press k to start clicking";
  goto stop;

  start:
    //sleep for a bit to control clicking speed
    std::this_thread::sleep_for(std::chrono::milliseconds(speed));

    MouseClick();
    MouseUp();

      if(GetAsyncKeyState(75) < 0)   //75 = 'k'
        {
          //cout << "stop";
          goto inBetween;
        }else{
          goto start;
        }


        inBetween:
          if(GetAsyncKeyState(75) == 0){
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

    if(GetAsyncKeyState(75) < 0)
      {
        //cout << "start";
        goto inBetween;
      }else{
        goto stop;
      }





}
