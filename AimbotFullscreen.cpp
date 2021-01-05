#include <wingdi.h>
#include <windows.h>
#include <cmath>
#include <iostream>


using namespace std;

void MouseMove (int x, int y )
{
  //double fScreenWidth    = ::GetSystemMetrics( SM_CXSCREEN )-1;
  //double fScreenHeight  = ::GetSystemMetrics( SM_CYSCREEN )-1;
  //double fx = x*(65535.0f/fScreenWidth);
  //double fy = y*(65535.0f/fScreenHeight);
  INPUT  Input={0};
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
  Input.mi.dx = x;
  Input.mi.dy = y;
  ::SendInput(1,&Input,sizeof(INPUT));
}

void CaptureScreen()
{
    int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
    //HWND hDesktopWnd = GetDesktopWindow();
    HDC hDesktopDC = GetDC(NULL);
    //HDC hDesktopDC =  CreateDC("DISPLAY", NULL, NULL, NULL);
    HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
    HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, nScreenWidth, nScreenHeight);
    SelectObject(hCaptureDC, hCaptureBitmap);


    BitBlt(hCaptureDC, 0, 0, nScreenWidth, nScreenHeight, hDesktopDC, 0,0, SRCCOPY);
    //POINT orig;
    // GetCursorPos(&cursor);
    //BitBlt(hCaptureDC, cursor.x, cursor.y, 100, 100, hDesktopDC, 0,0, SRCCOPY);

    BITMAPINFO bmi = {0};
    bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
    bmi.bmiHeader.biWidth = nScreenWidth;
    bmi.bmiHeader.biHeight = nScreenHeight;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    RGBQUAD *pPixels = new RGBQUAD[nScreenWidth * nScreenHeight];

    GetDIBits(
        hCaptureDC,
        hCaptureBitmap,
        0,
        nScreenHeight,
        pPixels,
        &bmi,
        DIB_RGB_COLORS
    );

    //for which color to search for
    BYTE redYee = 140;
    BYTE GYee = 50;
    BYTE BYee = 50;


    // write:
    int p;
    int x, y;

    //for saving pixel location of color:
    //int pX;
    //int pY;






    for(y = 0; y < nScreenHeight; y++){
        for(x = 0; x < nScreenWidth; x++){
            p = (nScreenHeight-y-1)*nScreenWidth+x; // upside down

              if(pPixels[p].rgbRed >= redYee && pPixels[p].rgbGreen <= GYee && pPixels[p].rgbBlue <= BYee){


                  MouseMove(x, y);
                    //cout << "noice";
                    goto exitLoop;  //jumps to the line labled exitLoop

              }
        }
    }

    exitLoop:;

    delete [] pPixels;

    ReleaseDC(NULL, hDesktopDC);
    DeleteDC(hCaptureDC);
    DeleteObject(hCaptureBitmap);

  //  return pX, pY;
}

int main(){
  int where = 0;

  start:
    CaptureScreen();

      if(GetAsyncKeyState(75) < 0)   //75 = 'k'
        {
          //cout << "stop";
          goto inBetween;
        }else{
          goto start;
        }


        inBetween:
          if(GetAsyncKeyState(75) == 0){
            //CaptureScreen();
            if(where == 0){
              where = 1;
              goto stop;
            }else{
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
