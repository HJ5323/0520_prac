/* 
실습 1
1. 앞 실습(snackBasket) 포인터로 만들어서 처리하기(업캐스팅)
2. Candy, Chocolate의 생성자에서 각각 제조사를 입력 받기
3. Candy, Chocolate 각각의 제조사를 출력하는 메소드를 만들고, 
   업캐스팅된 인스턴스를 다시 다운캐스팅하여 실행하기
*/

#include <iostream>

using namespace std;

class Snack {
protected: // Snack, Candy, Chocolate 클래스 접근 가능
    string category; // 종류
    float price; // 가격
    string productName; // 상품이름
    string manufacturer; // 제조사

public:
    Snack(string category, float price, string productName, string manufacturer)
        : category(category), price(price), productName(productName), manufacturer(manufacturer) {}

    virtual ~Snack() {} // 가상 소멸자

    string getCategory() { // protected로 선언된 category에 접근 가능하게 해줌
        return category;
    }

    string getProductName() { // protected로 선언된 productName에 접근 가능하게 해줌
        return productName;
    }

    string getManufacturer() { // protected로 선언된 manufacturer에 접근 가능하게 해줌
        return manufacturer;
    }
};

class Candy : public Snack {
private: // Candy 클래스에서만 접근 가능
    string flavor; // 맛

public:
    Candy(string flavor, float price, string productName, string manufacturer)
        : Snack("Candy", price, productName, manufacturer), flavor(flavor) {}

    void printManufacturer() { // 제조사 출력 메소드
        cout << " ( " << getManufacturer() << " ) : " << productName << endl;
    }
};

class Chocolate : public Snack {
private: // Chocolate 클래스에서만 접근 가능
    string shape; // 모양

public:
    Chocolate(string shape, float price, string productName, string manufacturer)
        : Snack("Chocolate", price, productName, manufacturer), shape(shape) {}

    void printManufacturer() {
        cout << " ( " << getManufacturer() << " ) : " << productName << endl;
    }
};

int main() {
    Candy candy_1("sour", 200, "Bear", "mm");
    Candy candy_2("sweet", 150, "Smile", "ss");
    Chocolate chocolate_1("round", 1000, "Coin", "ww");
    Chocolate chocolate_2("bar", 1500, "Milk Bar", "aa");

    // 업캐스팅
    Snack* snackBasket[4] = { &candy_1, &candy_2, &chocolate_1, &chocolate_2 };

    cout << "[ Category : Product Name -- Snack Basket ]\n" << endl;

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << snackBasket[i]->getCategory() << " : " << snackBasket[i]->getProductName()  << endl;
    }

    cout << "\n[ ( Manufacturer ) : Product Name -- Snack Basket ]" << endl;
    //다운캐스팅
    for (int i = 0; i < 4; i++) {
        if (Candy* candy = dynamic_cast<Candy*>(snackBasket[i])) {
            candy->printManufacturer();
        }
        else if (Chocolate* chocolate = dynamic_cast<Chocolate*>(snackBasket[i])) {
            chocolate->printManufacturer();
        }
    }

    return 0;
}