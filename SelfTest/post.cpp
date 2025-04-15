#include <iostream>
#include <string>
#include "post.h"

using namespace std;

Sender::Sender(string sender) : name(move(sender)) {
}

string Sender::getName() {
	return name;
}

string Sender::sendLetter(Letter letter, PostOffice office, string type) {
	cout << "我要寄信，收信人是 " << letter.getRecipientName() << "，选择投递方式是：" << type << endl;
	return type;
}

void Sender::pay(PostOffice office, double postage) {
	cout << "支付邮费 " << postage << " 元。" << endl;
	office.charge(postage);
}

Letter::Letter(string address, string content, Recipient recipient) : address(move(address)), content(move(content)) {
	recipientName = recipient.getName();
}

string Letter::getRecipientName() {
	return recipientName;
}

string Letter::getContent() {
	return content;
}

void Letter::setSenderName(Sender sender) {
	senderName = sender.getName();
}

Postman::Postman(string name) : name(move(name)) {
}

void Postman::deliverLetter(Letter& letter) const {
	cout << "我是邮递员 " << name << "，马上投递信件，收信人是：" << letter.getRecipientName() << endl;
}

PostOffice::PostOffice(Postman& tom, Postman& jerry) : tom(tom), jerry(jerry) {
}

double PostOffice::dealService(Letter& letter, string type) {
	double postage = 0.0;

	if (type == "surface mail") {
		postage = 1.0;
	} else {	// EMS
		postage = 15.0;
	}

	cout << "收到信件，收信人是 " << letter.getRecipientName() << "，邮费是 " << postage << " 元。" << endl;
	return postage;
}

void PostOffice::charge(double postage) {
	cout << "收到邮费 " << postage << " 元。" << endl;
}

Postman& PostOffice::assignPostman(const string& type) const {
	if (type == "surface mail") {
		return tom;
	} else {	// EMS
		return jerry;
	}
}

Recipient::Recipient(string name) : name(move(name)) {
}

string Recipient::getName() {
	return name;
}

void Recipient::receiveLetter(Letter& letter) {
	cout << "收到信件，信件的内容是：" << letter.getContent() << endl;
}
