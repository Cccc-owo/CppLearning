#include <iostream>
#include <string>

#ifndef POST_H
#define POST_H

using namespace std;

class Sender;
class Letter;
class PostOffice;
class Postman;
class Recipient;

class Sender {
public:
    Sender(string sender);
	string getName();
    string sendLetter(Letter letter, PostOffice office, string type); // 寄信
    void pay(PostOffice office, double postage); // 付费
private:
    string name;
};

class Letter {
public:
	Letter(string address, string content, Recipient recipient);
	string getRecipientName();
	string getContent();
	void setSenderName(Sender sender);
private:
    string address; // 地址
    string content; // 内容
    string senderName; // 寄信人
    string recipientName; // 收信人
};

class PostOffice {
public:
	PostOffice(Postman& tom, Postman& jerry);
    double dealService(Letter &letter, string type); // 办理业务
    void charge(double postage); // 收邮费
    Postman & assignPostman(const string& type) const; // 分配邮递员
private:
    Postman &tom;
    Postman &jerry;
};

class Postman {
public:
	explicit Postman(string name);
    void deliverLetter(Letter &letter) const; // 送信
private:
    string name;
};

class Recipient {
public:
	Recipient(string name);
	string getName();
    void receiveLetter(Letter &letter); // 收到信件
private:
    string name;
};

#endif //POST_H
