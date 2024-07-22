///@name Leo Doak
///@class CSC-370
///@date 2/29/2024

//g++ -o beziertest beziertest.cpp -O2 -lm -lpthread -I/usr/X11R6/include -L/usr/X11R6/lib -lm -lpthread -lX11

// For Bezier Curves

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
        //cout << x << ", " << y<< endl;
        coords_x.push_back(x);//appends x 
        coords_y.push_back(y);//appends y 
        image.draw_circle(x, y, 2, color);  //5 is dot size 
        window.display(image);
	}
  }
    cout << "User Picked: " << coords_x.size() << " points\n"; 
//image.save("BezierTestogpoints.bmp");
// creates the new vectors for storing the new points in 
vector<double> coords_x_new;  
vector<double> coords_y_new;


// this is the loop for each count 
// need to get the points at each tolerance level    
for (double count = 0.0 ; count < 1.00; count = count + 0.01){ 
    //cout << "Count: " << count << "\n";  
    //creates the points of each tolerance along each line 
    for(int i = 0; i < coords_x.size()-1;i++){ 
        
        //gets next tolerance point 
        double q_x = ((1.0-count) * coords_x[i]) + (count * coords_x[i+1]);
        double q_y = ((1.0-count) * coords_y[i]) + (count * coords_y[i+1]); 
            
        coords_x_new.push_back(q_x);//appends x 
        coords_y_new.push_back(q_y);//appends y 

    }
    
    vector<double> coords_x_tol; 
    vector<double> coords_y_tol;

   int length_x = coords_x_new.size(); 
   //cout << "length of x coords" << length_x << "\n";  

    while(length_x > 2){
         for(int i = 0; i < coords_x_new.size()-1;i++){
            
            double q_x = ((1.0-count) * coords_x_new[i]) + (count * coords_x_new[i+1]);
            double q_y = ((1.0-count) * coords_y_new[i]) + (count * coords_y_new[i+1]); 
                
            coords_x_tol.push_back(q_x);//appends x 
            coords_y_tol.push_back(q_y);//appends y 

         }
        coords_x_new.swap(coords_x_tol); 
        coords_y_new.swap(coords_y_tol);
        coords_x_tol.clear(); 
        coords_y_tol.clear();
        length_x = length_x - 1; 
    }
    int point_x = coords_x_new[0]; 
    int point_x1 = coords_x_new[1];
    int point_y = coords_y_new[0]; 
    int point_y1 = coords_y_new[1]; 

    double n_x =  ((point_x1 - point_x) * count ) + point_x; 
    double n_y =  ((point_y1 - point_y) * count ) + point_y;
    unsigned char color1[] = {0,0,255} ;   //blue 
    image.draw_circle(n_x,n_y,3,color1) ; 

    coords_x_new.clear(); 
    coords_y_new.clear(); 
}

//image.save("BezierTestConnec.bmp");
//Display an image
CImgDisplay disp(image);
//Keeps image displayed
while(!disp.is_closed())
    disp.wait(); 

return 0; 
}