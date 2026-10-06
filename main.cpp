#include <iostream>
#include <cmath>
#include <cstring>
#include <thread>
#include <chrono>

int main(){
    const int width = 80;
    const int height = 40;
  
    float A = 0;
    float B = 0;
  
    const float R1 = 1.0f;
    const float R2 = 2.0f;
  
    const float K2 = 5.0f;
  
    const char* chars = ".,-~:;=!*#$@";

    while(true){
        char output[width*height];
        float zbuffer[width*height];

        std::memset(output,' ',sizeof(output));
        std::fill(zbuffer,zbuffer+width*height,0.0f);

        for(float theta = 0; theta < 2 * M_PI; theta += 0.07f){
            for(float phi = 0; phi < 2 * M_PI; phi += 0.02f){
              
                float circleX = R2 + R1 * cos(theta);
                float circleY = R1 * sin(theta);

                float x = circleX * (cos(B)*cos(phi)+sin(A)*sin(B)*sin(phi))-circleY*cos(A)*sin(B);
                float y = circleX * (sin(B)*cos(phi)-sin(A)*cos(B)*sin(phi))+circleY*cos(A)*cos(B);
                float z = K2 + cos(A)*circleX*sin(phi)+circleY*sin(A);
              
                float ooz = 1.0f / z;
              
                int xp = static_cast<int>(width/2+35*ooz*x);
                int yp = static_cast<int>(height/2-18*ooz*y);

                float L = cos(phi)*cos(theta)*sin(B)-cos(A)*cos(theta)*sin(phi)-sin(A)*sin(theta)*cos(B)*cos(A)*sin(theta)-cos(theta)*sin(A)*sin(phi);

                int luminance = static_cast<int>(8*L);

                if(luminance < 0) luminance = 0;
                if(luminance > 11) luminance = 11;
                
                int index = xp + yp * width;

                if(xp >= 0 && xp < width && yp >= 0 && yp < height && ooz > zbuffer[index]){
                    zbuffer[index] = ooz;
                    output[index] = chars[luminance];
                }
            }
        }
        std::cout<<"\x1b[H";
      
        for(int i=1;i<width*height;++i){
            std::cout<<(i%width?output[i]:'\n');
        }
      
        A += 0.05f;
        B += 0.02f;
      
        std::this_thread::sleep_for(
            std::chrono::milliseconds(30)
        );
    }
  
    return 0;
}
