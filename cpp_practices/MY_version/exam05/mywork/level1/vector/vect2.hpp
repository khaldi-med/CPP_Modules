#include <string>
#include <iostream>

class vector2{
//Part 1:
    private:
        int x, y;
    public:
        vector2(): x(0), y(0) {}; 

        vector2(int _x, int _y): x(_x), y(_y) {};
        vector2(const vector2 &oth): x(oth.x), y(oth.y) {};
        vector2 operator=(const vector2 &oth){
            if(this != &oth){
                x = oth.x;
                y = oth.y;
            }
            return *this;
        }

//Part 2:
        int& operator[](int i){
            if(i==0)
                return x;
            else
                return y;
        }

        int operator[](int i) const {
            if(i==0)
                return x;
            else
                return y;        
        }

//Part 3:
        vector2 &operator++(){x++; y++; return *this;}
        vector2 operator++(int){vector2 tmp = *this; x++; y++; return tmp;}
        vector2 &operator--(){x--; y--; return *this;}
        vector2 operator--(int){vector2 tmp = *this; x--; y--; return tmp;}

//Part 4:
    
        vector2 &operator+=(const vector2& oth){
            x += oth.x;
            y += oth.y;
            return *this;
        }

        vector2 &operator-=(const vector2& oth){
            x -= oth.x;
            y -= oth.y;
            return *this;
        }
        vector2 &operator*=(int v){
            x *= v;
            y *= v;
            return *this;
        }

//Part 5:

        vector2 operator+(const vector2 &oth) const {return(vector2(x + oth.x, y + oth.y));}
        vector2 operator-(const vector2 &oth) const{return(vector2(x - oth.x, y - oth.y));}
        vector2 operator-() const {return vector2(-x, -y);}
        vector2 operator*(int v) const {return(vector2(x*v, y*v));}

//Part 6:
        
        bool operator==(const vector2 &oth){return(x==oth.x && y==oth.y);}

        bool operator!=(const vector2 &oth){return(x!=oth.x && y!=oth.y);}

//Part 7:
    
    friend vector2 operator*(int v, const vector2 &oth){
        return(vector2(oth.x*v, oth.y*v));
    }

    friend std::ostream& operator<<(std::ostream &os, const vector2 &oth){
        os << "{" << oth[0] << ", " << oth[1] << "}";
        return os;
    }
};
