class Rectangle
{
public:

    Rectangle(double len = 1.0, double wid = 1.0);
    Rectangle();

    // Setters for dimensions
    void setLength(double);
    void setWidth(double);

    // Getters for dimensions
    double getLength();
    double getWidth();

    // Area and perimeter calculation
    double getArea(double, double);
    double getPerimeter(double, double);

    // Drawing functions
    void draw();
    void setFillCharacter(char);
    void setPerimeterCharacter(char);

private:
    double length;
    double width;

    // Characters for drawing
    char fillChar = ' ';
    char borderChar = '*';
    
    // Helper function for drawing
    void drawRectangle(int startX, int startY, int endX, int endY);
};

