#include <iostream>

using namespace std;

class Product {									// 商品类
public:
	Product();
	Product(string name, double price, double quantity);
	void printInfo();							// 输出该商品的信息：名称、标牌价格、购买数量
	double getPrice();
	double getQuantity();
private:
	string name;
	double price;
	double quantity;
};

class ShoppingCart {							// 购物车类
public:
	ShoppingCart();
	void addProduct(Product product);			// 添加一定数量的商品到购物车
	double checkout();							// 对购物车中的商品进行结算
	void printInvoice();						// 将商品信息输出到显示器
private:
	Product products[20];
	int products_index;
};


int main() {
	Product tShirt("Tshirt", 79, 2);		// 创建服装对象，名称、价格、数量
	Product suit("suit", 1099, 1);		// 套装
	Product hat("hat", 129, 3);			// 帽子
	Product tv("tv set", 4899, 1);		// 创建家电对象，名称、价格、数量
	Product ac("air condition", 5280, 1);	// 空调

	ShoppingCart myCart;
	// 将商品添加到购物车
	myCart.addProduct(tShirt);
	myCart.addProduct(suit);
	myCart.addProduct(hat);
	myCart.addProduct(tv);
	myCart.addProduct(ac);

	double checkoutPrice = myCart.checkout();				// 购物车商品结算，显示顾客需要支付的总金额
	cout << "您需要支付" << checkoutPrice << "元。" << endl;
	myCart.printInvoice();									// 将购物清单输出到显示器上

	return 0;

}

Product::Product() {
	name = "NULL";
	price = 0.0;
	quantity = 0.0;
}

Product::Product(string name, double price, double quantity) : name(name), price(price), quantity(quantity) {
}

void Product::printInfo() {
	cout << name << ", " << price << ", " << quantity << endl;
}

double Product::getPrice() {
	return price;
}

double Product::getQuantity() {
	return quantity;
}

ShoppingCart::ShoppingCart() : products_index(0) {
}

void ShoppingCart::addProduct(Product product) {
	this->products[products_index++] = product;
}

double ShoppingCart::checkout() {
	double checkoutPrice = 0.0;
	for (int i = 0; i < products_index; i++) {
		checkoutPrice += products[i].getPrice() * products[i].getQuantity();
	}
	return checkoutPrice;
}

void ShoppingCart::printInvoice() {
	for (int i = 0; i < products_index; i++) {
		products[i].printInfo();
	}
}
