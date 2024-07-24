///@name Leo Doak
///@class CSC-370
///@date 2/29/2024

//g++ -o Chaikins-Algorithm.exe Chaikins-Algorithm.cpp -O2 -lm -lpthread -I/usr/X11R6/include -L/usr/X11R6/lib -lm -lpthread -lX11

//For Chaikins algorithm curves
#include <iostream>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

int main (){
    vector <int> coords_x; 
    vector <int> coords_y;
    CImg<unsigned char> image(500,500,1,3,0); 
    CImgDisplay window(image, "Click control points");
    unsigned char color[] = { 255,128,64 };
    while (!window.is_closed()){
    window.wait();
    if (window.button()){
        int x = window.mouse_x();
        int y = window.mouse_y();
        cout << x << ", " << y<< endl;
        coords_x.push_back(x);//appends x 
        coords_y.push_back(y);//appends y 
        image.draw_circle(x, y, 2, color);  //5 is dot size 
        window.display(image);
	}
  }
  //image.save("CurveTestpoint.bmp");
    cout << "User Picked: " << coords_x.size() << " points\n"; 

    vector<int> coords_x_new; 
    vector<int> coords_y_new;

//lines and stuff 
    
for (int count = 0; count < 7; count ++){ 
    //image.save("CurveTestconnec.bmp");
    
    unsigned char color[] = {};
    //	* you can also set a random value:
	color[0] = rand()%255;
	color[1] = rand()%255;
	color[2] = rand()%255;

    // draw line function 
    for(int i = 0; i < coords_x.size()-1;i++){ //connect line segments
        image.draw_line(coords_x[i], coords_y[i], coords_x[i+1], coords_y[i+1], color); 
    } 
    // create list for points    
    for(int i = 0; i < coords_x.size()-1;i++){
            double q_x = ((3.0 / 4.0) * coords_x[i]) + ((1.0 / 4.0) * coords_x[i+1]);
            double q_y = ((3.0 / 4.0) * coords_y[i]) + ((1.0 / 4.0) * coords_y[i+1]); 
            coords_x_new.push_back(q_x);//appends q_x 
            coords_y_new.push_back(q_y);//appends q_y  
            double r_x = ((1.0 / 4.0) * coords_x[i]) + ((3.0 / 4.0) * coords_x[i+1]);
            double r_y = ((1.0 / 4.0) * coords_y[i]) + ((3.0 / 4.0) * coords_y[i+1]); 
            coords_x_new.push_back(r_x);//appends r_x 
            coords_y_new.push_back(r_y);//appends r_y
    }
    coords_x.clear();
    coords_y.clear();
    coords_x = coords_x_new; 
    coords_y = coords_y_new; 
    coords_x_new.clear(); //erease the vector
    coords_y_new.clear();

    
    //Display an image
    CImgDisplay disp(image);
    //Keeps image displayed
    while(!disp.is_closed())
        disp.wait(); 

     
    }

//image.save("CurveTest3point.bmp");
return 0; 
}