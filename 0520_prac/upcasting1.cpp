/* 
�ǽ� 1
1. �� �ǽ�(snackBasket) �����ͷ� ���� ó���ϱ�(��ĳ����)
2. Candy, Chocolate�� �����ڿ��� ���� �����縦 �Է� �ޱ�
3. Candy, Chocolate ������ �����縦 ����ϴ� �޼ҵ带 �����, 
   ��ĳ���õ� �ν��Ͻ��� �ٽ� �ٿ�ĳ�����Ͽ� �����ϱ�
*/

#include <iostream>

using namespace std;

class Snack {
protected: // Snack, Candy, Chocolate Ŭ���� ���� ����
    string category; // ����
    float price; // ����
    string productName; // ��ǰ�̸�
    string manufacturer; // ������

public:
    Snack(string category, float price, string productName, string manufacturer)
        : category(category), price(price), productName(productName), manufacturer(manufacturer) {}

    virtual ~Snack() {} // ���� �Ҹ���

    string getCategory() { // protected�� ����� category�� ���� �����ϰ� ����
        return category;
    }

    string getProductName() { // protected�� ����� productName�� ���� �����ϰ� ����
        return productName;
    }

    string getManufacturer() { // protected�� ����� manufacturer�� ���� �����ϰ� ����
        return manufacturer;
    }
};

class Candy : public Snack {
private: // Candy Ŭ���������� ���� ����
    string flavor; // ��

public:
    Candy(string flavor, float price, string productName, string manufacturer)
        : Snack("Candy", price, productName, manufacturer), flavor(flavor) {}

    void printManufacturer() { // ������ ��� �޼ҵ�
        cout << " ( " << getManufacturer() << " ) : " << productName << endl;
    }
};

class Chocolate : public Snack {
private: // Chocolate Ŭ���������� ���� ����
    string shape; // ���

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

    // ��ĳ����
    Snack* snackBasket[4] = { &candy_1, &candy_2, &chocolate_1, &chocolate_2 };

    cout << "[ Category : Product Name -- Snack Basket ]\n" << endl;

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << snackBasket[i]->getCategory() << " : " << snackBasket[i]->getProductName()  << endl;
    }

    cout << "\n[ ( Manufacturer ) : Product Name -- Snack Basket ]" << endl;
    //�ٿ�ĳ����
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