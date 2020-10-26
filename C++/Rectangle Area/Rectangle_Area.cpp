#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

/*
 *class Rectangle  
 * The class should have the following : 
 *
 * Member Variables: 
 * int width // an integer that represents the width of the rectangle
 * int height // an integer that represents the height of the rectangle
 *
 * Member Functions:
 * void read_input() // Reads the values from the input stream into width and height
 * void display () // Sends the values of width and height to output stream 
 *
*/
class Rectangle{
    protected:
        int width;
        int height;

    public:
        c read_input(){
            cin >> width;
            cin >> height;
        }

        void display(){
            cout << width << " "<< height << endl;
        }

};

/*
 *class RectangleArea  
 * The class should have the following : 
 *
 * Member Variables: 
 * int Area // an integer that represents the area of the rectangle
 *
 * Member Functions:
 * void display () // Sends the value of the area to output stream 
 *
*/
class RectangleArea:public Rectangle{
    private:
        int Area;

    public:

        void display(){
            cout << width * height;
        }

};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
