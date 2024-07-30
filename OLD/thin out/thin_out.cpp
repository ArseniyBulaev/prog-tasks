#include <iostream>
#include <vector>


struct Record{
    int X;
    int Y;

    friend std::ostream& operator<<(std::ostream& os, const Record& record);
};

std::ostream& operator <<(std::ostream& os, const Record& record){
    
    os << "(" << record.X << "," << record.Y << ")";
    return os;
}

std::vector<Record> thin_out(const std::vector<Record> & records, int n){
   
    std::vector<Record> thinned_out;
    int record_number = 0;

    for (int i = 0; i < records.size(); ++i)
    {
        ++record_number;

        // Последний элемент
        if (((i < records.size() - 1) && (records[i + 1].Y != records[i].Y)) || i == records.size() - 1)
        {
            thinned_out.push_back(records[i]);
            record_number = 0;
            continue;
        }

        // Первый и n-ый
        if (record_number == 1 || record_number == n )
        {
            thinned_out.push_back(records[i]);
        }
    }
    
    return thinned_out;
}

void print(const std::vector<Record> & records){
    for (size_t i = 0; i < records.size(); ++i)
    {
        std::cout << records[i];
        if (i < records.size() - 1) std::cout << ",";
    }
    std::cout << std::endl;
}

int main(){

    std::vector<Record> records = {
        Record{1,10},
        Record{2,11},
        Record{3,11},
        Record{4,11},
        Record{5,11},
        Record{6,10},
        Record{7,11},
        Record{8,11},
        Record{9,11},
        Record{10,11},
        Record{11,10},
        };


    std::cout << "original ";
    print(records);
    std::cout << "n=3 ";
    print(thin_out(records, 3));
    std::cout << "n=4 ";
    print(thin_out(records, 4));

    return 0;
}