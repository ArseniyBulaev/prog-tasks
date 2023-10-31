#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>

using std::vector, std::set;
using std::cout, std::endl;

struct Point{
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {}
    static double calculate_distance(const Point &, const Point &);
    friend std::ostream & operator << (std::ostream & out, const Point & point);
};

double Point::calculate_distance(const Point & a, const Point & b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

std::ostream & operator << (std::ostream & out, const Point & point){
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

bool operator < (const Point & point_1, const Point & point_2){
    if (point_1.x != point_2.x){
       return point_1.x < point_2.x;
    }
    else{
        return point_1.y < point_2.y;
    }
}

bool operator > (const Point & point_1, const Point & point_2){
   return point_2 < point_1;
}

bool operator == (const Point & point_1, const Point & point_2){
    return !(point_2 < point_1 || point_1 < point_2);
}


// Эвристика ближайшей точки
vector<Point> nearest_neighbor(set<Point> available_points){
    // Маршрут
    vector<Point> route;
    // Генератор случайных чисел
    std::random_device dev;
    // Алгоритм для генерации
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, available_points.size() - 1);
    // Из множества P выбираем и посещаем произвольную точку p_0
    auto it = std::begin(available_points);
    std::advance(it, dist(rng));
    Point p = *it;
    // Удаляем выбранную точку из доступных (Посещаем её)
    available_points.extract(p);
    route.push_back(p);
    
    // Пока остаются непосещённые точки
    while(!available_points.empty()){
        const Point * nearest = nullptr;
        double distance_to_nearest;
        // Выбираем точку ближаюшую к p
        for (const Point & some_point : available_points){
            // Расстояние до некоторой точки
            double distance = Point::calculate_distance(p, some_point);
            if (nearest){
                if (distance < distance_to_nearest){
                    nearest = &some_point;
                    distance_to_nearest = distance;
                }
            }
            else{
                nearest = &some_point;
                distance_to_nearest = distance;
            }
        } 
        // Посещаем ближайшую точку
        p = *nearest;
        available_points.extract(p);
        route.push_back(p);
    }
    return route;
}



int main(){
    set<Point> points {
        Point(0, 0), Point(1, 0), Point(-1, 0),
        Point(3, 0), Point(-5, 0), Point(11, 0),
        Point(-21, 0)
    };

    vector<Point> route = nearest_neighbor(points);

    for(const Point & p: route){
        cout << p << " ";
    }
    cout << endl;

    return 0;
}