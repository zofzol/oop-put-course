#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
    string productName;
    static int productCount;
protected:
    float productPrice;
public:
    Product(string name, float price) {
        productName = name;
        productPrice = price;
        productCount++;
    }

    float getPrice() {
        return productPrice;
    }
};

int Product::productCount = 0;

class Customer {
    string customerName;
    string customerEmail;
    static int customerCount;
public:
    Customer(string name, string email) {
        customerName = name;
        customerEmail = email;
        customerCount++;
    }
};

int Customer::customerCount = 0;

class Order {
    Customer* orderCustomer;
    vector<Product*> orderProducts;
    static int orderCount;
    static float totalOrderPrice;
public:
    Order(Customer* customer) {
        orderCustomer = customer;
        orderCount++;
    }

    void addProduct(Product* product) {
        orderProducts.push_back(product);
    }

    void calculateTotalPrice() {
        int productCount = orderProducts.size();
        for (int i = 0; i < productCount; i++) {
            totalOrderPrice += orderProducts[i]->getPrice();
        }

        cout << "Total Order Price: " << totalOrderPrice << endl;
    }
};

int Order::orderCount = 0;
float Order::totalOrderPrice = 0;

int main() {
    Product product1("apple", 2.5);
    Product product2("banana", 1.75);
    Customer customer1("Vito Bambino", "v.bambino@tlen.pl");
    Order order1(&customer1);
    order1.addProduct(&product1);
    order1.addProduct(&product2);
    order1.calculateTotalPrice();
    return 0;
}
