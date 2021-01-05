#include <wingdi.h>
#include <windows.h>
#include <iostream>


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

  start:
      if(GetAsyncKeyState(75) < 0)   //75 = 'k'
        {
          //cout << "stop";
          goto inBetween;
        }else{
          goto start;
        }


        inBetween:
          if(GetAsyncKeyState(75) == 0){

            if(where == 0){
              MouseClick();
              where = 1;
              goto stop;
            }else{
              MouseUp();
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
